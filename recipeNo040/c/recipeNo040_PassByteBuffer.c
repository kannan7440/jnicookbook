#include <stdio.h>
#include "jni.h"
#include "recipeNo040_PassByteBuffer.h"

#define BUFFER_SIZE 44

JNIEXPORT int JNICALL Java_recipeNo040_PassByteBuffer_displayByteBuffer
  (JNIEnv *env, jclass obj, jobject objarg) {
	
  /* Get objarg's class - objarg is the one we pass from
     Java */
  jclass clsByteBuffer = (*env)->GetObjectClass(env, objarg); 

  /* Remember that you can alway get method signature using javap tool
     > javap -s -p java.nio.ByteBuffer | grep -A 1 get
     ...
     --
       public abstract byte get(int);
      descriptor: (I)B
     --
     ...
  */
  
  jmethodID midGetByte = 
    (*env)->GetMethodID(env, clsByteBuffer, "get", "(I)B"); 

  /* We have to make sure that method exists */
  if (midGetByte == NULL) {
    return -1; /* method not found */ 
  } 

  /* Now, it's time to get some values */
  for(int i=0; i<BUFFER_SIZE; i++) {
    jbyte byteValue = (*env)->CallByteMethod(env, objarg, midGetByte, i);
    printf("%d\n", byteValue); 
  }

  return 0;

}
