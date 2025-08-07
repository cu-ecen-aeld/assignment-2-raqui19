// Like writer.sh



/* INSTRUCTIONS :

1. One difference from the write.sh instructions in Assignment 1:  You do not need to make your "writer" utility create directories which do not exist.  You can assume the directory is created by the caller.

2. Setup syslog logging for your utility using the LOG_USER facility.

3. Use the syslog capability to write a message “Writing <string> to <file>” where <string> is the text string written to file (second argument) and <file> is the file created by the script.  This should be written with LOG_DEBUG level.

4. Use the syslog capability to log any unexpected errors with LOG_ERR level.
*/





#include <stdio.h>
#include <syslog.h>
#include <string.h>

#define WRITER_NO_PARAMETERS (2)
#define MAX_PATH_LENGTH (100)
#define MAX_STR_LENGTH (1000)



int main(int argc, char* argv[]) {
    char file_path[MAX_PATH_LENGTH] = {0};
    char file_str[MAX_STR_LENGTH] = {0}; 
    char file_name[MAX_PATH_LENGTH] = {0};
    char write_str[1200] = {0};

    // Open a connection to syslog
    openlog("writer_logs", LOG_PID | LOG_CONS, LOG_USER);

    printf("WELCOME TO FINDER\n");
    printf("Args received: %d\n", argc);

    if(argc < WRITER_NO_PARAMETERS+1) {
        syslog(LOG_ERR, "Error : missing parameter");
        closelog();
        return 1;
    }


    // Read path from cmd line - path of the file
    memcpy(&file_path[0], argv[1], strlen(argv[1]));
    printf("%s-\n", file_path);

    // Read string from cmd line - string to write to the file
    memcpy(&file_str[0], argv[2], strlen(argv[2]));
    printf("%s-\n", file_str);

    // Extract file name
    char* fname = strrchr(file_path, '/') + 1;

    memcpy(&file_name[0], fname, strlen(fname));


    // Log the operation
    sprintf(&write_str[0], "Writing %s to %s", file_str, file_name);
    syslog(LOG_DEBUG, (const char*)&write_str[0]);
    
    
    // Check if the file exists, otherwise just return
    FILE* file = fopen(file_path, "r");
    if(file == NULL){
    	syslog(LOG_ERR, "Error : file read");
    	return 1;
    }
    fclose(file);
    

    
    // Open file and write to it
    file = fopen(file_path, "w");
    if(file == NULL){
    	syslog(LOG_ERR, "Error : file write");
    	return 1;
    }
    fprintf(file, "%s\n", &file_str[0]);
    fclose(file);

    printf("Success\n");
    syslog(LOG_INFO, "Success writer");

cleanup:
    closelog();
}
