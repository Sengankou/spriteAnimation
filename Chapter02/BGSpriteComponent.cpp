// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
//
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#include "BGSpriteComponent.h"
#include "Actor.h"

BGSpriteComponent::BGSpriteComponent(class Actor *owner, int drawOrder)
	: SpriteComponent(owner, drawOrder), mScrollSpeed(0.0f)
{
}

void BGSpriteComponent::Update(float deltaTime)
{
	SpriteComponent::Update(deltaTime);
	for (auto &bg : mBGTextures)
	{
		// xのオフセットを更新
		bg.mOffset.x += mScrollSpeed * deltaTime;
		// 画面から完全に出た場合、オフセットを最後の背景テクスチャの右にリセット
		if (bg.mOffset.x < -mScreenSize.x)
		{
			bg.mOffset.x = (mBGTextures.size() - 1) * mScreenSize.x - 1;
		}
	}
}

void BGSpriteComponent::Draw(SDL_Renderer *renderer)
{
	// それぞれの背景テクスチャを描画
	for (auto &bg : mBGTextures)
	{
		SDL_Rect r;
		// 画面のサイズを設定
		r.w = static_cast<int>(mScreenSize.x);
		r.h = static_cast<int>(mScreenSize.y);
		// ownerの位置を中心に矩形を設定
		r.x = static_cast<int>(mOwner->GetPosition().x - r.w / 2 + bg.mOffset.x);
		r.y = static_cast<int>(mOwner->GetPosition().y - r.h / 2 + bg.mOffset.y);

		// この背景を描画
		SDL_RenderCopy(renderer,
					   bg.mTexture,
					   nullptr,
					   &r);
	}
}

void BGSpriteComponent::SetBGTextures(const std::vector<SDL_Texture *> &textures)
{
	int count = 0;
	for (auto tex : textures)
	{
		BGTexture temp;
		temp.mTexture = tex;
		// それぞれのテクスチャは画面幅分のオフセットを持つ
		temp.mOffset.x = count * mScreenSize.x;
		temp.mOffset.y = 0;
		mBGTextures.emplace_back(temp);
		count++;
	}
}
