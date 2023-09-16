#ifndef CC_PLUGIN4_GLOBAL_H
#define CC_PLUGIN4_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(CC_PLUGIN4_LIBRARY)
#  define CC_PLUGIN4_EXPORT Q_DECL_EXPORT
#else
#  define CC_PLUGIN4_EXPORT Q_DECL_IMPORT
#endif

#endif // CC_PLUGIN4_GLOBAL_H
