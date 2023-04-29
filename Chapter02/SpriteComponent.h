// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
//
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#pragma once
#include "Component.h"
#include "SDL/SDL.h"
class SpriteComponent : public Component
{
public:
	// 描画順序(drawOrder)が低いほど遠くに置かれる
	SpriteComponent(class Actor *owner, int drawOrder = 100);
	~SpriteComponent();

	virtual void Draw(SDL_Renderer *renderer);
	virtual void SetTexture(SDL_Texture *texture);

	int GetDrawOrder() const { return mDrawOrder; }
	int GetTexHeight() const { return mTexHeight; }
	int GetTexWidth() const { return mTexWidth; }

protected:
	SDL_Texture *mTexture; // 描画するテクスチャ
	int mDrawOrder;		   // 画家のアルゴリズムで使用する描画順序
	int mTexWidth;		   // テクスチャの幅
	int mTexHeight;		   // テクスチャの高さ
};
