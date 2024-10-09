#include "threading.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// Optional: use these functions to add debug or error prints to your application
#define DEBUG_LOG(msg,...)
//#define DEBUG_LOG(msg,...) printf("threading: " msg "\n" , ##__VA_ARGS__)
#define ERROR_LOG(msg,...) printf("threading ERROR: " msg "\n" , ##__VA_ARGS__)

void* threadfunc(void* thread_param)
{

    // TODO: wait, obtain mutex, wait, release mutex as described by thread_data structure
    // hint: use a cast like the one below to obtain thread arguments from your parameter
    //struct thread_data* thread_func_args = (struct thread_data *) thread_param;
    
    int retval;
    
    struct thread_data* thread_func_args = (struct thread_data *) thread_param;
    int microsecs_obt = (thread_func_args-> wait_to_obtain_ms)*1000;
    int microsecs_rel = (thread_func_args-> wait_to_release_ms)*1000;
    
    usleep (microsecs_obt);
    
    retval = pthread_mutex_lock(thread_func_args->mutex);
    printf("H A L U K mutex lock returns %d\n",retval);
    usleep (microsecs_rel);
    
    pthread_mutex_unlock(thread_func_args->mutex);
	printf("H A L U K mutex unlock returns %d\n",retval);
	thread_func_args->thread_complete_success = true;
    
    return thread_param;
}


bool start_thread_obtaining_mutex(pthread_t *thread, pthread_mutex_t *mutex,int wait_to_obtain_ms, int wait_to_release_ms)
{
    /**
     * TODO: allocate memory for thread_data, setup mutex and wait arguments, pass thread_data to created thread
     * using threadfunc() as entry point.
     *
     * return true if successful.
     *
     * See implementation details in threading.h file comment block
     */
     
     int retval; // for errors warnings etc
     
     
     struct thread_data *td = (struct thread_data *)malloc(sizeof(struct thread_data));
    
	  // first check if the mutex is there, create only if NULL
     if(mutex== NULL){
		retval =pthread_mutex_init(mutex,NULL);
     	printf("H A L U K mutex create returns %d\n",retval);
     }
     
     // assign parameters into the struct
     td->mutex = mutex;
     
     td->wait_to_obtain_ms = wait_to_obtain_ms;
     
     td->wait_to_release_ms = wait_to_release_ms;
     
     // create and start a thread
     retval = pthread_create(thread,NULL,threadfunc, td);
     
     if(!retval) return true;// if 0 It's OK

	ERROR_LOG("pthread_create error");
    return false;
}

