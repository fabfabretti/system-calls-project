/// @file semaphore.c
/// @brief Contiene l'implementazione delle funzioni
///         specifiche per la gestione dei SEMAFORI.

#include "defines.h"

// Sostituisce la system call semop rendendola più agibile eliminando la necessità dei flag
void semOp(int semid, unsigned short sem_num, short sem_op) {
  struct sembuf sop = {
    .sem_num = sem_num,
    .sem_op = sem_op,
    .sem_flg = 0
  };

  if (semop(semid, & sop, 1) == -1)
    errExit("semop failed");
}