#include "CCMenuItemSpriteExtra.h"


DWORD base = (DWORD)GetModuleHandleA("GeometryDash.exe");
namespace cocos2d {
	#pragma runtime_checks( "s", off )
	void CCMenuItemSpriteExtra::activate(){
		typedef void(__thiscall* mActivate)(CCMenuItemSpriteExtra*);
		reinterpret_cast<mActivate>(base + 0x191C0)(this);
	}

	void CCMenuItemSpriteExtra::selected(){
		typedef void(__thiscall* mSelected)(CCMenuItemSpriteExtra*);
		reinterpret_cast<mSelected>(base + 0x19270)(this);
	}

	void CCMenuItemSpriteExtra::unselected(){
		typedef void(__thiscall* mUnselected)(CCMenuItemSpriteExtra*);
		reinterpret_cast<mUnselected>(base + 0x19430)(this);
	}

	CCMenuItemSpriteExtra* CCMenuItemSpriteExtra::create(
		
		CCNode* normalSprite, 
		CCObject* target, 
		SEL_MenuHandler selector) {
		typedef CCMenuItemSpriteExtra* (__thiscall* createPtr)(CCNode*,CCObject*, SEL_MenuHandler);
		auto returnVal = reinterpret_cast<createPtr>(base + 0x18EE0)(normalSprite , target, selector);
		__asm add esp,8
		return returnVal;
	}
	#pragma runtime_checks( "s", restore )
}