#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h> // 동적 라이브러리를 위한 헤더

int main() {
    void *handle;
    int (*add_func)(int, int);
    int (*sub_func)(int, int);
    char *error;

    // 1. 공유 라이브러리 파일 열기
    handle = dlopen("./libcalc.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(1);
    }

    // 2. 라이브러리 안에서 함수 이름으로 찾아서 연결하기
    add_func = dlsym(handle, "add");
    if ((error = dlerror()) != NULL)  {
        fprintf(stderr, "%s\n", error);
        exit(1);
    }

    sub_func = dlsym(handle, "sub");
    if ((error = dlerror()) != NULL)  {
        fprintf(stderr, "%s\n", error);
        exit(1);
    }

    // 3. 찾은 함수 사용하기
    printf("Dynamic Add: %d\n", add_func(10, 5));
    printf("Dynamic Sub: %d\n", sub_func(10, 5));

    // 4. 라이브러리 닫기
    dlclose(handle);
    return 0;
}
