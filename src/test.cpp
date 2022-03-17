#include <sqlite3.h>
#include <cstdio>
#define Cirg

int main() {
    sqlite3* DB;

    int exit = 0;
    exit = sqlite3_open("example.db", &DB);
    printf("%d\n", exit);
}