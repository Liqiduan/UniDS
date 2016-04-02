/**
 * @file fifo.c
 * @brief Implementation of fifo.
 * @author Liqiduan
 * @version 1.0.0
 * @date 2016-04-01
 */

#include "fifo.h"

/**
 * @brief Initial memory for fifo to use.
 *
 * @param p 	 Point to the fifo will be initialled.
 * @param len	 Indicate how many memory will be used.
 * @param dataP  Point to the memory will be used.
 *
 * Initial memory from dataP to dataP + len*sizeof(fifo_data_t)
 *
 *
 * @return 0 - Success
 * 	   -1 - failed
 */

int fifo_init(fifo *p, fifo_len_t len, fifo_data_t *dataP)
{
	if(len<=MAX_FIFO_SIZE)
	{
		p->readP=dataP;
		p->writeP=dataP;
		p->beginP=dataP;
		p->endP=p->beginP + len;
	}
    else
    {
        p->readP=NULL;
        p->writeP=NULL;
		p->beginP=NULL;
		p->endP=NULL;
    }
}


/**
 * @brief fifo_used Return the size has been used
 *
 * @param p Point to the fifo
 *
 * @return Size has been used
 */
fifo_len_t fifo_used(fifo *p)
{
    if(p->beginP==NULL)
    {
        return MAX_FIFO_SIZE;
    }

	if( p->readP >= p->writeP )
	{
		return (p->readP - p->writeP);
	}
	else
	{
		return  (p->endP - p->beginP) - (p->writeP - p->readP);
	}
}


/**
 * @brief fifo_clear Clear a fifo
 *
 * @param p Point to the fifo
 */
void fifo_clear(fifo *p)
{
	p->readP=p->beginP;
	p->writeP=p->endP;
}


/**
 * @brief fifo_gets Get data from fifo
 *
 * @param p 	Point to the fifo which will be read
 * @param len	Indicate how many data will be read
 * @param bufP	The data read from fifo will store in the memory pointed by bufP
 *
 * @return 	How many data has been get
 */
int fifo_gets(fifo *p, fifo_len_t len, fifo_data_t *bufP)
{
	fifo_len_t count=0;

	if(p->beginP==NULL)
    {
        return -1;
    }

	while( (p->readP!=p->writeP) && (len>0) )
	{
		if(p->readP >= p->endP)
		{
			p->readP=p->beginP;
		}

        *bufP = *(p->readP);
        count++;
        p->readP++;
        bufP++;
        len--;
	}
	return count;
}

/**
 * @brief fifo_puts Put data into fifo
 *
 * @param p	Point to the fifo will be put
 * @param len	Indicate how many data will be put
 * @param bufP	Point to the data will be put
 *
 * @return How many data has put
 */
int fifo_puts(fifo *p, fifo_len_t len, fifo_data_t *bufP)
{
	fifo_len_t count=0;
    if(p->beginP==NULL)
    {
        return -1;
    }

	while( (p->readP!=(p->writeP+1)) && (len>0) )
	{
		if(p->writeP >= p->endP)
		{
			p->writeP=p->beginP;
		}

        *p->writeP = *bufP;
        count++;
        p->writeP++;
        bufP++;
        len--;
	}
	return count;
}
