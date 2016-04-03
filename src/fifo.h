/**
 * @file fifo.h
 * @brief Header file of fifo part.
 * @author Liqiduan
 * @version 1.0.0
 * @date 2016-04-01
 */

#ifndef _UNIDS_FIFO_H_
#define _UNIDS_FIFO_H_

#ifndef NULL
#define NULL 0
#endif // NULL

#define MAX_FIFO_SIZE 64

typedef unsigned int fifo_len_t;
typedef unsigned char fifo_data_t;

/**
 * @brief Here is the struct definiton of fifo
 *
 */
typedef struct
{
	fifo_data_t* readP;	///Point to the memory will be read
	fifo_data_t* writeP;	///Point to the memory will be write
	fifo_data_t* beginP;	///Point to the begin of a memory used as fifo.
	fifo_data_t* endP;	///Point to the end of a memory used as fifo.
}fifo;

/**
 * @brief Initial memory for fifo to use.
 */
int fifo_init(fifo *p, fifo_len_t len, fifo_data_t *dataP);

/**
 * @brief Return how many memory has been used!
 */
fifo_len_t fifo_used(fifo *p);

/**
 * @brief Clear a fifo.
 */
void fifo_clear(fifo *p);

/**
 * @brief Get data from fifo.
 */
int fifo_gets(fifo *p, fifo_len_t len, fifo_data_t *bufP);

/**
 * @brief Put data into a fifo.
 */
int fifo_puts(fifo *p, fifo_len_t len, fifo_data_t *bufP);

#endif

