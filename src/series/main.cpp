#include <cstdio>

int main() {
    int n = 100,
        sum{0};
    
    for(int i=1; i<n; i++) {
        sum += ( (2*i)/(3*i+2) );
        printf("%d\n", sum);    
    }

}