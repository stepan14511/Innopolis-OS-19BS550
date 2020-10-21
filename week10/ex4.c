#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

int main(){
    DIR *dirp = opendir("tmp"); // Open directory
    if(dirp == NULL){
        printf("Unable to open directory 'tmp'.");
        return 1;
    }


    struct dirent *entry;
    int eCount = 0; // Count number of entries in arrays
    char file_names[256][256];
    int i_nodes[256];
    while((entry = readdir(dirp)) != NULL){ // Get entry
        struct stat eStat;
        char path[256]; // Get path, relative to our program
        strcpy(path, "tmp/");
        strcat(path, entry->d_name);
        stat(path, &eStat); // Get stat of entry
        strcpy(file_names[eCount], entry->d_name);
        i_nodes[eCount] = eStat.st_ino;
        eCount++;
    }

    // Now we are listing file names, related to each ino.
    int ino_num[256]; // Save ino itselves
    int ino_count[256]; // Save amount of files with such ino.
    char ino_names[256][256]; // Save their names.
    int ino_n = 0;
    for(int i = 0; i < eCount; i++){
        char found_in_array = 0; // Check if inode is already in array
        for(int j = 0; j < ino_n; j++){
            if(ino_num[j] == i_nodes[i]){
                found_in_array = 1;
                strcat(ino_names[j], " ");
                strcat(ino_names[j], file_names[i]);
                ino_count[j]++;
            }
        }
        if(found_in_array == 0){ // If not in array yet, add it.
            ino_num[ino_n] = i_nodes[i];
            ino_count[ino_n] = 1;
            strcpy(ino_names[ino_n], file_names[i]);
            ino_n++;
        }
    }

    // And printing where ino_count > 1
    for(int i = 0; i < ino_n; i++){
        if(ino_count[i] > 1){
            printf("%d: ", ino_num[i]);
            printf(ino_names[i]);
            printf("\n");
        }
    }
    return 0;
}