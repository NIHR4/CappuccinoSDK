#ifndef __CCMENU_ITEM_EXTRA_H__
#define __CCMENU_ITEM_EXTRA_H__

#include "menu_nodes/CCMenuItem.h"
#include "sprite_nodes/CCSprite.h"

NS_CC_BEGIN

class CC_DLL CCMenuItemSpriteExtra : public CCMenuItemSprite {
private:
	uint32_t m_uiUnknown0 = 0x3F800000; //0x118
	uint32_t m_uiUnknown1 = 0;          //0x11C
	uint16_t m_usUnknown2 = 0;		    //0x120
	uint8_t  m_ucUnknown3 = false;      //0x121
	uint32_t m_uiUnknwon4 = 0x3F800000; //0x124
	uint32_t m_uiUnknown5 = 0;          //0x128
	uint32_t m_uiUnknown6 = 0;          //0x128
	uint32_t m_uiUnknown7 = 0;          //0x12C
	uint32_t m_uiUnknown8 = 0x3F48C8C9; //0x130
	CCPoint  m_cUnknown9;               //0x134
	uint32_t m_uiUnknwonA = 0x3E99999A; //0x13C
	uint32_t m_uiUnknwonB = 0x3ECCCCCD; //0x140
	uint32_t m_uiUnknwonC = 0;          //0x144
	uint32_t m_uiUnknwonD = 0;          //0x148
	
public:
	virtual void activate() override;
	virtual void selected() override;
	virtual void unselected() override;
	static CCMenuItemSpriteExtra* create(CCNode* normalSprite, /*CCNode* selectedSprite,*/ CCObject* target, SEL_MenuHandler selector);
};

NS_CC_END
#endif