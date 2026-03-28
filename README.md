# run.c-sh
chdir lib cc -c -O *.c ar r /lib/liby.a *.o rm *.o chdir ../source cc -s -O y?.c cmp a.out /usr/bin/yacc cp a.out /usr/bin/yacc rm a.out *.o


```
chdir lib

cc -c -O *.c

ar r /lib/liby.a *.o

rm *.o

chdir ../source

cc -s -O y?.c

cmp a.out /usr/bin/yacc

cp a.out /usr/bin/yacc

rm a.out *.o
```



Open a terminal in that directory and run:
```
cc -o build_script main.c
```

This creates an executable called:
```
./build_script
```


▶️ 3. Run it
```
./build_script
```


📂 4. Required directory structure

Your program assumes this layout:


```
project/
│
├── main.c
├── ruin.h
├── lib/
│   ├── file1.c
│   ├── file2.c
│   └── ...
└── source/
    ├── y1.c
    ├── y2.c
    └── ...
```



If lib/ or source/ don’t exist, chdir() will fail.




⚠️ 5. Important gotchas

🔴 Permissions


This line:
```
system("cp a.out /usr/bin/yacc");
```


should fail unless you run as _root_:

```
sudo ./build_script

```


🔴 Wildcards (*.c, *.o)


These only work because system() runs through a shell (/bin/sh), which expands them.

If you later switch to execve(), they will NOT work automatically.

🔴 Hardcoded paths

```
"/lib/liby.a"

"/usr/bin/yacc"
```


These are system directories. On modern systems:



__/lib__ may be protected


__/usr/bin___ requires root

Safer alternative:

```
"ar r ./liby.a *.o"

"cp a.out ./yacc"
```


🧠 What “using it” really means

You built a mini build script engine:

Instead of:
```
cc -c -O *.c
```


you now do:
```
run_commands(lib_steps);
```


To conclude:

```
Data (Command[]) = script

Code (run_commands) = executor
```
