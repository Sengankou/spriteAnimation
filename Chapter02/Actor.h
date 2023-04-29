#pragma once
#include <vector>
#include "Math.h"
class Actor
{
public:
	// Actorの状態管理用
	enum State
	{
		EActive,
		EPaused,
		EDead
	};

	Actor(class Game *game); // コンストラクタ
	virtual ~Actor();		 // デストラクタ

	// Game クラスから呼ばれる更新関数 (オーバーライド不可)
	void Update(float deltaTime);
	// アタッチされた全コンポーネントを更新(オーバーライド不可)
	void UpdateComponents(float deltaTime);
	// Actor 固有の更新処理 (オーバーライド可能)
	virtual void UpdateActor(float deltaTime);

	// Getter/Setter
	const Vector2 &GetPosition() const { return mPosition; }   // 位置を返す Getter
	void SetPosition(const Vector2 &pos) { mPosition = pos; }  // 位置をセットする Setter
	float GetScale() const { return mScale; }				   // スケールを返す Getter
	void SetScale(float scale) { mScale = scale; }			   // スケールをセットする Setter
	float GetRotation() const { return mRotation; }			   // 回転角度を返す Getter
	void SetRotation(float rotation) { mRotation = rotation; } // 回転角度をセットする Setter

	State GetState() const { return mState; }	   // Actor の状態を返す Getter
	void SetState(State state) { mState = state; } // Actor の状態をセットする Setter

	class Game *GetGame() { return mGame; } // Actor が属する Game クラスへのポインタを返す Getter

	// コンポーネントの追加/削除
	void AddComponent(class Component *component);	  // コンポーネントを追加する関数
	void RemoveComponent(class Component *component); // コンポーネントを削除する関数

private:
	// Actorの状態
	State mState;

	Vector2 mPosition; // Actorの中心位置
	float mScale;	   // Actorのスケール（1.0fが100%）
	float mRotation;   // 回転角度（ラジアン）

	std::vector<class Component *> mComponents; // アタッチされているコンポーネントを格納する vector コンテナ
	class Game *mGame;							// Actor が属する Game クラスへのポインタ
};
