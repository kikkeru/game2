#pragma once
#pragma once
#include <GLLibrary.h>

//!アニメーションの種類
enum {
	eAnimIdle = 0,
	eAnimRun,
	eAnimJumpUp,
	eAnimJumpDown,
	eAnimAttack01,
	eAnimAttack01End,
	eAnimAttack02,
	eAnimAttack02End,
	eAnimAttack03,
	eAnimAttack03End,
	eAnimDamage,
	eAnimDamageEnd,
	eAnimDeath,
	eAnimDown,
	eAnimGuard,
	eAnimGuardEnd,
	eAnimStep,
	eAnimStan,
	eAnimCharge,
	eAnimPause,
};

//プレイヤーのアニメーションデータ
extern TexAnimData player_anim_data[];
//敵のアニメーションデータ
extern TexAnimData enemy_anim_data[];
//ボスのアニメーションデータ
extern TexAnimData boss_anim_data[];

//エフェクトのアニメーションデータ
extern TexAnimData effect_Gurad_anim_data[];
extern TexAnimData effect_slash_anim_data[];
extern TexAnimData effect_slash2_anim_data[];
extern TexAnimData effect_slash3_anim_data[];
extern TexAnimData effect_eslash1_anim_data[];
extern TexAnimData effect_eslash2_anim_data[];
extern TexAnimData effect_eslash3_anim_data[];
extern TexAnimData Guard_anim_data[];
extern TexAnimData effect_Rock_anim_data[];

