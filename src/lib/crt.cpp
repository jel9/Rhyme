//
// Created by chloe on 7/25/24.
//

#include <stddef.h>
#include <stdint.h>

extern "C" void *
memset (void *d, int c, size_t n)
{
  char *p = (char *)d;
  while (n--)
    {
      *p++ = c;
    }
  return d;
}

extern "C" void *
memcpy (void *dest, const void *src, size_t n)
{
  char *p1 = (char *)dest;
  char *p2 = (char *)src;

  while (n--)
    {
      *p1++ = *p2++;
    }
  return dest;
}

extern "C" void *
memmove (void *dest, const void *src, size_t n)
{
  uint8_t *pdest = (uint8_t *)dest;
  const uint8_t *psrc = (const uint8_t *)src;

  if (src > dest)
    {
      for (size_t i = 0; i < n; i++)
        {
          pdest[i] = psrc[i];
        }
    }
  else if (src < dest)
    {
      for (size_t i = n; i > 0; i--)
        {
          pdest[i - 1] = psrc[i - 1];
        }
    }

  return dest;
}

extern "C" int
memcmp (const void *str1, const void *str2, size_t count)
{
  const unsigned char *c1, *c2;

  c1 = (const unsigned char *)str1;
  c2 = (const unsigned char *)str2;

  while (count-- > 0)
    {
      if (*c1++ != *c2++)
        return c1[-1] < c2[-1] ? -1 : 1;
    }
  return 0;
}

extern "C" size_t
strlen (const char *s)
{
  size_t i = 0;
  while (*s++)
    i++;
  return i;
}

extern "C" char *
strncpy (char *destination, const char *source, size_t num)
{
  while ((*destination++ = *source++) && num--)
    ;
  return destination;
}