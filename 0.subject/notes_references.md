Note: It helps me to read a resume in french before english just to be sure to understand well.

### Communication par tuyau [:link:](http://www.zeitoun.net/articles/communication-par-tuyau/start)
Les pipes `|` permettent de faire communiquer les processus entre eux, i.e. rediriger la sortie d'une commande vers l'entrée d'une autre. ex: `ls | wc` EXPLIQUER LE PROCESSUS DANS MES MOTS <br>
<br>
<dl>
	<dt>Caracteristiques d'un pipe</dt>
		<dd>- Possède deux extrémités.</dd>
		<dd>- Les informations passent dans un sens unique, donc on peut écrire les informations à l'entrée et les lire à la sortie.</dd>
		<dd>- Les deux extrémités sont référencés par des descripteurs de fichiers (des entiers stoqués dans la variable fd).</dd>
</dl>

```
                   processus
	    _________________________________
entrée |                                 | sortie
 fd[1]    > -------   pipe   -------- >    fd[0]
	   |_________________________________|

```

### Code : Création d'un pipe dans un processus unique <br>
```c
  #include <stdio.h>
  #include <memory.h>
  #include <unistd.h>
 
  int main( int argc, char ** argv )
  {
   char buffer[BUFSIZ+1];
 
   /* Créer le pipe */
   int fd[2];
   pipe(fd);
 
   /* Écrire dans le pipe */
   write(fd[1], "Hello World\n", strlen("Hello World\n"));
 
   /* Lire le pipe et imprimer la valeur lue. */
   read(fd[0], buffer, BUFSIZ);
   printf("%s", buffer);
  }

  La fonction "pipe(fd)" va réserver deux descripteurs de fichiers dans le tableau fd, 
  "fd[0]" pour l'extrémité à lire et "fd[1]" pour l'extrémité à écrire. 
```

### Création d'un pipe dans un processus ayant un fils

Dans le processus suivant, en plus de créer un pipe, on crée un enfant qui partagera le pipe avec son parent i.e. permettant l'échange d'information entre parent et enfant. Un problème se pose, car l'un écrit dans la pipe, il n'est pas possible de déterminer lequel des deux recevra les données...

```
                   processus
				    parent
	    _________________________________
entrée |                                 | sortie
 fd[1]   >---        pipe        --->      fd[0]
	   |_______                  ________|
	           |  redirection   |
               |    ?  ?  ?     |
			   |  inattendue    |
	    _______                  ________
entrée |                                 | sortie
 fd[1]    >---        pipe        --->     fd[0]
	   |_________________________________|

	               processus
				    enfant
```

... sauf si l'on ferme les processus inutisés. :tada:

```
                   processus
				    parent
	    _________________________________
entrée |                                 | sortie
 fd[1]   >---------          pipe        | fermée
	   |_______      ↓            ________|
	           |      ↓         |
               |       ↓        |
		 	   |        ↓       |
	    _______          ↓       ________
entrée |                  ↓              | sortie
fermé  |      pipe          ----------->   fd[0]
	   |_________________________________|

	               processus
				    enfant
```

Ainsi, si le processus parent écrit à l'entrée fd[1], l'enfant recevra assurément l'information en lecture à la sortie fd[0].

```c
  #include <stdio.h>
  #include <memory.h>
  #include <unistd.h>
 
  int main( int argc, char ** argv )
  {
   /* créer le pipe parent */
   int  pfd[2];
   if (pipe(pfd) == -1)
     {
       printf("pipe failed\n");
       return 1;
     }
 
   /* créer l'enfant */
   int  pid;
   if ((pid = fork()) < 0)
     {
       printf("fork failed\n");
       return 2;
     }
 
   if (pid == 0)
     {
       /* enfant */
       char buffer[BUFSIZ];
 
       close(pfd[1]); /* fermer le processsus écriture */
 
       /* lire les données et imprimer le résultat sur l'écran */
       while (read(pfd[0], buffer, BUFSIZ) != 0)
         printf("child reads %s", buffer);
 
       close(pfd[0]); /* fermer le pipe */
     }
   else
     {
       /* parent */
       char buffer[BUFSIZ];
 
       close(pfd[0]); /* fermer le processus de lecture */
 
       /* envoyer les données dans le pipe */
       strcpy(buffer, "HelloWorld\n");
       write(pfd[1], buffer, strlen(buffer)+1);
 
       close(pfd[1]); /* fermer le pipe */
     }
 
   return 0;
  }
```

Cet échange unidirectionnel peut se faire inversement si l'on crée un deuxième pipe et l'initialise dans l'autre sens.

## 
Chaque processus créé possède trois pipes nommés stdin (fd[0]), stdout (fd[1]) et stderr (fd[2])

```
             keyboard
                ↓
	            ↓ #0 stdin
			    ↓
			  Process
			↓        ↓
#1 stdout	↓   or   ↓   #2 stderr
			↓        ↓
				↓
				↓
				↓
			 Display

			

```
### [:link:](https://www.rozmichelle.com/pipes-forks-dups/)
Utility of File Descriptor, 


## References

- [Command line arguments](https://www.geeksforgeeks.org/command-line-arguments-in-c-cpp/)
- [Introduction to command shell](https://datacarpentry.org/shell-genomics/01-introduction/)
- [](https://en.wikipedia.org/wiki/Standard_streams#/media/File:Stdstreams-notitle.svg)

### Not used

- [Implementation of pipe in linux](https://www.slideshare.net/tusharkute/implementation-of-pipe-in-linux?next_slideshow=1)
- [Pipes, Forks, & Dups: Understanding Command Execution and Input/Output Data Flow](https://www.rozmichelle.com/pipes-forks-dups/)
- [Piping in Unix or Linux](https://www.geeksforgeeks.org/piping-in-unix-or-linux/)
- [Pipes and File I/O](https://slideplayer.com/slide/11637035/)
- [Programmation systeme: execve() fork() et pipe()](https://n-pn.fr/t/2318-c--programmation-systeme-execve-fork-et-pipe)
- [Redirection](https://datacarpentry.org/shell-genomics/04-redirection/index.html)
- Forum [fork after malloc in parent... does the child process need to free it?](https://stackoverflow.com/questions/23440132/fork-after-malloc-in-parent-does-the-child-process-need-to-free-it#:~:text=You%20do%20not%20need%20to,bright%20idea%20to%20do%20so.&text=You%20seem%20to%20be%20basically,not%20worry%20about%20freeing%20stuff)
- Forum [Redirection exec output to a buffer or file](https://stackoverflow.com/questions/2605130/redirecting-exec-output-to-a-buffer-or-file)
- Forum [Unix pipe into ls](https://stackoverflow.com/questions/18210956/unix-pipe-into-ls)
- Forum [Write on pire in c](https://stackoverflow.com/questions/47503798/write-on-pipe-in-c)
- Code [redir_handler](https://github.com/Kampouse/mini-shell-racoon/blob/jp_v2/executing/redir_handler.c)
- Code [redir](http://gunpowder.cs.loyola.edu/~jglenn/702/S2005/Examples/dup2.html)
- Tutorial [pipex 42](https://csnotes.medium.com/pipex-tutorial-42-project-4469f5dd5901)
- Videos [Unix process in C](https://www.youtube.com/playlist?list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY)
- Video [Tubes anonymes et nommes](https://www.youtube.com/watch?v=k8bGYB2gl-A&t=824s)
- [Tester](https://github.com/vfurmane/pipex-tester)


#### mettre dans notes get_next_line
<dl>
	<dt>buffer [:link:](https://www.larousse.fr/dictionnaires/francais/buffer/11615)</dt>
		<dd> En informatique, mémoire intégrée dans des périphériques (disque dur, imprimante, lecteur de cédérom, scanner…) qui permet un stockage temporaire de données afin de faciliter les échanges d'informations et d'optimiser les flux de données.</dd>
		<dd>Synonyme : mémoire tampon</dd>
		<dd>(anglais buffer, tampon)</dd>
</dl>
