# 42-Pipex
Pipex reproduces the behaviour of the shell pipe | command in C. (An UNIX mechanism.)<br>
<br>
[Mandaroty part](https://github.com/ava8kyoko/42-Pipex/blob/master/subject/mandatory_part.md)

People who inspired me :
[KingMeeko](https://github.com/dantremb/pipex) | [gabcollet](https://github.com/gabcollet/pipex) | [Tuto pipex](https://csnotes.medium.com/pipex-tutorial-42-project-4469f5dd5901)


```
dprintf(2, "%s\n", path);

bin
ls

perror(path);
perror(path);
dprintf(2, "erroooooooooooor = %s\n", cmd[0]);
dprintf(2, "erroooooooooooor = %s\n", cmd[1]);

./pipex in ls cat out && cat out 
./pipex in ls "cat -e" out && cat out



rm -rf Caches
du -sh Caches

expliquer pq <in ls "marche pas" ls lit 1 pas 0

nm prog
```