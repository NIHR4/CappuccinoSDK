#pragma once
#include <cocos2d.h>

class CCMenuItemSpriteExtra : public cocos2d::CCMenuItemSprite{
private:
	float m_fSizeMult = 1.25;
	float m_fOriginalSizeMult;
public:
	virtual void selected() override;
	virtual void unselected() override;
	virtual void activate() override;
	static CCMenuItemSpriteExtra* create(CCNode *normalSprite, CCNode *selectedSprite, CCObject *target, cocos2d::SEL_MenuHandler selector);
	void setSizeMult(float multiplier) { m_fSizeMult = multiplier; }
};
