/*******************************************************************/
/**                  +-+-+-+-+-+-+-+-+-+-+                        **/
/**                  |  L P J  -  w s l  |                        **/
/**                  +-+-+-+-+-+-+-+-+-+-+                        **/
/**                                                               **/
/**  src/crop/ f r e e _ c r o p . c                              **/
/*******************************************************************/

#include "lpj.h"
#include "crop.h"

void free_crop(Pft *pft)
{
  free(pft->data);
} /* of 'free_crop' */
