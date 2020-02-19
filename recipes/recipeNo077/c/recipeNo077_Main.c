#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/errno.h>
#include "recipeNo077_Main.h"

JNIEXPORT jobject JNICALL Java_recipeNo077_Main_buildObject
  (JNIEnv *env, jobject obj) {

  // Let's prepare result holder - Wrapper obj
  jclass    wCls                 = (*env)->FindClass( env, "recipeNo077/Wrapper" );
  jmethodID wConstructorID       = (*env)->GetMethodID( env, wCls, "<init>", "()V" );
  jmethodID setStringValMethodID = (*env)->GetMethodID( env, wCls, "setStringVal", "(Ljava/lang/String;)V" );

  // Construct new object of type recipeNo077.Wrapper
  jobject wObj = (*env)->NewObject( env, wCls, wConstructorID );

  // Set values of object's field using set method
  // Note that we are passing `C` style NULL that will
  // be visible as null on `Java` side
  (*env)->CallVoidMethod(env, wObj, setStringValMethodID, NULL );
   
  return wObj;

}

