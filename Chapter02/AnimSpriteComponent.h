// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#pragma once
#include "SpriteComponent.h"
#include <vector>
class AnimSpriteComponent : public SpriteComponent
{
public:
	AnimSpriteComponent(class Actor* owner, int drawOrder = 100);
	// フレーム毎にアニメーションを更新する
	void Update(float deltaTime) override;
	// アニメーションに使用するテクスチャを設定する
	void SetAnimTextures(const std::vector<SDL_Texture*>& textures);
	// FPSを設定・取得する
	float GetAnimFPS() const { return mAnimFPS; }
	void SetAnimFPS(float fps) { mAnimFPS = fps; }
private:
	// アニメーションでの全テクスチャ
	std::vector<SDL_Texture*> mAnimTextures;
	// 現在表示しているフレーム
	float mCurrFrame;
	// アニメーションのフレームレート
	float mAnimFPS;
};
