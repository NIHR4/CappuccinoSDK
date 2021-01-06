#pragma once
#include <cocos2d.h>

class CCMenuItemSpriteExtra : public cocos2d::CCMenuItemSprite{
private:
	float m_sizeMult = 1.25;
public:
	virtual void selected() override;
	virtual void unselected() override;
	static CCMenuItemSpriteExtra* create(CCNode *normalSprite, CCNode *selectedSprite, CCObject *target, cocos2d::SEL_MenuHandler selector);
	void setSizeMult(float multiplier) { m_sizeMult = 1.25; }
};