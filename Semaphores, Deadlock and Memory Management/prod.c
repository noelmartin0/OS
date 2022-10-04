#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<stdlib.h>
#define MAXITEMS 5
#define BUFFSIZE 5
int buff[BUFFSIZE];
int in = 0;
int out = 0;
sem_t empty;
sem_t full;
pthread_mutex_t mutex;
void producer(int *pro)
{
    int item;
    for(int i = 0; i< MAXITEMS; i++)
    item = rand();
    sem_wait(&empty);
    pthread_mutex_lock(&mutex);
    buff[in] = item;
    printf("\nProducer %d produces  %d",*((int *)pro),in);
    sleep(1);
    in = (in%BUFFSIZE)+1;
    pthread_mutex_unlock(&mutex);
    sem_post(&full);
}
void consumer(int *con)
{
    int item;
    for(int i = 0; i<MAXITEMS; i++)
    {
        item = buff[out];
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        printf("\nConsumer %d consumes  %d",*((int *)con),out);
        sleep(1);
        out = (out%BUFFSIZE)+1;
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
}
void main()
{
    int i;
    pthread_t pro[5], con[5];
    pthread_mutex_init(&mutex,NULL);
    int a[] = {1,2,3,4,5};
    sem_init(&empty,0,BUFFSIZE);
    sem_init(&full,0,0);
    for(i = 0; i< MAXITEMS; i++)
     pthread_create(&pro,NULL,(void *)producer,(void *)&a[i]);
    for(i = 0; i< MAXITEMS; i++)
     pthread_create(&con,NULL,(void *)consumer,(void *)&a[i]);
    for(i = 0; i< MAXITEMS; i++)
     pthread_join(pro[i],NULL);
    for(i = 0; i< MAXITEMS; i++)
     pthread_join(con[i],NULL);
    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
}