/* 
 * INTRINS.H: intrisic functions for C-51
 * Copyright (c) KEIL ELEKTRONIK GmbH and Franklin Software, Inc., 1991-1993
 * V3.00
 */


extern void          _nop_     (void);
extern bit           _testbit_ (bit);
extern unsigned char _cror_    (unsigned char, unsigned char);
extern unsigned int  _iror_    (unsigned int,  unsigned char);
extern unsigned long _lror_    (unsigned long, unsigned char);
extern unsigned char _crol_    (unsigned char, unsigned char);
extern unsigned int  _irol_    (unsigned int,  unsigned char);
extern unsigned long _lrol_    (unsigned long, unsigned char);
