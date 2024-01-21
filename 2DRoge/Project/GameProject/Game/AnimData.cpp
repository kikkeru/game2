#include "AnimData.h"


static TexAnim playerIdle[] = {
	{ 0,16 },
	{ 1,16 },
	{ 2,16 },
	
};
static TexAnim playerRun[] = {
	{ 10,8 },
	{ 11,8 },
	{ 12,8 },
	{ 13,8 },
	{ 14,8 },
	{ 15,8 },
	
	
};
static TexAnim playerJumpUp[] = {
	{ 20,4 },
	

};
static TexAnim playerJumpDown[] = {
	{ 21,7 },
	{ 22,7 },
	
	

};
static TexAnim playerAttack01[] = {
	{ 30,10 },
	{ 31,1 },
	{ 31,4 },
	
	
};
static TexAnim playerAttack01End[] = {
	{ 31,4 },
};
static TexAnim playerAttack02[] = {
	{ 32,10 },
	{ 33,1 },
	{ 33,4 },
};
static TexAnim playerAttack02End[] = {
	{ 33,4 },
};
static TexAnim playerAttack03[] = {
	{ 34,10 },
	{ 35,1 },
	{ 35,4 }, };
static TexAnim playerAttack03End[] = {
	{ 35,4 },
};

static TexAnim playerDamage[] = {
	{ 50,4 },
	{ 51,4 },
	{ 50,4 },
	{ 51,4 },
	
	
};
static TexAnim playerDamageEnd[] = {
	{ 51,2 },
};
static TexAnim playerDeath[] = {
	{ 52,3 },
	{ 53,3 },
};

static TexAnim playerDown[] = {
	{ 50,6 },
	{ 52,6 },
	{ 53,20 },
};
static TexAnim playerDownGround[] = {
	{ 109,4 },
	{ 110,4 },
	{ 111,4 },
};
static TexAnim playerWakeup[] = {
	{ 112,4 },
	{ 113,4 },
	{ 114,4 },
	{ 115,4 },
	{ 116,4 },
	{ 117,4 },
	{ 118,4 },
};
static TexAnim playerGuard[] = {
	{ 40,4 },
};
static TexAnim playerGuardEnd[] = {
	{ 122,4 },
	{ 121,4 },
	{ 120,4 },
};
static TexAnim playerCrash[] = {
	{ 128,4 },
	{ 129,4 },
	{ 130,4 },
	{ 131,90 },
};
static TexAnim playerCrash01End[] = {
	{ 131,4 },
	{ 130,4 },
	{ 129,4 },
	{ 128,4 },
};
static TexAnim playerExtAttack01[] = {
	{ 144,4 },
	{ 145,4 },
	{ 146,12 },
	{ 147,2 },
	{ 148,2 },
	{ 149,2 },
	{ 150,16 },
};
static TexAnim playerExtAttack01End[] = {
	{ 151,4 },
	{ 152,4 },
};
static TexAnim playerExtAttack02[] = {
	{ 160,2 },
	{ 161,2 },
	{ 162,2 },
	{ 163,2 },
	{ 164,2 },
	{ 165,2 },
	{ 166,2 },
	{ 167,2 },
	{ 168,2 },
};
static TexAnim playerExtAttack02End[] = {
	{ 169,16 },
	{ 170,4 },
	{ 171,4 },
};
static TexAnim playerStep[] = {
	{ 23,7 },
	{ 24,8 },
};
TexAnimData player_anim_data[] = {
	ANIMDATA(playerIdle),
	ANIMDATA(playerRun),
	ANIMDATA(playerJumpUp),
	ANIMDATA(playerJumpDown),
	ANIMDATA(playerAttack01),
	ANIMDATA(playerAttack01End),
	ANIMDATA(playerAttack02),
	ANIMDATA(playerAttack02End),
	ANIMDATA(playerAttack03),
	ANIMDATA(playerAttack03End),
	ANIMDATA(playerDamage),
	ANIMDATA(playerDamageEnd),
	ANIMDATA(playerDeath),
	ANIMDATA(playerDown),
	ANIMDATA(playerGuard),
	ANIMDATA(playerGuardEnd),
	ANIMDATA(playerStep),
	
};

static TexAnim enemyIdle[] = {
	{ 0,16 },
	{ 1,16 },
	{ 2,16 },
};
static TexAnim enemyRun[] = {
	{ 10,8 },
	{ 11,8 },
	{ 12,8 },
	{ 13,8 },
	{ 14,8 },
	{ 15,8 },
};
static TexAnim enemyJumpUp[] = {
	{ 20,4 },
};
static TexAnim enemyJumpDown[] = {
	{ 21,4 },
	{ 22,4 },
};

static TexAnim enemyAttack01[] = {
	{ 30,15},
	{ 31,3},
	{ 31,1},
	{ 31,15 },
};
static TexAnim enemyAttack01End[] = {
	{31,15},
};
static TexAnim enemyAttack02[] = {
	{ 0,0 },
};
static TexAnim enemyAttack02End[] = {
	{ 0,0 },
};
static TexAnim enemyAttack03[] = {
	{ 0,0 },
};
static TexAnim enemyAttack03End[] = {
	{ 0,0 },
};
static TexAnim enemyDamage[] = {
	{ 50,4 },
	{ 51,4 },
	{ 50,4 },
	{ 51,4 },
};
static TexAnim enemyDamageEnd[] = {
	{51,2}
};
static TexAnim enemyDeath[] = {
	{ 96,4 },
	{ 97,4 },
	{ 98,8 },
	{ 99,4 },
	{ 100,4 },
	{ 101,4 },
	{ 102,4 },
	{ 103,4 },
};

static TexAnim enemyDown[] = {
	{ 50,6 },
	{ 52,6 },
	{ 53,6 }, 
};
static TexAnim enemyDownGround[] = {
	{ 109,4 },
	{ 110,4 },
	{ 111,4 },
};
static TexAnim enemyWakeup[] = {
	{ 112,4 },
	{ 113,4 },
	{ 114,4 },
	{ 115,4 },
	{ 116,4 },
	{ 117,4 },
	{ 118,4 },
};
static TexAnim enemyGuard[] = {
	{ 0,4 },
};
static TexAnim enemyGuardEnd[] = {
	{ 0,4 },
};
static TexAnim enemyCrash[] = {
	{ 128,4 },
	{ 129,4 },
	{ 130,4 },
	{ 131,60 },
};
static TexAnim enemyCrash01End[] = {
	{ 131,4 },
	{ 130,4 },
	{ 129,4 },
	{ 128,4 },
};
static TexAnim enemyExt01Attack[] = {
	{ 0,4 },
};
static TexAnim enemyExtAttack01End[] = {
	{ 0,4 },
};
static TexAnim enemyStep[] = {
	{ 21,4 },
	{ 22,4 },
};
static TexAnim enemyStan[] = {
	{ 40,4 },
	{ 50,4 },

};


TexAnimData enemy_anim_data[] = {
	ANIMDATA(enemyIdle),
	ANIMDATA(enemyRun),
	ANIMDATA(enemyJumpUp),
	ANIMDATA(enemyJumpDown),
	ANIMDATA(enemyAttack01),
	ANIMDATA(enemyAttack01End),
	ANIMDATA(enemyAttack02),
	ANIMDATA(enemyAttack02End),
	ANIMDATA(enemyAttack03),
	ANIMDATA(enemyAttack03End),
	ANIMDATA(enemyDamage),
	ANIMDATA(enemyDamageEnd),
	ANIMDATA(enemyDeath),
	ANIMDATA(enemyDown),
	ANIMDATA(enemyGuard),
	ANIMDATA(enemyGuardEnd),
	ANIMDATA(enemyStep),
	ANIMDATA(enemyStan),
};

static TexAnim bossIdle[] = {
	{ 1,16 },
};
static TexAnim bossRun[] = {
	{ 10,15 },
	{ 11,15 },
};
static TexAnim bossJumpUp[] = {
	{ 23,4 },


};
static TexAnim bossJumpDown[] = {
	{ 23,7 },



};
static TexAnim bossAttack01[] = {
	{ 30,15 },
	{ 31,1 },
	{ 31,5 },


};
static TexAnim bossAttack01End[] = {
	{ 31,4 },
};
static TexAnim bossAttack02[] = {
	{ 33,30 },
};
static TexAnim bossAttack02End[] = {
	{ 33,4 },
};
static TexAnim bossAttack03[] = {
	{ 35,7 },
	{ 35,30 },
};
static TexAnim bossAttack03End[] = {
	{ 35,10 },
};

static TexAnim bossDamage[] = {
	{ 50,4 },
	{ 51,4 },
	{ 50,4 },
	{ 51,4 },


};
static TexAnim bossDamageEnd[] = {
	{ 51,2 },
};
static TexAnim bossrDeath[] = {
	{ 52,3 },
	{ 53,3 },
};

static TexAnim bossDeath[] = {
	{ 50,6 },
	{ 52,6 },
	{ 53,6 },
};

static TexAnim bossDown[] = {
	{ 50,6 },
	{ 52,6 },
	{ 53,20 },
};

static TexAnim bossGuard[] = {
	{ 21,5 },
	{ 22,5 },
};

static TexAnim bossGuardEnd[] = {
	{ 21,5 },
	{ 22,5 },
};

static TexAnim bossStep[] = {
	{ 23,5 },
};

static TexAnim bossStan[] = {
	{ 23,5 },
};

static TexAnim bossCharge[] = {
	{ 34,75 },

};

static TexAnim bossPause[] = {
	{ 32,40 },

};

TexAnimData boss_anim_data[] = {
	ANIMDATA(bossIdle),
	ANIMDATA(bossRun),
	ANIMDATA(bossJumpUp),
	ANIMDATA(bossJumpDown),
	ANIMDATA(bossAttack01),
	ANIMDATA(bossAttack01End),
	ANIMDATA(bossAttack02),
	ANIMDATA(bossAttack02End),
	ANIMDATA(bossAttack03),
	ANIMDATA(bossAttack03End),
	ANIMDATA(bossDamage),
	ANIMDATA(bossDamageEnd),
	ANIMDATA(bossDeath),
	ANIMDATA(bossDown),
	ANIMDATA(bossGuard),
	ANIMDATA(bossGuardEnd),
	ANIMDATA(bossStep),
	ANIMDATA(bossStan),
	ANIMDATA(bossCharge),
	ANIMDATA(bossPause),
	
};



static TexAnim _effect_blood[] = {
	{ 0,1 },
	{ 1,1 },
	{ 2,1 },
	{ 3,1 },
};
TexAnimData effect_blood_anim_data[] = {
	ANIMDATA(_effect_blood),
};
static TexAnim _effect_smoke[] = {
	{ 0,2 },
	{ 1,2 },
	{ 2,2 },
	{ 3,2 },
	{ 4,2 },
};
TexAnimData effect_smoke_anim_data[] = {
	ANIMDATA(_effect_smoke),
};

static TexAnim _effect_Gurad[] = {
	{ 0,2 },
	
};
TexAnimData effect_Gurad_anim_data[] = {
	ANIMDATA(_effect_Gurad),
};

static TexAnim _effect_slash[] = {
	{ 0,4 },
	{ 1,4 },
	{ 2,4 },
	{ 3,4 },
	{ 4,4 },
};

TexAnimData effect_slash_anim_data[] = {
	ANIMDATA(_effect_slash),
};

static TexAnim _effect_slash2[] = {
	{ 0,4 },
	{ 1,4 },
	{ 2,4 },
	{ 3,4 },
	{ 4,4 },
};

TexAnimData effect_slash2_anim_data[] = {
	ANIMDATA(_effect_slash2),
};

static TexAnim _effect_slash3[] = {
	{ 0,4 },
	{ 1,4 },
	{ 2,4 },
	{ 3,4 },
	{ 4,4 },
};

TexAnimData effect_slash3_anim_data[] = {
	ANIMDATA(_effect_slash3),
};

static TexAnim _effect_eslash1[] = {
	{ 0,4 },
	{ 1,4 },
	{ 2,4 },
	{ 3,4 },
	{ 4,4 },
};

TexAnimData effect_eslash1_anim_data[] = {
	ANIMDATA(_effect_eslash1),
};

static TexAnim _effect_eslash2[] = {
	{ 3,4 },
	{ 4,4 },
	
};

TexAnimData effect_eslash2_anim_data[] = {
	ANIMDATA(_effect_eslash2),
};

static TexAnim _effect_eslash3[] = {
	{ 0,4 },
	{ 1,4 },
	{ 2,4 },
	{ 3,4 },
	{ 4,4 },
};

TexAnimData effect_eslash3_anim_data[] = {
	ANIMDATA(_effect_eslash3),
};


static TexAnim _Guard[] = {
	{ 40,4 },
	
};

TexAnimData Guard_anim_data[] = {
	ANIMDATA(_Guard),
};

static TexAnim _effect_Rock[] = {
	{ 0,4 },
	{ 1,4 },
	
};

TexAnimData effect_Rock_anim_data[] = {
	ANIMDATA(_effect_Rock),
};