/**************************************************************************
 *
 * Copyright 2009 VMware, Inc.
 * All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sub license, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice (including the
 * next paragraph) shall be included in all copies or substantial portions
 * of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT.
 * IN NO EVENT SHALL VMWARE AND/OR ITS SUPPLIERS BE LIABLE FOR
 * ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 **************************************************************************/


#include "util/u_debug.h"

#include "lp_bld_type.h"
#include "lp_bld_const.h"


LLVMTypeRef
lp_build_elem_type(union lp_type type)
{
   if (type.floating) {
      switch(type.width) {
      case 32:
         return LLVMFloatType();
         break;
      case 64:
         return LLVMDoubleType();
         break;
      default:
         assert(0);
         return LLVMFloatType();
      }
   }
   else {
      return LLVMIntType(type.width);
   }
}


LLVMTypeRef
lp_build_vec_type(union lp_type type)
{
   LLVMTypeRef elem_type = lp_build_elem_type(type);
   return LLVMVectorType(elem_type, type.length);
}


/**
 * This function is a mirror of lp_build_elem_type() above.
 *
 * XXX: I'm not sure if it wouldn't be easier/efficient to just recreate the
 * type and check for identity.
 */
boolean
lp_check_elem_type(union lp_type type, LLVMTypeRef elem_type) 
{
   LLVMTypeKind elem_kind;

   assert(elem_type);
   if(!elem_type)
      return FALSE;

   elem_kind = LLVMGetTypeKind(elem_type);

   if (type.floating) {
      switch(type.width) {
      case 32:
         if(elem_kind != LLVMFloatTypeKind)
            return FALSE;
         break;
      case 64:
         if(elem_kind != LLVMDoubleTypeKind)
            return FALSE;
         break;
      default:
         assert(0);
         return FALSE;
      }
   }
   else {
      if(elem_kind != LLVMIntegerTypeKind)
         return FALSE;

      if(LLVMGetIntTypeWidth(elem_type) != type.width)
         return FALSE;
   }

   return TRUE; 
}


boolean
lp_check_vec_type(union lp_type type, LLVMTypeRef vec_type) 
{
   LLVMTypeRef elem_type;

   assert(vec_type);
   if(!vec_type)
      return FALSE;

   if(LLVMGetTypeKind(vec_type) != LLVMVectorTypeKind)
      return FALSE;

   if(LLVMGetVectorSize(vec_type) != type.length)
      return FALSE;

   elem_type = LLVMGetElementType(vec_type);

   return lp_check_elem_type(type, elem_type);
}


boolean
lp_check_value(union lp_type type, LLVMValueRef val) 
{
   LLVMTypeRef vec_type;

   assert(val);
   if(!val)
      return FALSE;

   vec_type = LLVMTypeOf(val);

   return lp_check_vec_type(type, vec_type);
}


LLVMTypeRef
lp_build_int_elem_type(union lp_type type)
{
   return LLVMIntType(type.width);
}


LLVMTypeRef
lp_build_int_vec_type(union lp_type type)
{
   LLVMTypeRef elem_type = lp_build_int_elem_type(type);
   return LLVMVectorType(elem_type, type.length);
}


void
lp_build_context_init(struct lp_build_context *bld,
                      LLVMBuilderRef builder,
                      union lp_type type)
{
   bld->builder = builder;
   bld->type = type;
   bld->undef = lp_build_undef(type);
   bld->zero = lp_build_zero(type);
   bld->one = lp_build_one(type);
}
