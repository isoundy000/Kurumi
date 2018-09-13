/*
** Lua binding: game
** Generated automatically by tolua++-1.0.92 on 09/13/18 10:47:26.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"
#include "tolua++.h"
#include "lua_function/tolua_ext.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"


/* Exported function */
TOLUA_API int  tolua_game_open (lua_State* tolua_S);

#include "gamecore/FSM.h"
#include "gamecore/GameActor.h"
#include "gamecore/GameAttribute.h"
#include "gamecore/GameMap.h"
#include "gamecore/GameWord.h"
#include "net/Client.h"
#include "Box2D/Box2D.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_GameAttribute (lua_State* tolua_S)
{
 GameAttribute* self = (GameAttribute*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_GameActor (lua_State* tolua_S)
{
 GameActor* self = (GameActor*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_b2BodyType (lua_State* tolua_S)
{
 b2BodyType* self = (b2BodyType*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_QFSM (lua_State* tolua_S)
{
 QFSM* self = (QFSM*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_b2Vec2 (lua_State* tolua_S)
{
 b2Vec2* self = (b2Vec2*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_QFSMState (lua_State* tolua_S)
{
 QFSMState* self = (QFSMState*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"GameAttribute");
 tolua_usertype(tolua_S,"QFSMState");
 tolua_usertype(tolua_S,"b2BodyType");
 
 tolua_usertype(tolua_S,"TCPClient");
 tolua_usertype(tolua_S,"b2Body");
 tolua_usertype(tolua_S,"GameMap");
 tolua_usertype(tolua_S,"ccs.Armature");
  tolua_usertype(tolua_S,"GameActor");
 tolua_usertype(tolua_S,"GameWord");
 tolua_usertype(tolua_S,"Node");
 tolua_usertype(tolua_S,"QFSM");
 tolua_usertype(tolua_S,"Client");
 tolua_usertype(tolua_S,"cc.Node");
 tolua_usertype(tolua_S,"SK");
}

/* method: new of class  QFSMState */
#ifndef TOLUA_DISABLE_tolua_game_QFSMState_new00
static int tolua_game_QFSMState_new00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"QFSMState",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"SK",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !toluafix_isfunction(tolua_S,3,"LuaFunction",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !toluafix_isfunction(tolua_S,4,"LuaFunction",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SK stateName = *((SK*)  tolua_tousertype(tolua_S,2,0));
  LuaFunction enterFunc = (  LuaFunction(tolua_S,3,0));
  LuaFunction leaveFunc = (  LuaFunction(tolua_S,4,0));
  {
   QFSMState* tolua_ret = (QFSMState*)  Mtolua_new((QFSMState)(stateName,enterFunc,leaveFunc));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"QFSMState");
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  QFSMState */
#ifndef TOLUA_DISABLE_tolua_game_QFSMState_new00_local
static int tolua_game_QFSMState_new00_local(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"QFSMState",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"SK",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !toluafix_isfunction(tolua_S,3,"LuaFunction",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !toluafix_isfunction(tolua_S,4,"LuaFunction",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SK stateName = *((SK*)  tolua_tousertype(tolua_S,2,0));
  LuaFunction enterFunc = (  LuaFunction(tolua_S,3,0));
  LuaFunction leaveFunc = (  LuaFunction(tolua_S,4,0));
  {
   QFSMState* tolua_ret = (QFSMState*)  Mtolua_new((QFSMState)(stateName,enterFunc,leaveFunc));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"QFSMState");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  QFSMState */
#ifndef TOLUA_DISABLE_tolua_game_QFSMState_delete00
static int tolua_game_QFSMState_delete00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"QFSMState",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  QFSMState* self = (QFSMState*)  tolua_tousertype(tolua_S,1,0);
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getStateName of class  QFSMState */
#ifndef TOLUA_DISABLE_tolua_game_QFSMState_getStateName00
static int tolua_game_QFSMState_getStateName00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"QFSMState",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  QFSMState* self = (QFSMState*)  tolua_tousertype(tolua_S,1,0);
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getStateName'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->getStateName();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getStateName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getFSM of class  QFSMState */
#ifndef TOLUA_DISABLE_tolua_game_QFSMState_getFSM00
static int tolua_game_QFSMState_getFSM00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"QFSMState",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  QFSMState* self = (QFSMState*)  tolua_tousertype(tolua_S,1,0);
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFSM'", NULL);
#endif
  {
   QFSM* tolua_ret = (QFSM*)  self->getFSM();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"QFSM");
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getFSM'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  QFSM */
#ifndef TOLUA_DISABLE_tolua_game_QFSM_new00
static int tolua_game_QFSM_new00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"QFSM",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   QFSM* tolua_ret = (QFSM*)  Mtolua_new((QFSM)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"QFSM");
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  QFSM */
#ifndef TOLUA_DISABLE_tolua_game_QFSM_new00_local
static int tolua_game_QFSM_new00_local(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"QFSM",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   QFSM* tolua_ret = (QFSM*)  Mtolua_new((QFSM)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"QFSM");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  QFSM */
#ifndef TOLUA_DISABLE_tolua_game_QFSM_delete00
static int tolua_game_QFSM_delete00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"QFSM",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  QFSM* self = (QFSM*)  tolua_tousertype(tolua_S,1,0);
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addState of class  QFSM */
#ifndef TOLUA_DISABLE_tolua_game_QFSM_addState00
static int tolua_game_QFSM_addState00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"QFSM",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !toluafix_isfunction(tolua_S,3,"LuaFunction",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !toluafix_isfunction(tolua_S,4,"LuaFunction",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  QFSM* self = (QFSM*)  tolua_tousertype(tolua_S,1,0);
  std::string stateName = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  LuaFunction enterFunc = (  LuaFunction(tolua_S,3,0));
  LuaFunction leaveFunc = (  LuaFunction(tolua_S,4,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addState'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->addState(stateName,enterFunc,leaveFunc);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addState'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addTranslation of class  QFSM */
#ifndef TOLUA_DISABLE_tolua_game_QFSM_addTranslation00
static int tolua_game_QFSM_addTranslation00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"QFSM",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  QFSM* self = (QFSM*)  tolua_tousertype(tolua_S,1,0);
  std::string fromStateName = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  std::string eventName = ((std::string)  tolua_tocppstring(tolua_S,3,0));
  std::string toStateName = ((std::string)  tolua_tocppstring(tolua_S,4,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addTranslation'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->addTranslation(fromStateName,eventName,toStateName);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addTranslation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeTranslation of class  QFSM */
#ifndef TOLUA_DISABLE_tolua_game_QFSM_removeTranslation00
static int tolua_game_QFSM_removeTranslation00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"QFSM",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  QFSM* self = (QFSM*)  tolua_tousertype(tolua_S,1,0);
  std::string fromStateName = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  std::string eventName = ((std::string)  tolua_tocppstring(tolua_S,3,0));
  std::string toStateName = ((std::string)  tolua_tocppstring(tolua_S,4,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeTranslation'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->removeTranslation(fromStateName,eventName,toStateName);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeTranslation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: start of class  QFSM */
#ifndef TOLUA_DISABLE_tolua_game_QFSM_start00
static int tolua_game_QFSM_start00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"QFSM",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  QFSM* self = (QFSM*)  tolua_tousertype(tolua_S,1,0);
  std::string startStateName = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'start'", NULL);
#endif
  {
   self->start(startStateName);
  }
 }
 return 0;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'start'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: handle of class  QFSM */
#ifndef TOLUA_DISABLE_tolua_game_QFSM_handle00
static int tolua_game_QFSM_handle00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"QFSM",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  QFSM* self = (QFSM*)  tolua_tousertype(tolua_S,1,0);
  std::string eventName = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'handle'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->handle(eventName);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'handle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clear of class  QFSM */
#ifndef TOLUA_DISABLE_tolua_game_QFSM_clear00
static int tolua_game_QFSM_clear00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"QFSM",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  QFSM* self = (QFSM*)  tolua_tousertype(tolua_S,1,0);
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clear'", NULL);
#endif
  {
   self->clear();
  }
 }
 return 0;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clear'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: forceSwitch of class  QFSM */
#ifndef TOLUA_DISABLE_tolua_game_QFSM_forceSwitch00
static int tolua_game_QFSM_forceSwitch00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"QFSM",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  QFSM* self = (QFSM*)  tolua_tousertype(tolua_S,1,0);
  std::string startStateName = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'forceSwitch'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->forceSwitch(startStateName);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'forceSwitch'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPreState of class  QFSM */
#ifndef TOLUA_DISABLE_tolua_game_QFSM_getPreState00
static int tolua_game_QFSM_getPreState00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"QFSM",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  QFSM* self = (QFSM*)  tolua_tousertype(tolua_S,1,0);
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPreState'", NULL);
#endif
  {
   QFSMState* tolua_ret = (QFSMState*)  self->getPreState();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"QFSMState");
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPreState'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getNextState of class  QFSM */
#ifndef TOLUA_DISABLE_tolua_game_QFSM_getNextState00
static int tolua_game_QFSM_getNextState00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"QFSM",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  QFSM* self = (QFSM*)  tolua_tousertype(tolua_S,1,0);
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getNextState'", NULL);
#endif
  {
   QFSMState* tolua_ret = (QFSMState*)  self->getNextState();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"QFSMState");
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getNextState'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCurState of class  QFSM */
#ifndef TOLUA_DISABLE_tolua_game_QFSM_getCurState00
static int tolua_game_QFSM_getCurState00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"QFSM",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  QFSM* self = (QFSM*)  tolua_tousertype(tolua_S,1,0);
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCurState'", NULL);
#endif
  {
   QFSMState* tolua_ret = (QFSMState*)  self->getCurState();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"QFSMState");
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCurState'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCurEventName of class  QFSM */
#ifndef TOLUA_DISABLE_tolua_game_QFSM_getCurEventName00
static int tolua_game_QFSM_getCurEventName00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"QFSM",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  QFSM* self = (QFSM*)  tolua_tousertype(tolua_S,1,0);
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCurEventName'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->getCurEventName();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCurEventName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  GameActor */
#ifndef TOLUA_DISABLE_tolua_game_GameActor_create00
static int tolua_game_GameActor_create00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GameActor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   GameActor* tolua_ret = (GameActor*)  GameActor::create();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GameActor");
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  GameActor */
#ifndef TOLUA_DISABLE_tolua_game_GameActor_new00
static int tolua_game_GameActor_new00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GameActor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   GameActor* tolua_ret = (GameActor*)  Mtolua_new((GameActor)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GameActor");
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  GameActor */
#ifndef TOLUA_DISABLE_tolua_game_GameActor_new00_local
static int tolua_game_GameActor_new00_local(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GameActor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   GameActor* tolua_ret = (GameActor*)  Mtolua_new((GameActor)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GameActor");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  GameActor */
#ifndef TOLUA_DISABLE_tolua_game_GameActor_delete00
static int tolua_game_GameActor_delete00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameActor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameActor* self = (GameActor*)  tolua_tousertype(tolua_S,1,0);
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: init of class  GameActor */
#ifndef TOLUA_DISABLE_tolua_game_GameActor_init00
static int tolua_game_GameActor_init00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameActor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameActor* self = (GameActor*)  tolua_tousertype(tolua_S,1,0);
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getGameAttribute of class  GameActor */
#ifndef TOLUA_DISABLE_tolua_game_GameActor_getGameAttribute00
static int tolua_game_GameActor_getGameAttribute00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameActor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameActor* self = (GameActor*)  tolua_tousertype(tolua_S,1,0);
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getGameAttribute'", NULL);
#endif
  {
   GameAttribute* tolua_ret = (GameAttribute*)  self->getGameAttribute();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GameAttribute");
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getGameAttribute'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getFSM of class  GameActor */
#ifndef TOLUA_DISABLE_tolua_game_GameActor_getFSM00
static int tolua_game_GameActor_getFSM00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameActor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameActor* self = (GameActor*)  tolua_tousertype(tolua_S,1,0);
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFSM'", NULL);
#endif
  {
   QFSM* tolua_ret = (QFSM*)  self->getFSM();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"QFSM");
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getFSM'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getArmature of class  GameActor */
#ifndef TOLUA_DISABLE_tolua_game_GameActor_getArmature00
static int tolua_game_GameActor_getArmature00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameActor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameActor* self = (GameActor*)  tolua_tousertype(tolua_S,1,0);
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getArmature'", NULL);
#endif
  {
   Armature* tolua_ret = (Armature*)  self->getArmature();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ccs.Armature");
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getArmature'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getGameWord of class  GameActor */
#ifndef TOLUA_DISABLE_tolua_game_GameActor_getGameWord00
static int tolua_game_GameActor_getGameWord00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameActor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameActor* self = (GameActor*)  tolua_tousertype(tolua_S,1,0);
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getGameWord'", NULL);
#endif
  {
   GameWord* tolua_ret = (GameWord*)  self->getGameWord();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GameWord");
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getGameWord'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setOrientation of class  GameActor */
#ifndef TOLUA_DISABLE_tolua_game_GameActor_setOrientation00
static int tolua_game_GameActor_setOrientation00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameActor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameActor* self = (GameActor*)  tolua_tousertype(tolua_S,1,0);
  short ori = ((short)  tolua_tonumber(tolua_S,2,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setOrientation'", NULL);
#endif
  {
   self->setOrientation(ori);
  }
 }
 return 0;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setOrientation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getOrientation of class  GameActor */
#ifndef TOLUA_DISABLE_tolua_game_GameActor_getOrientation00
static int tolua_game_GameActor_getOrientation00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameActor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameActor* self = (GameActor*)  tolua_tousertype(tolua_S,1,0);
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getOrientation'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getOrientation();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getOrientation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: loadArmature of class  GameActor */
#ifndef TOLUA_DISABLE_tolua_game_GameActor_loadArmature00
static int tolua_game_GameActor_loadArmature00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameActor",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameActor* self = (GameActor*)  tolua_tousertype(tolua_S,1,0);
  const std::string filepath = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'loadArmature'", NULL);
#endif
  {
   self->loadArmature(filepath);
   tolua_pushcppstring(tolua_S,(const char*)filepath);
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'loadArmature'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getActorType of class  GameActor */
#ifndef TOLUA_DISABLE_tolua_game_GameActor_getActorType00
static int tolua_game_GameActor_getActorType00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameActor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameActor* self = (GameActor*)  tolua_tousertype(tolua_S,1,0);
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getActorType'", NULL);
#endif
  {
   GameActorType tolua_ret = (GameActorType)  self->getActorType();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getActorType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setActorType of class  GameActor */
#ifndef TOLUA_DISABLE_tolua_game_GameActor_setActorType00
static int tolua_game_GameActor_setActorType00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameActor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameActor* self = (GameActor*)  tolua_tousertype(tolua_S,1,0);
  GameActorType type = ((GameActorType) (int)  tolua_tonumber(tolua_S,2,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setActorType'", NULL);
#endif
  {
   self->setActorType(type);
  }
 }
 return 0;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setActorType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isRunAABB of class  GameActor */
#ifndef TOLUA_DISABLE_tolua_game_GameActor_isRunAABB00
static int tolua_game_GameActor_isRunAABB00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameActor",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GameActor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameActor* self = (GameActor*)  tolua_tousertype(tolua_S,1,0);
  GameActor* other = ((GameActor*)  tolua_tousertype(tolua_S,2,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isRunAABB'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isRunAABB(other);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isRunAABB'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: attLevelTest of class  GameActor */
#ifndef TOLUA_DISABLE_tolua_game_GameActor_attLevelTest00
static int tolua_game_GameActor_attLevelTest00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameActor",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GameActor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameActor* self = (GameActor*)  tolua_tousertype(tolua_S,1,0);
  GameActor* other = ((GameActor*)  tolua_tousertype(tolua_S,2,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'attLevelTest'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->attLevelTest(other);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'attLevelTest'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AABBCallback of class  GameActor */
#ifndef TOLUA_DISABLE_tolua_game_GameActor_AABBCallback00
static int tolua_game_GameActor_AABBCallback00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameActor",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GameActor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameActor* self = (GameActor*)  tolua_tousertype(tolua_S,1,0);
  GameActor* other = ((GameActor*)  tolua_tousertype(tolua_S,2,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AABBCallback'", NULL);
#endif
  {
   self->AABBCallback(other);
  }
 }
 return 0;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AABBCallback'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: attOtherActorCallback of class  GameActor */
#ifndef TOLUA_DISABLE_tolua_game_GameActor_attOtherActorCallback00
static int tolua_game_GameActor_attOtherActorCallback00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameActor",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GameActor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameActor* self = (GameActor*)  tolua_tousertype(tolua_S,1,0);
  GameActor* other = ((GameActor*)  tolua_tousertype(tolua_S,2,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'attOtherActorCallback'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->attOtherActorCallback(other);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'attOtherActorCallback'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: lockOrientation of class  GameActor */
#ifndef TOLUA_DISABLE_tolua_game_GameActor_lockOrientation00
static int tolua_game_GameActor_lockOrientation00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameActor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameActor* self = (GameActor*)  tolua_tousertype(tolua_S,1,0);
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'lockOrientation'", NULL);
#endif
  {
   self->lockOrientation();
  }
 }
 return 0;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'lockOrientation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: unLockOrientation of class  GameActor */
#ifndef TOLUA_DISABLE_tolua_game_GameActor_unLockOrientation00
static int tolua_game_GameActor_unLockOrientation00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameActor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameActor* self = (GameActor*)  tolua_tousertype(tolua_S,1,0);
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'unLockOrientation'", NULL);
#endif
  {
   self->unLockOrientation();
  }
 }
 return 0;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'unLockOrientation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isLockOrientation of class  GameActor */
#ifndef TOLUA_DISABLE_tolua_game_GameActor_isLockOrientation00
static int tolua_game_GameActor_isLockOrientation00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameActor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameActor* self = (GameActor*)  tolua_tousertype(tolua_S,1,0);
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isLockOrientation'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isLockOrientation();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isLockOrientation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setMapConstraintEnable of class  GameActor */
#ifndef TOLUA_DISABLE_tolua_game_GameActor_setMapConstraintEnable00
static int tolua_game_GameActor_setMapConstraintEnable00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameActor",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameActor* self = (GameActor*)  tolua_tousertype(tolua_S,1,0);
  bool InEnable = ((bool)  tolua_toboolean(tolua_S,2,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setMapConstraintEnable'", NULL);
#endif
  {
   self->setMapConstraintEnable(InEnable);
  }
 }
 return 0;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setMapConstraintEnable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isEnableMapConstraint of class  GameActor */
#ifndef TOLUA_DISABLE_tolua_game_GameActor_isEnableMapConstraint00
static int tolua_game_GameActor_isEnableMapConstraint00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameActor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameActor* self = (GameActor*)  tolua_tousertype(tolua_S,1,0);
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isEnableMapConstraint'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isEnableMapConstraint();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isEnableMapConstraint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: registerLuaHandle of class  GameActor */
#ifndef TOLUA_DISABLE_tolua_game_GameActor_registerLuaHandle00
static int tolua_game_GameActor_registerLuaHandle00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameActor",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !toluafix_isfunction(tolua_S,3,"LuaFunction",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameActor* self = (GameActor*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  LuaFunction handle = (  LuaFunction(tolua_S,3,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'registerLuaHandle'", NULL);
#endif
  {
   self->registerLuaHandle(name,handle);
   tolua_pushcppstring(tolua_S,(const char*)name);
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'registerLuaHandle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: unregisterLuaHandle of class  GameActor */
#ifndef TOLUA_DISABLE_tolua_game_GameActor_unregisterLuaHandle00
static int tolua_game_GameActor_unregisterLuaHandle00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameActor",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameActor* self = (GameActor*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'unregisterLuaHandle'", NULL);
#endif
  {
   self->unregisterLuaHandle(name);
   tolua_pushcppstring(tolua_S,(const char*)name);
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'unregisterLuaHandle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isIgnoreBodyRotation of class  GameActor */
#ifndef TOLUA_DISABLE_tolua_game_GameActor_isIgnoreBodyRotation00
static int tolua_game_GameActor_isIgnoreBodyRotation00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameActor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameActor* self = (GameActor*)  tolua_tousertype(tolua_S,1,0);
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isIgnoreBodyRotation'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isIgnoreBodyRotation();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isIgnoreBodyRotation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setIgnoreBodyRotation of class  GameActor */
#ifndef TOLUA_DISABLE_tolua_game_GameActor_setIgnoreBodyRotation00
static int tolua_game_GameActor_setIgnoreBodyRotation00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameActor",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameActor* self = (GameActor*)  tolua_tousertype(tolua_S,1,0);
  bool bIgnoreBodyRotation = ((bool)  tolua_toboolean(tolua_S,2,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setIgnoreBodyRotation'", NULL);
#endif
  {
   self->setIgnoreBodyRotation(bIgnoreBodyRotation);
  }
 }
 return 0;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setIgnoreBodyRotation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getB2Body of class  GameActor */
#ifndef TOLUA_DISABLE_tolua_game_GameActor_getB2Body00
static int tolua_game_GameActor_getB2Body00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameActor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameActor* self = (GameActor*)  tolua_tousertype(tolua_S,1,0);
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getB2Body'", NULL);
#endif
  {
   b2Body* tolua_ret = (b2Body*)  self->getB2Body();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"b2Body");
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getB2Body'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setB2Body of class  GameActor */
#ifndef TOLUA_DISABLE_tolua_game_GameActor_setB2Body00
static int tolua_game_GameActor_setB2Body00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameActor",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"b2Body",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameActor* self = (GameActor*)  tolua_tousertype(tolua_S,1,0);
  b2Body* pBody = ((b2Body*)  tolua_tousertype(tolua_S,2,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setB2Body'", NULL);
#endif
  {
   self->setB2Body(pBody);
  }
 }
 return 0;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setB2Body'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPTMRatio of class  GameActor */
#ifndef TOLUA_DISABLE_tolua_game_GameActor_getPTMRatio00
static int tolua_game_GameActor_getPTMRatio00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameActor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameActor* self = (GameActor*)  tolua_tousertype(tolua_S,1,0);
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPTMRatio'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getPTMRatio();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPTMRatio'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPTMRatio of class  GameActor */
#ifndef TOLUA_DISABLE_tolua_game_GameActor_setPTMRatio00
static int tolua_game_GameActor_setPTMRatio00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameActor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameActor* self = (GameActor*)  tolua_tousertype(tolua_S,1,0);
  float fPTMRatio = ((float)  tolua_tonumber(tolua_S,2,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPTMRatio'", NULL);
#endif
  {
   self->setPTMRatio(fPTMRatio);
  }
 }
 return 0;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPTMRatio'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: syncPhysicsTransform of class  GameActor */
#ifndef TOLUA_DISABLE_tolua_game_GameActor_syncPhysicsTransform00
static int tolua_game_GameActor_syncPhysicsTransform00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameActor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameActor* self = (GameActor*)  tolua_tousertype(tolua_S,1,0);
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'syncPhysicsTransform'", NULL);
#endif
  {
   self->syncPhysicsTransform();
  }
 }
 return 0;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'syncPhysicsTransform'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  GameAttribute */
#ifndef TOLUA_DISABLE_tolua_game_GameAttribute_new00
static int tolua_game_GameAttribute_new00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GameAttribute",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   GameAttribute* tolua_ret = (GameAttribute*)  Mtolua_new((GameAttribute)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GameAttribute");
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  GameAttribute */
#ifndef TOLUA_DISABLE_tolua_game_GameAttribute_new00_local
static int tolua_game_GameAttribute_new00_local(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GameAttribute",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   GameAttribute* tolua_ret = (GameAttribute*)  Mtolua_new((GameAttribute)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GameAttribute");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setHP of class  GameAttribute */
#ifndef TOLUA_DISABLE_tolua_game_GameAttribute_setHP00
static int tolua_game_GameAttribute_setHP00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameAttribute",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameAttribute* self = (GameAttribute*)  tolua_tousertype(tolua_S,1,0);
  int value = ((int)  tolua_tonumber(tolua_S,2,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setHP'", NULL);
#endif
  {
   self->setHP(value);
  }
 }
 return 0;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setHP'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getHP of class  GameAttribute */
#ifndef TOLUA_DISABLE_tolua_game_GameAttribute_getHP00
static int tolua_game_GameAttribute_getHP00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameAttribute",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameAttribute* self = (GameAttribute*)  tolua_tousertype(tolua_S,1,0);
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getHP'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getHP();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getHP'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAtt of class  GameAttribute */
#ifndef TOLUA_DISABLE_tolua_game_GameAttribute_setAtt00
static int tolua_game_GameAttribute_setAtt00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameAttribute",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameAttribute* self = (GameAttribute*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAtt'", NULL);
#endif
  {
   self->setAtt(value);
  }
 }
 return 0;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAtt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAtt of class  GameAttribute */
#ifndef TOLUA_DISABLE_tolua_game_GameAttribute_getAtt00
static int tolua_game_GameAttribute_getAtt00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameAttribute",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameAttribute* self = (GameAttribute*)  tolua_tousertype(tolua_S,1,0);
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAtt'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getAtt();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAtt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setDef of class  GameAttribute */
#ifndef TOLUA_DISABLE_tolua_game_GameAttribute_setDef00
static int tolua_game_GameAttribute_setDef00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameAttribute",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameAttribute* self = (GameAttribute*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDef'", NULL);
#endif
  {
   self->setDef(value);
  }
 }
 return 0;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDef'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDef of class  GameAttribute */
#ifndef TOLUA_DISABLE_tolua_game_GameAttribute_getDef00
static int tolua_game_GameAttribute_getDef00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameAttribute",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameAttribute* self = (GameAttribute*)  tolua_tousertype(tolua_S,1,0);
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDef'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getDef();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDef'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  GameMap */
#ifndef TOLUA_DISABLE_tolua_game_GameMap_create00
static int tolua_game_GameMap_create00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GameMap",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   GameMap* tolua_ret = (GameMap*)  GameMap::create();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GameMap");
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: loadMapFile of class  GameMap */
#ifndef TOLUA_DISABLE_tolua_game_GameMap_loadMapFile00
static int tolua_game_GameMap_loadMapFile00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameMap",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameMap* self = (GameMap*)  tolua_tousertype(tolua_S,1,0);
  const std::string filepath = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string actorNodeName = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  const std::string fixNodeName = ((const std::string)  tolua_tocppstring(tolua_S,4,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'loadMapFile'", NULL);
#endif
  {
   self->loadMapFile(filepath,actorNodeName,fixNodeName);
   tolua_pushcppstring(tolua_S,(const char*)filepath);
   tolua_pushcppstring(tolua_S,(const char*)actorNodeName);
   tolua_pushcppstring(tolua_S,(const char*)fixNodeName);
  }
 }
 return 3;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'loadMapFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setViewPos of class  GameMap */
#ifndef TOLUA_DISABLE_tolua_game_GameMap_setViewPos00
static int tolua_game_GameMap_setViewPos00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameMap",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameMap* self = (GameMap*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setViewPos'", NULL);
#endif
  {
   self->setViewPos(x,y);
  }
 }
 return 0;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setViewPos'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setViewSize of class  GameMap */
#ifndef TOLUA_DISABLE_tolua_game_GameMap_setViewSize00
static int tolua_game_GameMap_setViewSize00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameMap",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameMap* self = (GameMap*)  tolua_tousertype(tolua_S,1,0);
  float width = ((float)  tolua_tonumber(tolua_S,2,0));
  float height = ((float)  tolua_tonumber(tolua_S,3,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setViewSize'", NULL);
#endif
  {
   self->setViewSize(width,height);
  }
 }
 return 0;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setViewSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getActorNode of class  GameMap */
#ifndef TOLUA_DISABLE_tolua_game_GameMap_getActorNode00
static int tolua_game_GameMap_getActorNode00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameMap",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameMap* self = (GameMap*)  tolua_tousertype(tolua_S,1,0);
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getActorNode'", NULL);
#endif
  {
   Node* tolua_ret = (Node*)  self->getActorNode();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Node");
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getActorNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: lockMapY of class  GameMap */
#ifndef TOLUA_DISABLE_tolua_game_GameMap_lockMapY00
static int tolua_game_GameMap_lockMapY00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameMap",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameMap* self = (GameMap*)  tolua_tousertype(tolua_S,1,0);
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'lockMapY'", NULL);
#endif
  {
   self->lockMapY();
  }
 }
 return 0;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'lockMapY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: unlockMapY of class  GameMap */
#ifndef TOLUA_DISABLE_tolua_game_GameMap_unlockMapY00
static int tolua_game_GameMap_unlockMapY00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameMap",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameMap* self = (GameMap*)  tolua_tousertype(tolua_S,1,0);
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'unlockMapY'", NULL);
#endif
  {
   self->unlockMapY();
  }
 }
 return 0;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'unlockMapY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getMapWidth of class  GameMap */
#ifndef TOLUA_DISABLE_tolua_game_GameMap_getMapWidth00
static int tolua_game_GameMap_getMapWidth00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameMap",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameMap* self = (GameMap*)  tolua_tousertype(tolua_S,1,0);
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMapWidth'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getMapWidth();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMapWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getMapHeight of class  GameMap */
#ifndef TOLUA_DISABLE_tolua_game_GameMap_getMapHeight00
static int tolua_game_GameMap_getMapHeight00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameMap",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameMap* self = (GameMap*)  tolua_tousertype(tolua_S,1,0);
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMapHeight'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getMapHeight();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMapHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  GameWord */
#ifndef TOLUA_DISABLE_tolua_game_GameWord_create00
static int tolua_game_GameWord_create00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GameWord",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   GameWord* tolua_ret = (GameWord*)  GameWord::create();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GameWord");
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setGameMap of class  GameWord */
#ifndef TOLUA_DISABLE_tolua_game_GameWord_setGameMap00
static int tolua_game_GameWord_setGameMap00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameWord",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GameMap",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameWord* self = (GameWord*)  tolua_tousertype(tolua_S,1,0);
  GameMap* map = ((GameMap*)  tolua_tousertype(tolua_S,2,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setGameMap'", NULL);
#endif
  {
   self->setGameMap(map);
  }
 }
 return 0;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setGameMap'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getGameMap of class  GameWord */
#ifndef TOLUA_DISABLE_tolua_game_GameWord_getGameMap00
static int tolua_game_GameWord_getGameMap00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameWord",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameWord* self = (GameWord*)  tolua_tousertype(tolua_S,1,0);
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getGameMap'", NULL);
#endif
  {
   GameMap* tolua_ret = (GameMap*)  self->getGameMap();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GameMap");
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getGameMap'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addActor of class  GameWord */
#ifndef TOLUA_DISABLE_tolua_game_GameWord_addActor00
static int tolua_game_GameWord_addActor00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameWord",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GameActor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameWord* self = (GameWord*)  tolua_tousertype(tolua_S,1,0);
  GameActor* actor = ((GameActor*)  tolua_tousertype(tolua_S,2,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addActor'", NULL);
#endif
  {
   self->addActor(actor);
  }
 }
 return 0;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addActor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeActor of class  GameWord */
#ifndef TOLUA_DISABLE_tolua_game_GameWord_removeActor00
static int tolua_game_GameWord_removeActor00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameWord",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GameActor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameWord* self = (GameWord*)  tolua_tousertype(tolua_S,1,0);
  GameActor* actor = ((GameActor*)  tolua_tousertype(tolua_S,2,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeActor'", NULL);
#endif
  {
   self->removeActor(actor);
  }
 }
 return 0;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeActor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setLocalPlayer of class  GameWord */
#ifndef TOLUA_DISABLE_tolua_game_GameWord_setLocalPlayer00
static int tolua_game_GameWord_setLocalPlayer00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameWord",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GameActor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameWord* self = (GameWord*)  tolua_tousertype(tolua_S,1,0);
  GameActor* player = ((GameActor*)  tolua_tousertype(tolua_S,2,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setLocalPlayer'", NULL);
#endif
  {
   self->setLocalPlayer(player);
  }
 }
 return 0;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setLocalPlayer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLocalPlayer of class  GameWord */
#ifndef TOLUA_DISABLE_tolua_game_GameWord_getLocalPlayer00
static int tolua_game_GameWord_getLocalPlayer00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameWord",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameWord* self = (GameWord*)  tolua_tousertype(tolua_S,1,0);
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLocalPlayer'", NULL);
#endif
  {
   GameActor* tolua_ret = (GameActor*)  self->getLocalPlayer();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GameActor");
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLocalPlayer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPlayerCount of class  GameWord */
#ifndef TOLUA_DISABLE_tolua_game_GameWord_getPlayerCount00
static int tolua_game_GameWord_getPlayerCount00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameWord",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameWord* self = (GameWord*)  tolua_tousertype(tolua_S,1,0);
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPlayerCount'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getPlayerCount();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPlayerCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPlayerByIndex of class  GameWord */
#ifndef TOLUA_DISABLE_tolua_game_GameWord_getPlayerByIndex00
static int tolua_game_GameWord_getPlayerByIndex00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameWord",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameWord* self = (GameWord*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPlayerByIndex'", NULL);
#endif
  {
   GameActor* tolua_ret = (GameActor*)  self->getPlayerByIndex(index);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GameActor");
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPlayerByIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeActorByName of class  GameWord */
#ifndef TOLUA_DISABLE_tolua_game_GameWord_removeActorByName00
static int tolua_game_GameWord_removeActorByName00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameWord",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameWord* self = (GameWord*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeActorByName'", NULL);
#endif
  {
   self->removeActorByName(name);
   tolua_pushcppstring(tolua_S,(const char*)name);
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeActorByName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: logicUpdate of class  GameWord */
#ifndef TOLUA_DISABLE_tolua_game_GameWord_logicUpdate00
static int tolua_game_GameWord_logicUpdate00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameWord",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameWord* self = (GameWord*)  tolua_tousertype(tolua_S,1,0);
  float d = ((float)  tolua_tonumber(tolua_S,2,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'logicUpdate'", NULL);
#endif
  {
   self->logicUpdate(d);
  }
 }
 return 0;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'logicUpdate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: openDebugDraw of class  GameWord */
#ifndef TOLUA_DISABLE_tolua_game_GameWord_openDebugDraw00
static int tolua_game_GameWord_openDebugDraw00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameWord",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameWord* self = (GameWord*)  tolua_tousertype(tolua_S,1,0);
  bool open = ((bool)  tolua_toboolean(tolua_S,2,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'openDebugDraw'", NULL);
#endif
  {
   self->openDebugDraw(open);
  }
 }
 return 0;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'openDebugDraw'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isOpenDebugDraw of class  GameWord */
#ifndef TOLUA_DISABLE_tolua_game_GameWord_isOpenDebugDraw00
static int tolua_game_GameWord_isOpenDebugDraw00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameWord",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameWord* self = (GameWord*)  tolua_tousertype(tolua_S,1,0);
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isOpenDebugDraw'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isOpenDebugDraw();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isOpenDebugDraw'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getActorNode of class  GameWord */
#ifndef TOLUA_DISABLE_tolua_game_GameWord_getActorNode00
static int tolua_game_GameWord_getActorNode00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameWord",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameWord* self = (GameWord*)  tolua_tousertype(tolua_S,1,0);
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getActorNode'", NULL);
#endif
  {
   Node* tolua_ret = (Node*)  self->getActorNode();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"cc.Node");
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getActorNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getChildNode of class  GameWord */
#ifndef TOLUA_DISABLE_tolua_game_GameWord_getChildNode00
static int tolua_game_GameWord_getChildNode00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameWord",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameWord* self = (GameWord*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getChildNode'", NULL);
#endif
  {
   Node* tolua_ret = (Node*)  self->getChildNode(name);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"cc.Node");
   tolua_pushcppstring(tolua_S,(const char*)name);
  }
 }
 return 2;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getChildNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: updateActors of class  GameWord */
#ifndef TOLUA_DISABLE_tolua_game_GameWord_updateActors00
static int tolua_game_GameWord_updateActors00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameWord",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameWord* self = (GameWord*)  tolua_tousertype(tolua_S,1,0);
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'updateActors'", NULL);
#endif
  {
   self->updateActors();
  }
 }
 return 0;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'updateActors'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setViewPortMinXValue of class  GameWord */
#ifndef TOLUA_DISABLE_tolua_game_GameWord_setViewPortMinXValue00
static int tolua_game_GameWord_setViewPortMinXValue00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameWord",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameWord* self = (GameWord*)  tolua_tousertype(tolua_S,1,0);
  float InValue = ((float)  tolua_tonumber(tolua_S,2,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setViewPortMinXValue'", NULL);
#endif
  {
   self->setViewPortMinXValue(InValue);
  }
 }
 return 0;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setViewPortMinXValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getViewPortMinXValue of class  GameWord */
#ifndef TOLUA_DISABLE_tolua_game_GameWord_getViewPortMinXValue00
static int tolua_game_GameWord_getViewPortMinXValue00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameWord",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameWord* self = (GameWord*)  tolua_tousertype(tolua_S,1,0);
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getViewPortMinXValue'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getViewPortMinXValue();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getViewPortMinXValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setViewPortMaxXValue of class  GameWord */
#ifndef TOLUA_DISABLE_tolua_game_GameWord_setViewPortMaxXValue00
static int tolua_game_GameWord_setViewPortMaxXValue00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameWord",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameWord* self = (GameWord*)  tolua_tousertype(tolua_S,1,0);
  float InValue = ((float)  tolua_tonumber(tolua_S,2,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setViewPortMaxXValue'", NULL);
#endif
  {
   self->setViewPortMaxXValue(InValue);
  }
 }
 return 0;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setViewPortMaxXValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getViewPortMaxXValue of class  GameWord */
#ifndef TOLUA_DISABLE_tolua_game_GameWord_getViewPortMaxXValue00
static int tolua_game_GameWord_getViewPortMaxXValue00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameWord",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameWord* self = (GameWord*)  tolua_tousertype(tolua_S,1,0);
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getViewPortMaxXValue'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getViewPortMaxXValue();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getViewPortMaxXValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setMinPosY of class  GameWord */
#ifndef TOLUA_DISABLE_tolua_game_GameWord_setMinPosY00
static int tolua_game_GameWord_setMinPosY00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameWord",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameWord* self = (GameWord*)  tolua_tousertype(tolua_S,1,0);
  float minPosY = ((float)  tolua_tonumber(tolua_S,2,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setMinPosY'", NULL);
#endif
  {
   self->setMinPosY(minPosY);
  }
 }
 return 0;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setMinPosY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: getGameWord */
#ifndef TOLUA_DISABLE_tolua_game_getGameWord00
static int tolua_game_getGameWord00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   GameWord* tolua_ret = (GameWord*)  getGameWord();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GameWord");
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getGameWord'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: changeParticleSystemPositionType */
#ifndef TOLUA_DISABLE_tolua_game_changeParticleSystemPositionType00
static int tolua_game_changeParticleSystemPositionType00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"cc.Node",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Node* root = ((Node*)  tolua_tousertype(tolua_S,1,0));
  {
   changeParticleSystemPositionType(root);
  }
 }
 return 0;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'changeParticleSystemPositionType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getInstance of class  Client */
#ifndef TOLUA_DISABLE_tolua_game_Client_getInstance00
static int tolua_game_Client_getInstance00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Client",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Client* tolua_ret = (Client*)  Client::getInstance();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Client");
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInstance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: destroy of class  Client */
#ifndef TOLUA_DISABLE_tolua_game_Client_destroy00
static int tolua_game_Client_destroy00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Client",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Client::destroy();
  }
 }
 return 0;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'destroy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setCallFunc of class  Client */
#ifndef TOLUA_DISABLE_tolua_game_Client_setCallFunc00
static int tolua_game_Client_setCallFunc00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Client",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !toluafix_isfunction(tolua_S,2,"LuaFunction",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Client* self = (Client*)  tolua_tousertype(tolua_S,1,0);
  LuaFunction handle = (  LuaFunction(tolua_S,2,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setCallFunc'", NULL);
#endif
  {
   self->setCallFunc(handle);
  }
 }
 return 0;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setCallFunc'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: connect of class  Client */
#ifndef TOLUA_DISABLE_tolua_game_Client_connect00
static int tolua_game_Client_connect00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Client",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Client* self = (Client*)  tolua_tousertype(tolua_S,1,0);
  const char* ip = ((const char*)  tolua_tostring(tolua_S,2,0));
  int port = ((int)  tolua_tonumber(tolua_S,3,0));
  unsigned int key = ((unsigned int)  tolua_tonumber(tolua_S,4,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'connect'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->connect(ip,port,key);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'connect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: disconnect of class  Client */
#ifndef TOLUA_DISABLE_tolua_game_Client_disconnect00
static int tolua_game_Client_disconnect00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Client",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Client* self = (Client*)  tolua_tousertype(tolua_S,1,0);
  unsigned int key = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'disconnect'", NULL);
#endif
  {
   self->disconnect(key);
  }
 }
 return 0;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'disconnect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: closeClient of class  Client */
#ifndef TOLUA_DISABLE_tolua_game_Client_closeClient00
static int tolua_game_Client_closeClient00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Client",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Client* self = (Client*)  tolua_tousertype(tolua_S,1,0);
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'closeClient'", NULL);
#endif
  {
   self->closeClient();
  }
 }
 return 0;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'closeClient'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isCloseFinish of class  Client */
#ifndef TOLUA_DISABLE_tolua_game_Client_isCloseFinish00
static int tolua_game_Client_isCloseFinish00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Client",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Client* self = (Client*)  tolua_tousertype(tolua_S,1,0);
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isCloseFinish'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isCloseFinish();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isCloseFinish'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: send of class  Client */
#ifndef TOLUA_DISABLE_tolua_game_Client_send00
static int tolua_game_Client_send00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Client",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Client* self = (Client*)  tolua_tousertype(tolua_S,1,0);
  unsigned int key = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
  char* data = ((char*)  tolua_tostring(tolua_S,3,0));
  unsigned int len = ((unsigned int)  tolua_tonumber(tolua_S,4,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'send'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->send(key,data,len);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'send'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: send of class  Client */
#ifndef TOLUA_DISABLE_tolua_game_Client_send01
static int tolua_game_Client_send01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Client",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Client* self = (Client*)  tolua_tousertype(tolua_S,1,0);
  unsigned int key = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
  char* data = ((char*)  tolua_tostring(tolua_S,3,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'send'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->send(key,data);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_game_Client_send00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: setNoDelay of class  Client */
#ifndef TOLUA_DISABLE_tolua_game_Client_setNoDelay00
static int tolua_game_Client_setNoDelay00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Client",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Client* self = (Client*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setNoDelay'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->setNoDelay(enable);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setNoDelay'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setKeepAlive of class  Client */
#ifndef TOLUA_DISABLE_tolua_game_Client_setKeepAlive00
static int tolua_game_Client_setKeepAlive00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Client",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Client* self = (Client*)  tolua_tousertype(tolua_S,1,0);
  int enable = ((int)  tolua_tonumber(tolua_S,2,0));
  unsigned int delay = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setKeepAlive'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->setKeepAlive(enable,delay);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setKeepAlive'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: checkState of class  Client */
#ifndef TOLUA_DISABLE_tolua_game_Client_checkState00
static int tolua_game_Client_checkState00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Client",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Client* self = (Client*)  tolua_tousertype(tolua_S,1,0);
  unsigned int key = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'checkState'", NULL);
#endif
  {
   TCPClient::CONNECTSTATE tolua_ret = (TCPClient::CONNECTSTATE)  self->checkState(key);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'checkState'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: checkState of class  Client */
#ifndef TOLUA_DISABLE_tolua_game_Client_checkState01
static int tolua_game_Client_checkState01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Client",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Client* self = (Client*)  tolua_tousertype(tolua_S,1,0);
  const char* ip = ((const char*)  tolua_tostring(tolua_S,2,0));
  unsigned int port = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'checkState'", NULL);
#endif
  {
   TCPClient::CONNECTSTATE tolua_ret = (TCPClient::CONNECTSTATE)  self->checkState(ip,port);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_game_Client_checkState00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAutoReconnect of class  Client */
#ifndef TOLUA_DISABLE_tolua_game_Client_setAutoReconnect00
static int tolua_game_Client_setAutoReconnect00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Client",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Client* self = (Client*)  tolua_tousertype(tolua_S,1,0);
  bool isAuto = ((bool)  tolua_toboolean(tolua_S,2,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAutoReconnect'", NULL);
#endif
  {
   self->setAutoReconnect(isAuto);
  }
 }
 return 0;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAutoReconnect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAutoReconnectTime of class  Client */
#ifndef TOLUA_DISABLE_tolua_game_Client_setAutoReconnectTime00
static int tolua_game_Client_setAutoReconnectTime00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Client",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Client* self = (Client*)  tolua_tousertype(tolua_S,1,0);
  float time = ((float)  tolua_tonumber(tolua_S,2,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAutoReconnectTime'", NULL);
#endif
  {
   self->setAutoReconnectTime(time);
  }
 }
 return 0;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAutoReconnectTime'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAutoReconnectByKey of class  Client */
#ifndef TOLUA_DISABLE_tolua_game_Client_setAutoReconnectByKey00
static int tolua_game_Client_setAutoReconnectByKey00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Client",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Client* self = (Client*)  tolua_tousertype(tolua_S,1,0);
  unsigned int key = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
  bool isAuto = ((bool)  tolua_toboolean(tolua_S,3,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAutoReconnectByKey'", NULL);
#endif
  {
   self->setAutoReconnectByKey(key,isAuto);
  }
 }
 return 0;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAutoReconnectByKey'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAutoReconnectTimeByKey of class  Client */
#ifndef TOLUA_DISABLE_tolua_game_Client_setAutoReconnectTimeByKey00
static int tolua_game_Client_setAutoReconnectTimeByKey00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Client",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Client* self = (Client*)  tolua_tousertype(tolua_S,1,0);
  unsigned int key = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
  float time = ((float)  tolua_tonumber(tolua_S,3,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAutoReconnectTimeByKey'", NULL);
#endif
  {
   self->setAutoReconnectTimeByKey(key,time);
  }
 }
 return 0;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAutoReconnectTimeByKey'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTransform of class  b2Body */
#ifndef TOLUA_DISABLE_tolua_game_b2Body_SetTransform00
static int tolua_game_b2Body_SetTransform00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"b2Body",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"b2Vec2",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  b2Body* self = (b2Body*)  tolua_tousertype(tolua_S,1,0);
  b2Vec2 position = (  tolua_ext_luaval_to_b2vec2(tolua_S,2,0));
  float angle = ((float)  tolua_tonumber(tolua_S,3,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTransform'", NULL);
#endif
  {
   self->SetTransform(position,angle);
  }
 }
 return 0;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTransform'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPosition of class  b2Body */
#ifndef TOLUA_DISABLE_tolua_game_b2Body_GetPosition00
static int tolua_game_b2Body_GetPosition00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"b2Body",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  b2Body* self = (b2Body*)  tolua_tousertype(tolua_S,1,0);
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPosition'", NULL);
#endif
  {
   b2Vec2 tolua_ret = (b2Vec2)  self->GetPosition();
    tolua_ext_b2vec2_to_luaval(tolua_S, tolua_ret);
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAngle of class  b2Body */
#ifndef TOLUA_DISABLE_tolua_game_b2Body_GetAngle00
static int tolua_game_b2Body_GetAngle00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"b2Body",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  b2Body* self = (b2Body*)  tolua_tousertype(tolua_S,1,0);
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAngle'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetAngle();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAngle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWorldCenter of class  b2Body */
#ifndef TOLUA_DISABLE_tolua_game_b2Body_GetWorldCenter00
static int tolua_game_b2Body_GetWorldCenter00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"b2Body",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  b2Body* self = (b2Body*)  tolua_tousertype(tolua_S,1,0);
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWorldCenter'", NULL);
#endif
  {
   b2Vec2 tolua_ret = (b2Vec2)  self->GetWorldCenter();
    tolua_ext_b2vec2_to_luaval(tolua_S, tolua_ret);
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWorldCenter'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetLocalCenter of class  b2Body */
#ifndef TOLUA_DISABLE_tolua_game_b2Body_GetLocalCenter00
static int tolua_game_b2Body_GetLocalCenter00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"b2Body",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  b2Body* self = (b2Body*)  tolua_tousertype(tolua_S,1,0);
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetLocalCenter'", NULL);
#endif
  {
   b2Vec2 tolua_ret = (b2Vec2)  self->GetLocalCenter();
    tolua_ext_b2vec2_to_luaval(tolua_S, tolua_ret);
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLocalCenter'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetLinearVelocity of class  b2Body */
#ifndef TOLUA_DISABLE_tolua_game_b2Body_SetLinearVelocity00
static int tolua_game_b2Body_SetLinearVelocity00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"b2Body",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"b2Vec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  b2Body* self = (b2Body*)  tolua_tousertype(tolua_S,1,0);
  b2Vec2 v = (  tolua_ext_luaval_to_b2vec2(tolua_S,2,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetLinearVelocity'", NULL);
#endif
  {
   self->SetLinearVelocity(v);
  }
 }
 return 0;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetLinearVelocity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetLinearVelocity of class  b2Body */
#ifndef TOLUA_DISABLE_tolua_game_b2Body_GetLinearVelocity00
static int tolua_game_b2Body_GetLinearVelocity00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"b2Body",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  b2Body* self = (b2Body*)  tolua_tousertype(tolua_S,1,0);
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetLinearVelocity'", NULL);
#endif
  {
   b2Vec2 tolua_ret = (b2Vec2)  self->GetLinearVelocity();
    tolua_ext_b2vec2_to_luaval(tolua_S, tolua_ret);
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLinearVelocity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAngularVelocity of class  b2Body */
#ifndef TOLUA_DISABLE_tolua_game_b2Body_SetAngularVelocity00
static int tolua_game_b2Body_SetAngularVelocity00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"b2Body",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  b2Body* self = (b2Body*)  tolua_tousertype(tolua_S,1,0);
  float omega = ((float)  tolua_tonumber(tolua_S,2,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAngularVelocity'", NULL);
#endif
  {
   self->SetAngularVelocity(omega);
  }
 }
 return 0;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAngularVelocity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAngularVelocity of class  b2Body */
#ifndef TOLUA_DISABLE_tolua_game_b2Body_GetAngularVelocity00
static int tolua_game_b2Body_GetAngularVelocity00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"b2Body",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  b2Body* self = (b2Body*)  tolua_tousertype(tolua_S,1,0);
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAngularVelocity'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetAngularVelocity();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAngularVelocity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ApplyForce of class  b2Body */
#ifndef TOLUA_DISABLE_tolua_game_b2Body_ApplyForce00
static int tolua_game_b2Body_ApplyForce00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"b2Body",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"b2Vec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_ext_check_is_table(tolua_S,3,"b2Vec2",0,&tolua_err)) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  b2Body* self = (b2Body*)  tolua_tousertype(tolua_S,1,0);
  b2Vec2 force = (  tolua_ext_luaval_to_b2vec2(tolua_S,2,0));
  b2Vec2 point = (  tolua_ext_luaval_to_b2vec2(tolua_S,3,0));
  bool wake = ((bool)  tolua_toboolean(tolua_S,4,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ApplyForce'", NULL);
#endif
  {
   self->ApplyForce(force,point,wake);
  }
 }
 return 0;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ApplyForce'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ApplyForceToCenter of class  b2Body */
#ifndef TOLUA_DISABLE_tolua_game_b2Body_ApplyForceToCenter00
static int tolua_game_b2Body_ApplyForceToCenter00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"b2Body",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"b2Vec2",0,&tolua_err)) ||
     !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  b2Body* self = (b2Body*)  tolua_tousertype(tolua_S,1,0);
  b2Vec2 force = (  tolua_ext_luaval_to_b2vec2(tolua_S,2,0));
  bool wake = ((bool)  tolua_toboolean(tolua_S,3,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ApplyForceToCenter'", NULL);
#endif
  {
   self->ApplyForceToCenter(force,wake);
  }
 }
 return 0;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ApplyForceToCenter'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ApplyTorque of class  b2Body */
#ifndef TOLUA_DISABLE_tolua_game_b2Body_ApplyTorque00
static int tolua_game_b2Body_ApplyTorque00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"b2Body",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  b2Body* self = (b2Body*)  tolua_tousertype(tolua_S,1,0);
  float torque = ((float)  tolua_tonumber(tolua_S,2,0));
  bool wake = ((bool)  tolua_toboolean(tolua_S,3,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ApplyTorque'", NULL);
#endif
  {
   self->ApplyTorque(torque,wake);
  }
 }
 return 0;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ApplyTorque'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ApplyLinearImpulse of class  b2Body */
#ifndef TOLUA_DISABLE_tolua_game_b2Body_ApplyLinearImpulse00
static int tolua_game_b2Body_ApplyLinearImpulse00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"b2Body",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"b2Vec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_ext_check_is_table(tolua_S,3,"b2Vec2",0,&tolua_err)) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  b2Body* self = (b2Body*)  tolua_tousertype(tolua_S,1,0);
  b2Vec2 impulse = (  tolua_ext_luaval_to_b2vec2(tolua_S,2,0));
  b2Vec2 point = (  tolua_ext_luaval_to_b2vec2(tolua_S,3,0));
  bool wake = ((bool)  tolua_toboolean(tolua_S,4,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ApplyLinearImpulse'", NULL);
#endif
  {
   self->ApplyLinearImpulse(impulse,point,wake);
  }
 }
 return 0;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ApplyLinearImpulse'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ApplyAngularImpulse of class  b2Body */
#ifndef TOLUA_DISABLE_tolua_game_b2Body_ApplyAngularImpulse00
static int tolua_game_b2Body_ApplyAngularImpulse00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"b2Body",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  b2Body* self = (b2Body*)  tolua_tousertype(tolua_S,1,0);
  float impulse = ((float)  tolua_tonumber(tolua_S,2,0));
  bool wake = ((bool)  tolua_toboolean(tolua_S,3,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ApplyAngularImpulse'", NULL);
#endif
  {
   self->ApplyAngularImpulse(impulse,wake);
  }
 }
 return 0;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ApplyAngularImpulse'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMass of class  b2Body */
#ifndef TOLUA_DISABLE_tolua_game_b2Body_GetMass00
static int tolua_game_b2Body_GetMass00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"b2Body",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  b2Body* self = (b2Body*)  tolua_tousertype(tolua_S,1,0);
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMass'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetMass();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMass'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetInertia of class  b2Body */
#ifndef TOLUA_DISABLE_tolua_game_b2Body_GetInertia00
static int tolua_game_b2Body_GetInertia00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"b2Body",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  b2Body* self = (b2Body*)  tolua_tousertype(tolua_S,1,0);
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetInertia'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetInertia();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetInertia'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ResetMassData of class  b2Body */
#ifndef TOLUA_DISABLE_tolua_game_b2Body_ResetMassData00
static int tolua_game_b2Body_ResetMassData00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"b2Body",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  b2Body* self = (b2Body*)  tolua_tousertype(tolua_S,1,0);
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ResetMassData'", NULL);
#endif
  {
   self->ResetMassData();
  }
 }
 return 0;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ResetMassData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWorldPoint of class  b2Body */
#ifndef TOLUA_DISABLE_tolua_game_b2Body_GetWorldPoint00
static int tolua_game_b2Body_GetWorldPoint00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"b2Body",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"b2Vec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  b2Body* self = (b2Body*)  tolua_tousertype(tolua_S,1,0);
  b2Vec2 localPoint = (  tolua_ext_luaval_to_b2vec2(tolua_S,2,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWorldPoint'", NULL);
#endif
  {
   b2Vec2 tolua_ret = (b2Vec2)  self->GetWorldPoint(localPoint);
    tolua_ext_b2vec2_to_luaval(tolua_S, tolua_ret);
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWorldPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWorldVector of class  b2Body */
#ifndef TOLUA_DISABLE_tolua_game_b2Body_GetWorldVector00
static int tolua_game_b2Body_GetWorldVector00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"b2Body",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"b2Vec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  b2Body* self = (b2Body*)  tolua_tousertype(tolua_S,1,0);
  b2Vec2 localVector = (  tolua_ext_luaval_to_b2vec2(tolua_S,2,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWorldVector'", NULL);
#endif
  {
   b2Vec2 tolua_ret = (b2Vec2)  self->GetWorldVector(localVector);
    tolua_ext_b2vec2_to_luaval(tolua_S, tolua_ret);
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWorldVector'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetLocalPoint of class  b2Body */
#ifndef TOLUA_DISABLE_tolua_game_b2Body_GetLocalPoint00
static int tolua_game_b2Body_GetLocalPoint00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"b2Body",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"b2Vec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  b2Body* self = (b2Body*)  tolua_tousertype(tolua_S,1,0);
  b2Vec2 worldPoint = (  tolua_ext_luaval_to_b2vec2(tolua_S,2,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetLocalPoint'", NULL);
#endif
  {
   b2Vec2 tolua_ret = (b2Vec2)  self->GetLocalPoint(worldPoint);
    tolua_ext_b2vec2_to_luaval(tolua_S, tolua_ret);
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLocalPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetLocalVector of class  b2Body */
#ifndef TOLUA_DISABLE_tolua_game_b2Body_GetLocalVector00
static int tolua_game_b2Body_GetLocalVector00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"b2Body",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"b2Vec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  b2Body* self = (b2Body*)  tolua_tousertype(tolua_S,1,0);
  b2Vec2 worldVector = (  tolua_ext_luaval_to_b2vec2(tolua_S,2,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetLocalVector'", NULL);
#endif
  {
   b2Vec2 tolua_ret = (b2Vec2)  self->GetLocalVector(worldVector);
    tolua_ext_b2vec2_to_luaval(tolua_S, tolua_ret);
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLocalVector'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetLinearVelocityFromWorldPoint of class  b2Body */
#ifndef TOLUA_DISABLE_tolua_game_b2Body_GetLinearVelocityFromWorldPoint00
static int tolua_game_b2Body_GetLinearVelocityFromWorldPoint00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"b2Body",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"b2Vec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  b2Body* self = (b2Body*)  tolua_tousertype(tolua_S,1,0);
  b2Vec2 worldPoint = (  tolua_ext_luaval_to_b2vec2(tolua_S,2,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetLinearVelocityFromWorldPoint'", NULL);
#endif
  {
   b2Vec2 tolua_ret = (b2Vec2)  self->GetLinearVelocityFromWorldPoint(worldPoint);
    tolua_ext_b2vec2_to_luaval(tolua_S, tolua_ret);
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLinearVelocityFromWorldPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetLinearVelocityFromLocalPoint of class  b2Body */
#ifndef TOLUA_DISABLE_tolua_game_b2Body_GetLinearVelocityFromLocalPoint00
static int tolua_game_b2Body_GetLinearVelocityFromLocalPoint00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"b2Body",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"b2Vec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  b2Body* self = (b2Body*)  tolua_tousertype(tolua_S,1,0);
  b2Vec2 localPoint = (  tolua_ext_luaval_to_b2vec2(tolua_S,2,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetLinearVelocityFromLocalPoint'", NULL);
#endif
  {
   b2Vec2 tolua_ret = (b2Vec2)  self->GetLinearVelocityFromLocalPoint(localPoint);
    tolua_ext_b2vec2_to_luaval(tolua_S, tolua_ret);
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLinearVelocityFromLocalPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetLinearDamping of class  b2Body */
#ifndef TOLUA_DISABLE_tolua_game_b2Body_GetLinearDamping00
static int tolua_game_b2Body_GetLinearDamping00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"b2Body",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  b2Body* self = (b2Body*)  tolua_tousertype(tolua_S,1,0);
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetLinearDamping'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetLinearDamping();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLinearDamping'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetLinearDamping of class  b2Body */
#ifndef TOLUA_DISABLE_tolua_game_b2Body_SetLinearDamping00
static int tolua_game_b2Body_SetLinearDamping00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"b2Body",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  b2Body* self = (b2Body*)  tolua_tousertype(tolua_S,1,0);
  float linearDamping = ((float)  tolua_tonumber(tolua_S,2,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetLinearDamping'", NULL);
#endif
  {
   self->SetLinearDamping(linearDamping);
  }
 }
 return 0;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetLinearDamping'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAngularDamping of class  b2Body */
#ifndef TOLUA_DISABLE_tolua_game_b2Body_GetAngularDamping00
static int tolua_game_b2Body_GetAngularDamping00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"b2Body",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  b2Body* self = (b2Body*)  tolua_tousertype(tolua_S,1,0);
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAngularDamping'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetAngularDamping();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAngularDamping'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAngularDamping of class  b2Body */
#ifndef TOLUA_DISABLE_tolua_game_b2Body_SetAngularDamping00
static int tolua_game_b2Body_SetAngularDamping00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"b2Body",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  b2Body* self = (b2Body*)  tolua_tousertype(tolua_S,1,0);
  float angularDamping = ((float)  tolua_tonumber(tolua_S,2,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAngularDamping'", NULL);
#endif
  {
   self->SetAngularDamping(angularDamping);
  }
 }
 return 0;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAngularDamping'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetGravityScale of class  b2Body */
#ifndef TOLUA_DISABLE_tolua_game_b2Body_GetGravityScale00
static int tolua_game_b2Body_GetGravityScale00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"b2Body",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  b2Body* self = (b2Body*)  tolua_tousertype(tolua_S,1,0);
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetGravityScale'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetGravityScale();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetGravityScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetGravityScale of class  b2Body */
#ifndef TOLUA_DISABLE_tolua_game_b2Body_SetGravityScale00
static int tolua_game_b2Body_SetGravityScale00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"b2Body",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  b2Body* self = (b2Body*)  tolua_tousertype(tolua_S,1,0);
  float scale = ((float)  tolua_tonumber(tolua_S,2,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetGravityScale'", NULL);
#endif
  {
   self->SetGravityScale(scale);
  }
 }
 return 0;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetGravityScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetType of class  b2Body */
#ifndef TOLUA_DISABLE_tolua_game_b2Body_SetType00
static int tolua_game_b2Body_SetType00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"b2Body",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"b2BodyType",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  b2Body* self = (b2Body*)  tolua_tousertype(tolua_S,1,0);
  b2BodyType type = *((b2BodyType*)  tolua_tousertype(tolua_S,2,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetType'", NULL);
#endif
  {
   self->SetType(type);
  }
 }
 return 0;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetType of class  b2Body */
#ifndef TOLUA_DISABLE_tolua_game_b2Body_GetType00
static int tolua_game_b2Body_GetType00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"b2Body",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  b2Body* self = (b2Body*)  tolua_tousertype(tolua_S,1,0);
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetType'", NULL);
#endif
  {
   b2BodyType tolua_ret = (b2BodyType)  self->GetType();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((b2BodyType)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"b2BodyType");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(b2BodyType));
     tolua_pushusertype(tolua_S,tolua_obj,"b2BodyType");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetBullet of class  b2Body */
#ifndef TOLUA_DISABLE_tolua_game_b2Body_SetBullet00
static int tolua_game_b2Body_SetBullet00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"b2Body",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  b2Body* self = (b2Body*)  tolua_tousertype(tolua_S,1,0);
  bool flag = ((bool)  tolua_toboolean(tolua_S,2,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetBullet'", NULL);
#endif
  {
   self->SetBullet(flag);
  }
 }
 return 0;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetBullet'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsBullet of class  b2Body */
#ifndef TOLUA_DISABLE_tolua_game_b2Body_IsBullet00
static int tolua_game_b2Body_IsBullet00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"b2Body",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  b2Body* self = (b2Body*)  tolua_tousertype(tolua_S,1,0);
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsBullet'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsBullet();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsBullet'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSleepingAllowed of class  b2Body */
#ifndef TOLUA_DISABLE_tolua_game_b2Body_SetSleepingAllowed00
static int tolua_game_b2Body_SetSleepingAllowed00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"b2Body",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  b2Body* self = (b2Body*)  tolua_tousertype(tolua_S,1,0);
  bool flag = ((bool)  tolua_toboolean(tolua_S,2,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSleepingAllowed'", NULL);
#endif
  {
   self->SetSleepingAllowed(flag);
  }
 }
 return 0;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSleepingAllowed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsSleepingAllowed of class  b2Body */
#ifndef TOLUA_DISABLE_tolua_game_b2Body_IsSleepingAllowed00
static int tolua_game_b2Body_IsSleepingAllowed00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"b2Body",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  b2Body* self = (b2Body*)  tolua_tousertype(tolua_S,1,0);
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsSleepingAllowed'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsSleepingAllowed();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsSleepingAllowed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAwake of class  b2Body */
#ifndef TOLUA_DISABLE_tolua_game_b2Body_SetAwake00
static int tolua_game_b2Body_SetAwake00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"b2Body",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  b2Body* self = (b2Body*)  tolua_tousertype(tolua_S,1,0);
  bool flag = ((bool)  tolua_toboolean(tolua_S,2,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAwake'", NULL);
#endif
  {
   self->SetAwake(flag);
  }
 }
 return 0;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAwake'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsAwake of class  b2Body */
#ifndef TOLUA_DISABLE_tolua_game_b2Body_IsAwake00
static int tolua_game_b2Body_IsAwake00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"b2Body",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  b2Body* self = (b2Body*)  tolua_tousertype(tolua_S,1,0);
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsAwake'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsAwake();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsAwake'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetActive of class  b2Body */
#ifndef TOLUA_DISABLE_tolua_game_b2Body_SetActive00
static int tolua_game_b2Body_SetActive00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"b2Body",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  b2Body* self = (b2Body*)  tolua_tousertype(tolua_S,1,0);
  bool flag = ((bool)  tolua_toboolean(tolua_S,2,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetActive'", NULL);
#endif
  {
   self->SetActive(flag);
  }
 }
 return 0;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetActive'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsActive of class  b2Body */
#ifndef TOLUA_DISABLE_tolua_game_b2Body_IsActive00
static int tolua_game_b2Body_IsActive00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"b2Body",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  b2Body* self = (b2Body*)  tolua_tousertype(tolua_S,1,0);
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsActive'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsActive();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsActive'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetFixedRotation of class  b2Body */
#ifndef TOLUA_DISABLE_tolua_game_b2Body_SetFixedRotation00
static int tolua_game_b2Body_SetFixedRotation00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"b2Body",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  b2Body* self = (b2Body*)  tolua_tousertype(tolua_S,1,0);
  bool flag = ((bool)  tolua_toboolean(tolua_S,2,0));
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFixedRotation'", NULL);
#endif
  {
   self->SetFixedRotation(flag);
  }
 }
 return 0;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFixedRotation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsFixedRotation of class  b2Body */
#ifndef TOLUA_DISABLE_tolua_game_b2Body_IsFixedRotation00
static int tolua_game_b2Body_IsFixedRotation00(lua_State* tolua_S)
{
#if (COCOS2D_DEBUG == 1)
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"b2Body",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  b2Body* self = (b2Body*)  tolua_tousertype(tolua_S,1,0);
#if (COCOS2D_DEBUG == 1)
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsFixedRotation'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsFixedRotation();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if (COCOS2D_DEBUG == 1)
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsFixedRotation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_game_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"QFSMState","QFSMState","",tolua_collect_QFSMState);
  #else
  tolua_cclass(tolua_S,"QFSMState","QFSMState","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"QFSMState");
   tolua_function(tolua_S,"new",tolua_game_QFSMState_new00);
   tolua_function(tolua_S,"new_local",tolua_game_QFSMState_new00_local);
   tolua_function(tolua_S,".call",tolua_game_QFSMState_new00_local);
   tolua_function(tolua_S,"delete",tolua_game_QFSMState_delete00);
   tolua_function(tolua_S,"getStateName",tolua_game_QFSMState_getStateName00);
   tolua_function(tolua_S,"getFSM",tolua_game_QFSMState_getFSM00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"QFSM","QFSM","",tolua_collect_QFSM);
  #else
  tolua_cclass(tolua_S,"QFSM","QFSM","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"QFSM");
   tolua_function(tolua_S,"new",tolua_game_QFSM_new00);
   tolua_function(tolua_S,"new_local",tolua_game_QFSM_new00_local);
   tolua_function(tolua_S,".call",tolua_game_QFSM_new00_local);
   tolua_function(tolua_S,"delete",tolua_game_QFSM_delete00);
   tolua_function(tolua_S,"addState",tolua_game_QFSM_addState00);
   tolua_function(tolua_S,"addTranslation",tolua_game_QFSM_addTranslation00);
   tolua_function(tolua_S,"removeTranslation",tolua_game_QFSM_removeTranslation00);
   tolua_function(tolua_S,"start",tolua_game_QFSM_start00);
   tolua_function(tolua_S,"handle",tolua_game_QFSM_handle00);
   tolua_function(tolua_S,"clear",tolua_game_QFSM_clear00);
   tolua_function(tolua_S,"forceSwitch",tolua_game_QFSM_forceSwitch00);
   tolua_function(tolua_S,"getPreState",tolua_game_QFSM_getPreState00);
   tolua_function(tolua_S,"getNextState",tolua_game_QFSM_getNextState00);
   tolua_function(tolua_S,"getCurState",tolua_game_QFSM_getCurState00);
   tolua_function(tolua_S,"getCurEventName",tolua_game_QFSM_getCurEventName00);
  tolua_endmodule(tolua_S);
  tolua_constant(tolua_S,"AT_MONSTER",AT_MONSTER);
  tolua_constant(tolua_S,"AT_NPC",AT_NPC);
  tolua_constant(tolua_S,"AT_PLAYER",AT_PLAYER);
  tolua_constant(tolua_S,"AT_NONE",AT_NONE);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"GameActor","GameActor","cc.Node",tolua_collect_GameActor);
  #else
  tolua_cclass(tolua_S,"GameActor","GameActor","cc.Node",NULL);
  #endif
  tolua_beginmodule(tolua_S,"GameActor");
   tolua_function(tolua_S,"create",tolua_game_GameActor_create00);
   tolua_function(tolua_S,"new",tolua_game_GameActor_new00);
   tolua_function(tolua_S,"new_local",tolua_game_GameActor_new00_local);
   tolua_function(tolua_S,".call",tolua_game_GameActor_new00_local);
   tolua_function(tolua_S,"delete",tolua_game_GameActor_delete00);
   tolua_function(tolua_S,"init",tolua_game_GameActor_init00);
   tolua_function(tolua_S,"getGameAttribute",tolua_game_GameActor_getGameAttribute00);
   tolua_function(tolua_S,"getFSM",tolua_game_GameActor_getFSM00);
   tolua_function(tolua_S,"getArmature",tolua_game_GameActor_getArmature00);
   tolua_function(tolua_S,"getGameWord",tolua_game_GameActor_getGameWord00);
   tolua_function(tolua_S,"setOrientation",tolua_game_GameActor_setOrientation00);
   tolua_function(tolua_S,"getOrientation",tolua_game_GameActor_getOrientation00);
   tolua_function(tolua_S,"loadArmature",tolua_game_GameActor_loadArmature00);
   tolua_function(tolua_S,"getActorType",tolua_game_GameActor_getActorType00);
   tolua_function(tolua_S,"setActorType",tolua_game_GameActor_setActorType00);
   tolua_function(tolua_S,"isRunAABB",tolua_game_GameActor_isRunAABB00);
   tolua_function(tolua_S,"attLevelTest",tolua_game_GameActor_attLevelTest00);
   tolua_function(tolua_S,"AABBCallback",tolua_game_GameActor_AABBCallback00);
   tolua_function(tolua_S,"attOtherActorCallback",tolua_game_GameActor_attOtherActorCallback00);
   tolua_function(tolua_S,"lockOrientation",tolua_game_GameActor_lockOrientation00);
   tolua_function(tolua_S,"unLockOrientation",tolua_game_GameActor_unLockOrientation00);
   tolua_function(tolua_S,"isLockOrientation",tolua_game_GameActor_isLockOrientation00);
   tolua_function(tolua_S,"setMapConstraintEnable",tolua_game_GameActor_setMapConstraintEnable00);
   tolua_function(tolua_S,"isEnableMapConstraint",tolua_game_GameActor_isEnableMapConstraint00);
   tolua_function(tolua_S,"registerLuaHandle",tolua_game_GameActor_registerLuaHandle00);
   tolua_function(tolua_S,"unregisterLuaHandle",tolua_game_GameActor_unregisterLuaHandle00);
   tolua_function(tolua_S,"isIgnoreBodyRotation",tolua_game_GameActor_isIgnoreBodyRotation00);
   tolua_function(tolua_S,"setIgnoreBodyRotation",tolua_game_GameActor_setIgnoreBodyRotation00);
   tolua_function(tolua_S,"getB2Body",tolua_game_GameActor_getB2Body00);
   tolua_function(tolua_S,"setB2Body",tolua_game_GameActor_setB2Body00);
   tolua_function(tolua_S,"getPTMRatio",tolua_game_GameActor_getPTMRatio00);
   tolua_function(tolua_S,"setPTMRatio",tolua_game_GameActor_setPTMRatio00);
   tolua_function(tolua_S,"syncPhysicsTransform",tolua_game_GameActor_syncPhysicsTransform00);
  tolua_endmodule(tolua_S);
  tolua_constant(tolua_S,"GAME_ORI_LEFT",GAME_ORI_LEFT);
  tolua_constant(tolua_S,"GAME_ORI_RIGHT",GAME_ORI_RIGHT);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"GameAttribute","GameAttribute","",tolua_collect_GameAttribute);
  #else
  tolua_cclass(tolua_S,"GameAttribute","GameAttribute","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"GameAttribute");
   tolua_function(tolua_S,"new",tolua_game_GameAttribute_new00);
   tolua_function(tolua_S,"new_local",tolua_game_GameAttribute_new00_local);
   tolua_function(tolua_S,".call",tolua_game_GameAttribute_new00_local);
   tolua_function(tolua_S,"setHP",tolua_game_GameAttribute_setHP00);
   tolua_function(tolua_S,"getHP",tolua_game_GameAttribute_getHP00);
   tolua_function(tolua_S,"setAtt",tolua_game_GameAttribute_setAtt00);
   tolua_function(tolua_S,"getAtt",tolua_game_GameAttribute_getAtt00);
   tolua_function(tolua_S,"setDef",tolua_game_GameAttribute_setDef00);
   tolua_function(tolua_S,"getDef",tolua_game_GameAttribute_getDef00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"GameMap","GameMap","cc.Node",NULL);
  tolua_beginmodule(tolua_S,"GameMap");
   tolua_function(tolua_S,"create",tolua_game_GameMap_create00);
   tolua_function(tolua_S,"loadMapFile",tolua_game_GameMap_loadMapFile00);
   tolua_function(tolua_S,"setViewPos",tolua_game_GameMap_setViewPos00);
   tolua_function(tolua_S,"setViewSize",tolua_game_GameMap_setViewSize00);
   tolua_function(tolua_S,"getActorNode",tolua_game_GameMap_getActorNode00);
   tolua_function(tolua_S,"lockMapY",tolua_game_GameMap_lockMapY00);
   tolua_function(tolua_S,"unlockMapY",tolua_game_GameMap_unlockMapY00);
   tolua_function(tolua_S,"getMapWidth",tolua_game_GameMap_getMapWidth00);
   tolua_function(tolua_S,"getMapHeight",tolua_game_GameMap_getMapHeight00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"GameWord","GameWord","cc.Node",NULL);
  tolua_beginmodule(tolua_S,"GameWord");
   tolua_function(tolua_S,"create",tolua_game_GameWord_create00);
   tolua_function(tolua_S,"setGameMap",tolua_game_GameWord_setGameMap00);
   tolua_function(tolua_S,"getGameMap",tolua_game_GameWord_getGameMap00);
   tolua_function(tolua_S,"addActor",tolua_game_GameWord_addActor00);
   tolua_function(tolua_S,"removeActor",tolua_game_GameWord_removeActor00);
   tolua_function(tolua_S,"setLocalPlayer",tolua_game_GameWord_setLocalPlayer00);
   tolua_function(tolua_S,"getLocalPlayer",tolua_game_GameWord_getLocalPlayer00);
   tolua_function(tolua_S,"getPlayerCount",tolua_game_GameWord_getPlayerCount00);
   tolua_function(tolua_S,"getPlayerByIndex",tolua_game_GameWord_getPlayerByIndex00);
   tolua_function(tolua_S,"removeActorByName",tolua_game_GameWord_removeActorByName00);
   tolua_function(tolua_S,"logicUpdate",tolua_game_GameWord_logicUpdate00);
   tolua_function(tolua_S,"openDebugDraw",tolua_game_GameWord_openDebugDraw00);
   tolua_function(tolua_S,"isOpenDebugDraw",tolua_game_GameWord_isOpenDebugDraw00);
   tolua_function(tolua_S,"getActorNode",tolua_game_GameWord_getActorNode00);
   tolua_function(tolua_S,"getChildNode",tolua_game_GameWord_getChildNode00);
   tolua_function(tolua_S,"updateActors",tolua_game_GameWord_updateActors00);
   tolua_function(tolua_S,"setViewPortMinXValue",tolua_game_GameWord_setViewPortMinXValue00);
   tolua_function(tolua_S,"getViewPortMinXValue",tolua_game_GameWord_getViewPortMinXValue00);
   tolua_function(tolua_S,"setViewPortMaxXValue",tolua_game_GameWord_setViewPortMaxXValue00);
   tolua_function(tolua_S,"getViewPortMaxXValue",tolua_game_GameWord_getViewPortMaxXValue00);
   tolua_function(tolua_S,"setMinPosY",tolua_game_GameWord_setMinPosY00);
  tolua_endmodule(tolua_S);
  tolua_function(tolua_S,"getGameWord",tolua_game_getGameWord00);
  tolua_function(tolua_S,"changeParticleSystemPositionType",tolua_game_changeParticleSystemPositionType00);
  tolua_cclass(tolua_S,"TCPClient","TCPClient","",NULL);
  tolua_beginmodule(tolua_S,"TCPClient");
   tolua_constant(tolua_S,"CONNECT",TCPClient::CONNECT);
   tolua_constant(tolua_S,"CONNECTING",TCPClient::CONNECTING);
   tolua_constant(tolua_S,"DISCONNECTING",TCPClient::DISCONNECTING);
   tolua_constant(tolua_S,"DISCONNECT",TCPClient::DISCONNECT);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Client","Client","",NULL);
  tolua_beginmodule(tolua_S,"Client");
   tolua_function(tolua_S,"getInstance",tolua_game_Client_getInstance00);
   tolua_function(tolua_S,"destroy",tolua_game_Client_destroy00);
   tolua_function(tolua_S,"setCallFunc",tolua_game_Client_setCallFunc00);
   tolua_function(tolua_S,"connect",tolua_game_Client_connect00);
   tolua_function(tolua_S,"disconnect",tolua_game_Client_disconnect00);
   tolua_function(tolua_S,"closeClient",tolua_game_Client_closeClient00);
   tolua_function(tolua_S,"isCloseFinish",tolua_game_Client_isCloseFinish00);
   tolua_function(tolua_S,"send",tolua_game_Client_send00);
   tolua_function(tolua_S,"send",tolua_game_Client_send01);
   tolua_function(tolua_S,"setNoDelay",tolua_game_Client_setNoDelay00);
   tolua_function(tolua_S,"setKeepAlive",tolua_game_Client_setKeepAlive00);
   tolua_function(tolua_S,"checkState",tolua_game_Client_checkState00);
   tolua_function(tolua_S,"checkState",tolua_game_Client_checkState01);
   tolua_function(tolua_S,"setAutoReconnect",tolua_game_Client_setAutoReconnect00);
   tolua_function(tolua_S,"setAutoReconnectTime",tolua_game_Client_setAutoReconnectTime00);
   tolua_function(tolua_S,"setAutoReconnectByKey",tolua_game_Client_setAutoReconnectByKey00);
   tolua_function(tolua_S,"setAutoReconnectTimeByKey",tolua_game_Client_setAutoReconnectTimeByKey00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"b2Body","b2Body","",NULL);
  tolua_beginmodule(tolua_S,"b2Body");
   tolua_function(tolua_S,"SetTransform",tolua_game_b2Body_SetTransform00);
   tolua_function(tolua_S,"GetPosition",tolua_game_b2Body_GetPosition00);
   tolua_function(tolua_S,"GetAngle",tolua_game_b2Body_GetAngle00);
   tolua_function(tolua_S,"GetWorldCenter",tolua_game_b2Body_GetWorldCenter00);
   tolua_function(tolua_S,"GetLocalCenter",tolua_game_b2Body_GetLocalCenter00);
   tolua_function(tolua_S,"SetLinearVelocity",tolua_game_b2Body_SetLinearVelocity00);
   tolua_function(tolua_S,"GetLinearVelocity",tolua_game_b2Body_GetLinearVelocity00);
   tolua_function(tolua_S,"SetAngularVelocity",tolua_game_b2Body_SetAngularVelocity00);
   tolua_function(tolua_S,"GetAngularVelocity",tolua_game_b2Body_GetAngularVelocity00);
   tolua_function(tolua_S,"ApplyForce",tolua_game_b2Body_ApplyForce00);
   tolua_function(tolua_S,"ApplyForceToCenter",tolua_game_b2Body_ApplyForceToCenter00);
   tolua_function(tolua_S,"ApplyTorque",tolua_game_b2Body_ApplyTorque00);
   tolua_function(tolua_S,"ApplyLinearImpulse",tolua_game_b2Body_ApplyLinearImpulse00);
   tolua_function(tolua_S,"ApplyAngularImpulse",tolua_game_b2Body_ApplyAngularImpulse00);
   tolua_function(tolua_S,"GetMass",tolua_game_b2Body_GetMass00);
   tolua_function(tolua_S,"GetInertia",tolua_game_b2Body_GetInertia00);
   tolua_function(tolua_S,"ResetMassData",tolua_game_b2Body_ResetMassData00);
   tolua_function(tolua_S,"GetWorldPoint",tolua_game_b2Body_GetWorldPoint00);
   tolua_function(tolua_S,"GetWorldVector",tolua_game_b2Body_GetWorldVector00);
   tolua_function(tolua_S,"GetLocalPoint",tolua_game_b2Body_GetLocalPoint00);
   tolua_function(tolua_S,"GetLocalVector",tolua_game_b2Body_GetLocalVector00);
   tolua_function(tolua_S,"GetLinearVelocityFromWorldPoint",tolua_game_b2Body_GetLinearVelocityFromWorldPoint00);
   tolua_function(tolua_S,"GetLinearVelocityFromLocalPoint",tolua_game_b2Body_GetLinearVelocityFromLocalPoint00);
   tolua_function(tolua_S,"GetLinearDamping",tolua_game_b2Body_GetLinearDamping00);
   tolua_function(tolua_S,"SetLinearDamping",tolua_game_b2Body_SetLinearDamping00);
   tolua_function(tolua_S,"GetAngularDamping",tolua_game_b2Body_GetAngularDamping00);
   tolua_function(tolua_S,"SetAngularDamping",tolua_game_b2Body_SetAngularDamping00);
   tolua_function(tolua_S,"GetGravityScale",tolua_game_b2Body_GetGravityScale00);
   tolua_function(tolua_S,"SetGravityScale",tolua_game_b2Body_SetGravityScale00);
   tolua_function(tolua_S,"SetType",tolua_game_b2Body_SetType00);
   tolua_function(tolua_S,"GetType",tolua_game_b2Body_GetType00);
   tolua_function(tolua_S,"SetBullet",tolua_game_b2Body_SetBullet00);
   tolua_function(tolua_S,"IsBullet",tolua_game_b2Body_IsBullet00);
   tolua_function(tolua_S,"SetSleepingAllowed",tolua_game_b2Body_SetSleepingAllowed00);
   tolua_function(tolua_S,"IsSleepingAllowed",tolua_game_b2Body_IsSleepingAllowed00);
   tolua_function(tolua_S,"SetAwake",tolua_game_b2Body_SetAwake00);
   tolua_function(tolua_S,"IsAwake",tolua_game_b2Body_IsAwake00);
   tolua_function(tolua_S,"SetActive",tolua_game_b2Body_SetActive00);
   tolua_function(tolua_S,"IsActive",tolua_game_b2Body_IsActive00);
   tolua_function(tolua_S,"SetFixedRotation",tolua_game_b2Body_SetFixedRotation00);
   tolua_function(tolua_S,"IsFixedRotation",tolua_game_b2Body_IsFixedRotation00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_game (lua_State* tolua_S) {
 return tolua_game_open(tolua_S);
};
#endif

