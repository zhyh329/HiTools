/******************************************************************* 
 *  Copyright(c) 2018-- 
 *  All rights reserved. 
 *   
 *  Name: bits.h
 *  Note: common data defines and operator
 *   
 *  Ver:1.0 
 *  Author: shliu
 *  Date: 2018-10-15
 * 

 ******************************************************************/

#ifndef __CM_BITS_H_
#define __CM_BITS_H_
 
 /** void pointer. */
typedef void *cm_pvoid_t;

/** Signed 64bit integer. */
typedef long long  cm_int64_t;

/** Unsigned 64bit integer. */
typedef unsigned long long   cm_uint64_t;

/** Signed 32bit integer. */
typedef int     cm_int32_t;

/** Unsigned 32bit integer. */
typedef unsigned int    cm_uint32_t;

/** Signed 16bit integer. */
typedef short       cm_int16_t;

/** Unsigned 16bit integer. */
typedef unsigned short  cm_uint16_t;

/** Signed 8bit integer. */
typedef signed char cm_int8_t;

/** Unsigned 8bit integer. */
typedef unsigned char   cm_uint8_t;

/** status. */
#define CM_SUCCESS  (0)
#define CM_FAIL     (-1)

#define CM_FALSE    (0)
#define CM_TRUE     (!CM_FALSE)

/**base*/
#define CM_MIN(a, b)				((a) < (b) ? (a) : (b))
#define CM_MAX(a, b)				((a) < (b) ? (b) : (a))
#define CM_BETWEEN(x, a, b)			((a) <= (x) && (x) <= (b))
#define CM_DIVCEIL(n, d)			(((n) + ((d) - 1)) / (d))
#define CM_LIMIT(x, a, b)			((x) = (x) < (a) ? (a) : (x) > (b) ? (b) : (x))

#define CM_ARRAY_LEN(a)				(sizeof(a) / sizeof(a)[0])
#define CM_ALIGN_BACK(x, a) 		((a) * (((x) / (a))))
#define CM_ALIGN_UP(x, a)   		((a) * ((x+a-1)/(a)))

/**bits macro*/
#define CM_BIT_TEST(val,offset) 	(((val) & (1ll<<offset))!=0)

#define CM_BIT_SET(val,offset) 		(((val) |= (1ll<<offset)))

#define CM_BIT_CLR(val,offset) 		(((val) &= ~(1ll<<offset)))


/**little Endian*/
	
#define CM_PUT8(p, value) 	((p)[0] = (cm_uint8_t)((value)>>0)&0xff)

#define CM_GET8(p) 			((p)[0])


#define CM_PUTLE16(p, value)  ((p)[0] = ((cm_uint16_t)(value)>>0)&0xff, (p)[1] = ((cm_uint16_t)(value)>>8)&0xff)
						  
#define CM_PUTLE32(p, value)  (\
								(p)[0] = (cm_uint8_t)((cm_uint32_t)(value)>>0)&0xff, (p)[1] = (cm_uint8_t)((cm_uint32_t)(value)>>8)&0xff, \
								(p)[2] = (cm_uint8_t)((cm_uint32_t)(value)>>16)&0xff,(p)[3] = (cm_uint8_t)((cm_uint32_t)(value)>>24)&0xff \
							)
						  

#define CM_PUTLE64(p, value) ( \
								(p)[0] = (cm_uint8_t)((cm_uint64_t)(value)>>0)&0xff, 	(p)[1] = (cm_uint8_t)((cm_uint64_t)(value)>>8)&0xff, \
								(p)[2] = (cm_uint8_t)((cm_uint64_t)(value)>>16)&0xff,	(p)[3] = (cm_uint8_t)((cm_uint64_t)(value)>>24)&0xff,\
								(p)[4] = (cm_uint8_t)((cm_uint64_t)(value)>>32)&0xff,   (p)[5] = (cm_uint8_t)((cm_uint64_t)(value)>>40)&0xff,\
								(p)[6] = (cm_uint8_t)((cm_uint64_t)(value)>>48)&0xff,	(p)[7] = (cm_uint8_t)((cm_uint64_t)(value)>>56)&0xff\
							)
							
#define CM_GETLE16(p) 		(((cm_uint8_t)(p)[0] << 0) | ((cm_uint8_t)(p)[1] << 8))
							
#define CM_GETLE32(p) 		( \
								((cm_uint8_t)(p)[0] << 0) | ((cm_uint8_t)(p)[1] << 8) | \
								((cm_uint8_t)(p)[2] << 16)| ((cm_uint8_t)(p)[3] << 24)  \
							)
							
#define CM_GETLE64(p) 		( \
								((cm_uint64_t)(p)[0] << 0)  |  ((cm_uint64_t)(p)[1] << 8) |  \
								((cm_uint64_t)(p)[2] << 16) | ((cm_uint64_t)(p)[3] << 24) | \
								((cm_uint64_t)(p)[4] << 32) | ((cm_uint64_t)(p)[5] << 40) |\
								((cm_uint64_t)(p)[6] << 48) | ((cm_uint64_t)(p)[7] << 56)	\
							)

/**big Endian*/
#define CM_PUTBE16(p, value) ( (p)[0] = ((cm_uint16_t)(value)>>8)&0xff, (p)[1] = ((cm_uint16_t)(value)>>0)&0xff )
							
#define CM_PUTBE32(p, value) ( \
								(p)[0] = (cm_uint8_t)((cm_uint32_t)(value)>>24)&0xff, (p)[1] = (cm_uint8_t)((cm_uint32_t)(value)>>16)&0xff, \
								(p)[2] = (cm_uint8_t)((cm_uint32_t)(value)>>8)&0xff,  (p)[3] = (cm_uint8_t)((cm_uint32_t)(value)>>0)&0xff \
							)
							
#define CM_PUTBE64(p, value) ( \
								(p)[0] = (cm_uint8_t)((cm_uint64_t)(value)>>56)&0xff, (p)[1] = (cm_uint8_t)((cm_uint64_t)(value)>>48)&0xff, \
								(p)[2] = (cm_uint8_t)((cm_uint64_t)(value)>>40)&0xff, (p)[3] = (cm_uint8_t)((cm_uint64_t)(value)>>32)&0xff, \
								(p)[4] = (cm_uint8_t)((cm_uint64_t)(value)>>24)&0xff, (p)[5] = (cm_uint8_t)((cm_uint64_t)(value)>>16)&0xff, \
								(p)[6] = (cm_uint8_t)((cm_uint64_t)(value)>>8)&0xff,  (p)[7] = (cm_uint8_t)((cm_uint64_t)(value)>>0)&0xff \
							)

#define CM_GETBE16(p) 	( ((cm_uint8_t)(p)[0] << 8) | ((cm_uint8_t)(p)[1] << 0))
						
#define CM_GETBE32(p)   (\
							((cm_uint8_t)(p)[0] << 24) | ((cm_uint8_t)(p)[1] << 16) | \
							((cm_uint8_t)(p)[2] << 8) | ((cm_uint8_t)(p)[3] << 0)\
						)
						
#define CM_GETBE64(p) 	( \
							((cm_uint64_t)(p)[0] << 56) | ((cm_uint64_t)(p)[1] << 48) | \
							((cm_uint64_t)(p)[2] << 40) | ((cm_uint64_t)(p)[3] << 32) | \
							((cm_uint64_t)(p)[4] << 24) | ((cm_uint64_t)(p)[5] << 16) | \
							((cm_uint64_t)(p)[6] << 8) | ((cm_uint64_t)(p)[7] << 0) \
						)

/**free delete close*/

#define CM_SAFE_FREE_(ptr) do{\
        if(ptr != NULL)\
        {\
            free(ptr);\
            ptr = NULL;\
        }\
    }while(0)


#define CM_SAFE_DELETE_(ptr) do{\
        if(ptr != NULL)\
        {\
            delete ptr;\
            ptr = NULL;\
        }\
    }while(0)


#define CM_SAFE_DELETE_ARRAY_(ptr) do{\
        if(ptr != NULL)\
        {\
            delete []ptr;\
            ptr = NULL;\
        }\
    }while(0)


#define CM_SAFE_CLOSE_(fd) do{\
        if(fd >= 0)\
        {\
            close(fd);\
            fd = -1;\
        }\
    }while(0)


#define CM_SAFE_FCLOSE_(fp) do{\
        if(fp != NULL)\
        {\
            fclose(fp);\
            fp = NULL;\
        }\
    }while(0)


#define CM_POINTER_ASSIGNMENT_(ptr, value) do{\
    if(ptr != NULL)\
    {\
        *ptr = value;\
    }\
}while(0)
						

#endif//__CM_BITS_H_
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *    
   *     C o p y r i g h t ( c )   2 0 1 8 - -    
   *     A l l   r i g h t s   r e s e r v e d .    
   *        
   *     N a m e :   b i t s . h  
   *     N o t e :   c o m m o n   d a t a   d e f i n e s  
   *        
   *     V e r : 1 . 0    
   *     A u t h o r :   s h l i u  
   *     D a t e :   2 0 1 8 - 1 0 - 1 5  
   *    
  
   * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * /  
  
 # i f n d e f   _ _ C M _ B I T S _ H _  
 # d e f i n e   _ _ C M _ B I T S _ H _  
    
   / * *   v o i d   p o i n t e r .   * /  
 t y p e d e f   v o i d   * c m _ p v o i d _ t ;  
  
 / * *   S i g n e d   6 4 b i t   i n t e g e r .   * /  
 t y p e d e f   l o n g   l o n g     c m _ i n t 6 4 _ t ;  
  
 / * *   U n s i g n e d   6 4 b i t   i n t e g e r .   * /  
 t y p e d e f   u n s i g n e d   l o n g   l o n g       c m _ u i n t 6 4 _ t ;  
  
 / * *   S i g n e d   3 2 b i t   i n t e g e r .   * /  
 t y p e d e f   i n t           c m _ i n t 3 2 _ t ;  
  
 / * *   U n s i g n e d   3 2 b i t   i n t e g e r .   * /  
 t y p e d e f   u n s i g n e d   i n t         c m _ u i n t 3 2 _ t ;  
  
 / * *   S i g n e d   1 6 b i t   i n t e g e r .   * /  
 t y p e d e f   s h o r t               c m _ i n t 1 6 _ t ;  
  
 / * *   U n s i g n e d   1 6 b i t   i n t e g e r .   * /  
 t y p e d e f   u n s i g n e d   s h o r t     c m _ u i n t 1 6 _ t ;  
  
 / * *   S i g n e d   8 b i t   i n t e g e r .   * /  
 t y p e d e f   s i g n e d   c h a r   c m _ i n t 8 _ t ;  
  
 / * *   U n s i g n e d   8 b i t   i n t e g e r .   * /  
 t y p e d e f   u n s i g n e d   c h a r       c m _ u i n t 8 _ t ;  
  
 / * *   s t a t u s .   * /  
 # d e f i n e   C M _ S U C C E S S     ( 0 )  
 # d e f i n e   C M _ F A I L           ( - 1 )  
  
 # d e f i n e   C M _ F A L S E         ( 0 )  
 # d e f i n e   C M _ T R U E           ( ! C M _ F A L S E )  
  
 / * * b a s e * /  
 # d e f i n e   C M _ M I N ( a ,   b ) 	 	 	 	 ( ( a )   <   ( b )   ?   ( a )   :   ( b ) )  
 # d e f i n e   C M _ M A X ( a ,   b ) 	 	 	 	 ( ( a )   <   ( b )   ?   ( b )   :   ( a ) )  
 # d e f i n e   C M _ B E T W E E N ( x ,   a ,   b ) 	 	 	 ( ( a )   < =   ( x )   & &   ( x )   < =   ( b ) )  
 # d e f i n e   C M _ D I V C E I L ( n ,   d ) 	 	 	 ( ( ( n )   +   ( ( d )   -   1 ) )   /   ( d ) )  
 # d e f i n e   C M _ L I M I T ( x ,   a ,   b ) 	 	 	 ( ( x )   =   ( x )   <   ( a )   ?   ( a )   :   ( x )   >   ( b )   ?   ( b )   :   ( x ) )  
  
 # d e f i n e   C M _ A R R A Y _ L E N ( a ) 	 	 	 	 ( s i z e o f ( a )   /   s i z e o f ( a ) [ 0 ] )  
 # d e f i n e   C M _ A L I G N _ B A C K ( x ,   a )   	 	 ( ( a )   *   ( ( ( x )   /   ( a ) ) ) )  
 # d e f i n e   C M _ A L I G N _ U P ( x ,   a )       	 	 ( ( a )   *   ( ( x + a - 1 ) / ( a ) ) )  
  
 / * * b i t s   m a c r o * /  
 # d e f i n e   C M _ B I T _ T E S T ( v a l , o f f s e t )   	 ( ( ( v a l )   &   ( 1 l l < < o f f s e t ) ) ! = 0 )  
  
 # d e f i n e   C M _ B I T _ S E T ( v a l , o f f s e t )   	 	 ( ( ( v a l )   | =   ( 1 l l < < o f f s e t ) ) )  
  
 # d e f i n e   C M _ B I T _ C L R ( v a l , o f f s e t )   	 	 ( ( ( v a l )   & =   ~ ( 1 l l < < o f f s e t ) ) )  
  
  
 / * * l i t t l e   E n d i a n * /  
 	  
 # d e f i n e   C M _ P U T 8 ( p ,   v a l u e )   	 ( ( p ) [ 0 ]   =   ( c m _ u i n t 8 _ t ) ( ( v a l u e ) > > 0 ) & 0 x f f )  
  
 # d e f i n e   C M _ G E T 8 ( p )   	 	 	 ( ( p ) [ 0 ] )  
  
  
 # d e f i n e   C M _ P U T L E 1 6 ( p ,   v a l u e )     ( ( p ) [ 0 ]   =   ( ( c m _ u i n t 1 6 _ t ) ( v a l u e ) > > 0 ) & 0 x f f ,   ( p ) [ 1 ]   =   ( ( c m _ u i n t 1 6 _ t ) ( v a l u e ) > > 8 ) & 0 x f f )  
 	 	 	 	 	 	      
 # d e f i n e   C M _ P U T L E 3 2 ( p ,   v a l u e )     ( \  
 	 	 	 	 	 	 	 	 ( p ) [ 0 ]   =   ( c m _ u i n t 8 _ t ) ( ( c m _ u i n t 3 2 _ t ) ( v a l u e ) > > 0 ) & 0 x f f ,   ( p ) [ 1 ]   =   ( c m _ u i n t 8 _ t ) ( ( c m _ u i n t 3 2 _ t ) ( v a l u e ) > > 8 ) & 0 x f f ,   \  
 	 	 	 	 	 	 	 	 ( p ) [ 2 ]   =   ( c m _ u i n t 8 _ t ) ( ( c m _ u i n t 3 2 _ t ) ( v a l u e ) > > 1 6 ) & 0 x f f , ( p ) [ 3 ]   =   ( c m _ u i n t 8 _ t ) ( ( c m _ u i n t 3 2 _ t ) ( v a l u e ) > > 2 4 ) & 0 x f f   \  
 	 	 	 	 	 	 	 )  
 	 	 	 	 	 	      
  
 # d e f i n e   C M _ P U T L E 6 4 ( p ,   v a l u e )   (   \  
 	 	 	 	 	 	 	 	 ( p ) [ 0 ]   =   ( c m _ u i n t 8 _ t ) ( ( c m _ u i n t 6 4 _ t ) ( v a l u e ) > > 0 ) & 0 x f f ,   	 ( p ) [ 1 ]   =   ( c m _ u i n t 8 _ t ) ( ( c m _ u i n t 6 4 _ t ) ( v a l u e ) > > 8 ) & 0 x f f ,   \  
 	 	 	 	 	 	 	 	 ( p ) [ 2 ]   =   ( c m _ u i n t 8 _ t ) ( ( c m _ u i n t 6 4 _ t ) ( v a l u e ) > > 1 6 ) & 0 x f f , 	 ( p ) [ 3 ]   =   ( c m _ u i n t 8 _ t ) ( ( c m _ u i n t 6 4 _ t ) ( v a l u e ) > > 2 4 ) & 0 x f f , \  
 	 	 	 	 	 	 	 	 ( p ) [ 4 ]   =   ( c m _ u i n t 8 _ t ) ( ( c m _ u i n t 6 4 _ t ) ( v a l u e ) > > 3 2 ) & 0 x f f ,       ( p ) [ 5 ]   =   ( c m _ u i n t 8 _ t ) ( ( c m _ u i n t 6 4 _ t ) ( v a l u e ) > > 4 0 ) & 0 x f f , \  
 	 	 	 	 	 	 	 	 ( p ) [ 6 ]   =   ( c m _ u i n t 8 _ t ) ( ( c m _ u i n t 6 4 _ t ) ( v a l u e ) > > 4 8 ) & 0 x f f , 	 ( p ) [ 7 ]   =   ( c m _ u i n t 8 _ t ) ( ( c m _ u i n t 6 4 _ t ) ( v a l u e ) > > 5 6 ) & 0 x f f \  
 	 	 	 	 	 	 	 )  
 	 	 	 	 	 	 	  
 # d e f i n e   C M _ G E T L E 1 6 ( p )   	 	 ( ( ( c m _ u i n t 8 _ t ) ( p ) [ 0 ]   < <   0 )   |   ( ( c m _ u i n t 8 _ t ) ( p ) [ 1 ]   < <   8 ) )  
 	 	 	 	 	 	 	  
 # d e f i n e   C M _ G E T L E 3 2 ( p )   	 	 (   \  
 	 	 	 	 	 	 	 	 ( ( c m _ u i n t 8 _ t ) ( p ) [ 0 ]   < <   0 )   |   ( ( c m _ u i n t 8 _ t ) ( p ) [ 1 ]   < <   8 )   |   \  
 	 	 	 	 	 	 	 	 ( ( c m _ u i n t 8 _ t ) ( p ) [ 2 ]   < <   1 6 ) |   ( ( c m _ u i n t 8 _ t ) ( p ) [ 3 ]   < <   2 4 )     \  
 	 	 	 	 	 	 	 )  
 	 	 	 	 	 	 	  
 # d e f i n e   C M _ G E T L E 6 4 ( p )   	 	 (   \  
 	 	 	 	 	 	 	 	 ( ( c m _ u i n t 6 4 _ t ) ( p ) [ 0 ]   < <   0 )     |     ( ( c m _ u i n t 6 4 _ t ) ( p ) [ 1 ]   < <   8 )   |     \  
 	 	 	 	 	 	 	 	 ( ( c m _ u i n t 6 4 _ t ) ( p ) [ 2 ]   < <   1 6 )   |   ( ( c m _ u i n t 6 4 _ t ) ( p ) [ 3 ]   < <   2 4 )   |   \  
 	 	 	 	 	 	 	 	 ( ( c m _ u i n t 6 4 _ t ) ( p ) [ 4 ]   < <   3 2 )   |   ( ( c m _ u i n t 6 4 _ t ) ( p ) [ 5 ]   < <   4 0 )   | \  
 	 	 	 	 	 	 	 	 ( ( c m _ u i n t 6 4 _ t ) ( p ) [ 6 ]   < <   4 8 )   |   ( ( c m _ u i n t 6 4 _ t ) ( p ) [ 7 ]   < <   5 6 ) 	 \  
 	 	 	 	 	 	 	 )  
  
 / * * b i g   E n d i a n * /  
 # d e f i n e   C M _ P U T B E 1 6 ( p ,   v a l u e )   (   ( p ) [ 0 ]   =   ( ( c m _ u i n t 1 6 _ t ) ( v a l u e ) > > 8 ) & 0 x f f ,   ( p ) [ 1 ]   =   ( ( c m _ u i n t 1 6 _ t ) ( v a l u e ) > > 0 ) & 0 x f f   )  
 	 	 	 	 	 	 	  
 # d e f i n e   C M _ P U T B E 3 2 ( p ,   v a l u e )   (   \  
 	 	 	 	 	 	 	 	 ( p ) [ 0 ]   =   ( c m _ u i n t 8 _ t ) ( ( c m _ u i n t 3 2 _ t ) ( v a l u e ) > > 2 4 ) & 0 x f f ,   ( p ) [ 1 ]   =   ( c m _ u i n t 8 _ t ) ( ( c m _ u i n t 3 2 _ t ) ( v a l u e ) > > 1 6 ) & 0 x f f ,   \  
 	 	 	 	 	 	 	 	 ( p ) [ 2 ]   =   ( c m _ u i n t 8 _ t ) ( ( c m _ u i n t 3 2 _ t ) ( v a l u e ) > > 8 ) & 0 x f f ,     ( p ) [ 3 ]   =   ( c m _ u i n t 8 _ t ) ( ( c m _ u i n t 3 2 _ t ) ( v a l u e ) > > 0 ) & 0 x f f   \  
 	 	 	 	 	 	 	 )  
 	 	 	 	 	 	 	  
 # d e f i n e   C M _ P U T B E 6 4 ( p ,   v a l u e )   (   \  
 	 	 	 	 	 	 	 	 ( p ) [ 0 ]   =   ( c m _ u i n t 8 _ t ) ( ( c m _ u i n t 6 4 _ t ) ( v a l u e ) > > 5 6 ) & 0 x f f ,   ( p ) [ 1 ]   =   ( c m _ u i n t 8 _ t ) ( ( c m _ u i n t 6 4 _ t ) ( v a l u e ) > > 4 8 ) & 0 x f f ,   \  
 	 	 	 	 	 	 	 	 ( p ) [ 2 ]   =   ( c m _ u i n t 8 _ t ) ( ( c m _ u i n t 6 4 _ t ) ( v a l u e ) > > 4 0 ) & 0 x f f ,   ( p ) [ 3 ]   =   ( c m _ u i n t 8 _ t ) ( ( c m _ u i n t 6 4 _ t ) ( v a l u e ) > > 3 2 ) & 0 x f f ,   \  
 	 	 	 	 	 	 	 	 ( p ) [ 4 ]   =   ( c m _ u i n t 8 _ t ) ( ( c m _ u i n t 6 4 _ t ) ( v a l u e ) > > 2 4 ) & 0 x f f ,   ( p ) [ 5 ]   =   ( c m _ u i n t 8 _ t ) ( ( c m _ u i n t 6 4 _ t ) ( v a l u e ) > > 1 6 ) & 0 x f f ,   \  
 	 	 	 	 	 	 	 	 ( p ) [ 6 ]   =   ( c m _ u i n t 8 _ t ) ( ( c m _ u i n t 6 4 _ t ) ( v a l u e ) > > 8 ) & 0 x f f ,     ( p ) [ 7 ]   =   ( c m _ u i n t 8 _ t ) ( ( c m _ u i n t 6 4 _ t ) ( v a l u e ) > > 0 ) & 0 x f f   \  
 	 	 	 	 	 	 	 )  
  
 # d e f i n e   C M _ G E T B E 1 6 ( p )   	 (   ( ( c m _ u i n t 8 _ t ) ( p ) [ 0 ]   < <   8 )   |   ( ( c m _ u i n t 8 _ t ) ( p ) [ 1 ]   < <   0 ) )  
 	 	 	 	 	 	  
 # d e f i n e   C M _ G E T B E 3 2 ( p )       ( \  
 	 	 	 	 	 	 	 ( ( c m _ u i n t 8 _ t ) ( p ) [ 0 ]   < <   2 4 )   |   ( ( c m _ u i n t 8 _ t ) ( p ) [ 1 ]   < <   1 6 )   |   \  
 	 	 	 	 	 	 	 ( ( c m _ u i n t 8 _ t ) ( p ) [ 2 ]   < <   8 )   |   ( ( c m _ u i n t 8 _ t ) ( p ) [ 3 ]   < <   0 ) \  
 	 	 	 	 	 	 )  
 	 	 	 	 	 	  
 # d e f i n e   C M _ G E T B E 6 4 ( p )   	 (   \  
 	 	 	 	 	 	 	 ( ( c m _ u i n t 6 4 _ t ) ( p ) [ 0 ]   < <   5 6 )   |   ( ( c m _ u i n t 6 4 _ t ) ( p ) [ 1 ]   < <   4 8 )   |   \  
 	 	 	 	 	 	 	 ( ( c m _ u i n t 6 4 _ t ) ( p ) [ 2 ]   < <   4 0 )   |   ( ( c m _ u i n t 6 4 _ t ) ( p ) [ 3 ]   < <   3 2 )   |   \  
 	 	 	 	 	 	 	 ( ( c m _ u i n t 6 4 _ t ) ( p ) [ 4 ]   < <   2 4 )   |   ( ( c m _ u i n t 6 4 _ t ) ( p ) [ 5 ]   < <   1 6 )   |   \  
 	 	 	 	 	 	 	 ( ( c m _ u i n t 6 4 _ t ) ( p ) [ 6 ]   < <   8 )   |   ( ( c m _ u i n t 6 4 _ t ) ( p ) [ 7 ]   < <   0 )   \  
 	 	 	 	 	 	 )  
  
 / * * f r e e   d e l e t e   c l o s e * /  
  
 # d e f i n e   C M _ S A F E _ F R E E _ ( p t r )   d o { \  
                 i f ( p t r   ! =   N U L L ) \  
                 { \  
                         f r e e ( p t r ) ; \  
                         p t r   =   N U L L ; \  
                 } \  
         } w h i l e ( 0 )  
  
  
 # d e f i n e   C M _ S A F E _ D E L E T E _ ( p t r )   d o { \  
                 i f ( p t r   ! =   N U L L ) \  
                 { \  
                         d e l e t e   p t r ; \  
                         p t r   =   N U L L ; \  
                 } \  
         } w h i l e ( 0 )  
  
  
 # d e f i n e   C M _ S A F E _ D E L E T E _ A R R A Y _ ( p t r )   d o { \  
                 i f ( p t r   ! =   N U L L ) \  
                 { \  
                         d e l e t e   [ ] p t r ; \  
                         p t r   =   N U L L ; \  
                 } \  
         } w h i l e ( 0 )  
  
  
 # d e f i n e   C M _ S A F E _ C L O S E _ ( f d )   d o { \  
                 i f ( f d   > =   0 ) \  
                 { \  
                         c l o s e ( f d ) ; \  
                         f d   =   - 1 ; \  
                 } \  
         } w h i l e ( 0 )  
  
  
 # d e f i n e   C M _ S A F E _ F C L O S E _ ( f p )   d o { \  
                 i f ( f p   ! =   N U L L ) \  
                 { \  
                         f c l o s e ( f p ) ; \  
                         f p   =   N U L L ; \  
                 } \  
         } w h i l e ( 0 )  
  
  
 # d e f i n e   C M _ P O I N T E R _ A S S I G N M E N T _ ( p t r ,   v a l u e )   d o { \  
         i f ( p t r   ! =   N U L L ) \  
         { \  
                 * p t r   =   v a l u e ; \  
         } \  
 } w h i l e ( 0 )  
 	 	 	 	 	 	  
  
 # e n d i f / / _ _ C M _ B I T S _ H _  
 
