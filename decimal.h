#ifndef DECIMAL_H
#define DECIMAL_H

typedef float decimal_t;

#ifndef decimalDiv
#define decimalDiv(a,b) ((decimal_t)((decimal_t)(a))/((decimal_t)(b)))
#endif

#endif // DECIMAL_H
