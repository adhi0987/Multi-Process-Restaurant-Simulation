
#ifndef SHAREDMEMORY_H
#define SHAREDMEMORY_H    
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include<string.h>

// Shared memory and semaphore keys
#define SHM_KEY_PATH "."
#define SEM_KEY_PATH "."
#define SHM_KEY_PROJ_ID 1234
#define SEM_KEY_PROJ_ID 5678

// Shared memory structure
typedef struct {
    int time;                           // Simulated time (minutes since 11:00 am)
    int empty_tables;                   // Number of empty tables
    int next_waiter;                    // Next waiter to serve a customer
    int pending_orders;                 // Number of pending orders for cooks
    int food_ready[5];                  // Customer ID for which food is ready 
    int no_of_cooks;                    // No of cooks to identify last leaving cooks
    int cook_queue[600];                // Cooking queue (200 orders max, 3 ints per order)
    int cook_queue_front;               // Front index of the cooking queue
    int cook_queue_back;                // Back index of the cooking queue
    int waiter_queues[5][200];          // Queues for each waiter (customer ID and count)
    int waiter_queue_front[5];          // Front index of each waiter's queue
    int waiter_queue_back[5];           // Back index of each waiter's queue
    int pending_waiter_orders[5];       // Pending Orders in Each Waiter Queue
} SharedData;

void sem_wait(int semid, int sem_num);
void sem_signal(int semid, int sem_num);
void printTime(int arrival_time);
void makeString(int waiter_id);

#endif