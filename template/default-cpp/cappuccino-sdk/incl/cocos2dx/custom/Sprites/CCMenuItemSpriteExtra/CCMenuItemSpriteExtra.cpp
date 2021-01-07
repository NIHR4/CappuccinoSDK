#include "CCMenuItemSpriteExtra.h"

void CCMenuItemSpriteExtra::selected(){
	CCMenuItemSprite::selected();
	auto resize = cocos2d::CCScaleTo::create(0.3, m_sizeMult);
	auto bounce = cocos2d::CCEaseBounceOut::create(resize);
	this->runAction(bounce);
}

void CCMenuItemSpriteExtra::unselected(){
	CCMenuItemSprite::selected();
	auto resize = cocos2d::CCScaleTo::create(0.3, 1.0);
	auto bounce = cocos2d::CCEaseBounceOut::create(resize);
	this->runAction(bounce);
}


CCMenuItemSpriteExtra* CCMenuItemSpriteExtra::create(CCNode *normalSprite, CCNode *selectedSprite, CCObject *target, cocos2d::SEL_MenuHandler selector){
	auto spriteItem = new CCMenuItemSpriteExtra;
	if (spriteItem && spriteItem->initWithNormalSprite(normalSprite, selectedSprite, nullptr, target, selector)) 
		spriteItem->autorelease();
	else {
		delete spriteItem;
		spriteItem = nullptr;
	}
	return spriteItem;

}