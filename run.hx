#ifndef HEADER_H
#define HEADER_H

#include <stdlib.h>
#include <unistd.h>

int main() {
    chdir("lib");
    system("cc -c -O *.c");
    system("ar r /lib/liby.a *.o");
    system("rm *.o");

    chdir("../source");
    system("cc -s -O y?.c");
    system("cmp a.out /usr/bin/yacc");
    system("cp a.out /usr/bin/yacc");
    system("rm a.out *.o");

    return 0;
}
#endif


chdir lib
cc -c -O *.c
ar r /lib/liby.a *.o
rm *.o
chdir ../source
cc -s -O y?.c
cmp a.out /usr/bin/yacc
cp a.out /usr/bin/yacc
rm a.out *.o
