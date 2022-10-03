#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#define N 5
#define LEFT (i+N-1)%N
#define RIGHT (i)%N
#define THINKING 0
#define HUNGRY 1
#define EATING 2
int state[N];
pthread_t t[N];
sem_t mutex;
sem_t s[N];
void think(int n)
{
    printf("\nThe Philosopher %d is thinking...",n);
    sleep(1);
}
void eat(int n)
{
    printf("\nThe Philosopher %d is eating...",n);
    sleep(1);
    printf("\nThe Philosopher %d has finished eating...");
}
void take_fork(int i)
{
  sem_wait(&mutex);
  state[i] = HUNGRY;
  if(state[i]==HUNGRY&&state[LEFT]!=EATING&&state[RIGHT]!=EATING)
  {
    state[i] = EATING;
    sem_wait(&s[LEFT]);
    sem_wait(&s[RIGHT]);
  }
  sem_post(&mutex);
}
void put_fork(int i)
{
    state[i] = THINKING;
    sem_post(&s[LEFT]);
    sem_post(&s[RIGHT]);
}
void *philo(int n)
{
    while(1)
    {
        think(n);
        take_fork(n);
        if(state[n]==EATING)
        {
            eat(n);
            put_fork(n);
        }
    }
}
void main()
{
    int i;
    for(i = 0; i<N; i++)
    {
        sem_init(&s[i],0,1);
    }
    sem_init(&mutex,0,1);
    for(i = 0; i<N; i++)
    {
        pthread_create(&t[i],0,(void *)philo,(void *)i);
    }
  while(1);
}