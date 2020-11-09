#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <direct.h>
#include <locale.h>
#include <time.h>
#include <string.h>

void bubble_sort(struct _finddata_t *c_file, int filecount) {
    for (int i = 1; i < filecount; i++) {
        for (int j = 0; j < filecount - i; j++) {
            if (c_file[j].size > c_file[j + 1].size) {
                char name[256];
                strcpy_s(name, 256, c_file[j].name);
                double a = c_file[j].size;
                c_file[j].size = c_file[j + 1].size;
                c_file[j + 1].size = a;
                strcpy_s(c_file[j].name, 256, c_file[j + 1].name);
                strcpy_s(c_file[j + 1].name, 256, name);
            }
        }
    }
}

void merge_sort(struct _finddata_t *c_file, int left, int right) {
    if (left == right) return;
    int mid = (left + right) / 2;
    merge_sort(c_file, left, mid);
    merge_sort(c_file, mid + 1, right);
    char name[200][256];
    int i = left;
    int j = mid + 1;
    int* tmp = (int*)malloc(right * sizeof(int));
    for (int k = 0; k < right - left + 1; k++) {
        if ((j > right) || ((i <= mid) && (c_file[i].size < c_file[j].size))) {
            tmp[k] = c_file[i].size;
            strcpy_s(name[k], 256, c_file[i].name);
            i++;
        }
        else {
            tmp[k] = c_file[j].size;
            strcpy_s(name[k], 256, c_file[j].name);
            j++;
        }
    }
    for (int k = 0; k < right - left + 1; k++) {
        c_file[left + k].size = tmp[k];
        strcpy_s(c_file[left + k].name, 256, name[k]);
    }
}

void insert_sort(struct _finddata_t *c_file, int filecount) {
    int tmp, j;
    char name[256];
    for (int i = 1; i < filecount; i++) {
        strcpy_s(name, 256, c_file[i].name);
        tmp = c_file[i].size;
        j = i - 1;
        while (j >= 0 && c_file[j].size > tmp) {
            c_file[j + 1].size = c_file[j].size;
            strcpy_s(c_file[j + 1].name, 256, c_file[j].name);
            j--;
        }
        c_file[j + 1].size = tmp;
        strcpy_s(c_file[j + 1].name, 256, name);
    }
}

void selection_sort(struct _finddata_t *c_file, int filecount) {
    int min, tmp;
    char name[256];
    for (int i = 0; i < filecount - 1; i++) {
        min = i;
        for (int j = i + 1; j < filecount; j++) {
            if (c_file[j].size < c_file[min].size)
                min = j;
        }
        tmp = c_file[i].size;
        c_file[i].size = c_file[min].size;
        c_file[min].size = tmp;
        strcpy_s(name, 256, c_file[i].name);
        strcpy_s(c_file[i].name, 256, c_file[min].name);
        strcpy_s(c_file[min].name, 256, name);
    }
}

void quick_sort(struct _finddata_t *c_file, int left, int right) {
    int l = left;
    int r = right;
    char name[256];
    strcpy_s(name, 256, c_file[left].name);
    int divider = c_file[left].size;
    while (left < right) {
        while ((c_file[right].size >= divider) && (left < right))
            right--;
        if (left != right) {
            c_file[left].size = c_file[right].size;
            strcpy_s(c_file[left].name, 256, c_file[right].name);
            left++;
        }
        while ((c_file[left].size <= divider) && (left < right))
            left++;
        if (left != right) {
            c_file[right].size = c_file[left].size;
            strcpy_s(c_file[right].name, 256, c_file[left].name);
            right--;
        }
    }
    c_file[left].size = divider;
    strcpy_s(c_file[left].name, 256, name);
    divider = left;
    left = l;
    right = r;
    if (left < divider)
        quick_sort(c_file, left, divider - 1);
    if (right > divider)
        quick_sort(c_file, divider + 1, right);
}

void main() {
    char path[256];
    int sw = -1, sw2 = 0;

    setlocale(LC_ALL,"");

    printf("Enter the path to the directory\n");
    scanf("%s", &path);

    while (sw2 != 2) {
        struct _finddata_t c_file[200];
        intptr_t hFile;
        clock_t fTimeStart, fTimeStop;
        int filecount = 0;

        if (_chdir(path) == -1) {
            printf("Wrong path\n");
            return 0;
        }

        if ((hFile = _findfirst("*.*", &c_file[filecount])) == -1)
            printf("No files in current directory.\n");
        else {
            printf("\nListing of files\n");
            printf(" FILE                                    SIZE\n", ' ');
            do {
                printf(" %-33s  %9ld\n", c_file[filecount].name, c_file[filecount].size);
                filecount++;
            } while (_findnext(hFile, &c_file[filecount]) == 0);
            _findclose(hFile);

            printf("\nChoose the sorting method:\n");
            printf("1-Bubble sort\n");
            printf("2-Merge sort\n");
            printf("3-Insert sort\n");
            printf("4-Selection sort\n");
            printf("5-Quick sort\n");
            scanf("%d", &sw);

            fTimeStart = clock() * 1000 / (double)CLOCKS_PER_SEC;
            switch (sw) {
            case 1:
                bubble_sort(c_file, filecount);
                break;
            case 2:
                merge_sort(c_file, 0, filecount - 1);
                break;
            case 3:
                insert_sort(c_file, filecount);
                break;
            case 4:
                selection_sort(c_file, filecount);
                break;
            case 5:
                quick_sort(c_file, 0, filecount-1);
                break;
            }
            fTimeStop = clock() * 1000 / (double)CLOCKS_PER_SEC;
            printf("\nSorting time is %i(ms)\n", fTimeStop - fTimeStart);

            printf("\nChoose the option:\n1-Sort ascending\n2-Sort descending\n");
            scanf("%d", &sw);
            switch (sw) {
            case 1:
                printf("\nListing of files\n");
                printf(" FILE                                    SIZE\n", ' ');
                for (int x = 0; x < filecount; x++) {
                    printf(" %-33s  %9ld\n", c_file[x].name, c_file[x].size);
                }
                break;
            case 2:
                printf("\nListing of files\n");
                printf(" FILE                                    SIZE\n", ' ');
                for (int x = filecount - 1; x >= 0; x--) {
                    printf(" %-33s  %9ld\n", c_file[x].name, c_file[x].size);
                }
                break;
            }
            
            printf("\nChoose the option:\n1-Continue\n2-Quit\n");
            scanf("%d", &sw2);
        }
    }
    system("pause");
}