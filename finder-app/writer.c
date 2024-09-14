// Author Haluk Madencioglu
// For ECEA5305 Assignment2


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <syslog.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>


int main(int argc, char *argv[]){
    char *fullname, *my_string, *str_error;
    int fd, numwr;
    
    // open syslog
    openlog(NULL, 0, LOG_USER);
    
    // the program itself counts as argv[0]
    if(argc<3 || argc >3){
        
        fprintf(stderr, "Invalid number of arguments. Arguments needed:1-filename including directory 2-string to write into that file\n");
        
        syslog(LOG_ERR,"Invalid number of arguments: %d",argc-1); 
        return 1; 
    }
    
    //get the full path-file and the string
    fullname = argv[1];
    my_string = argv[2];
    
     
    
    //open the file for writing create if necessary, clear contents
    fd = open(fullname, O_WRONLY|O_TRUNC|O_CREAT, S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH);
    if (fd == -1){
        str_error=strerror(errno);// get the explanation from errno
        syslog(LOG_ERR, "%s",str_error);    // report it to syslog
        return 1;
    }
    
    
    // report it to syslog
    syslog(LOG_DEBUG, "Writing %s to %s",my_string, fullname);
    
    numwr=write(fd,my_string,strlen(my_string));
    
    if(numwr == -1){
        str_error=strerror(errno);
        syslog(LOG_ERR, "%s",str_error);
        return 1;
    }else if(numwr != strlen(my_string)){
        // this time no errno set so just a partial write
        syslog(LOG_ERR, "%s","The write operation did not complete; it's a partial write");
        return 1;
    }
    
    //else, everything went smooth
    
    return 0;
}

