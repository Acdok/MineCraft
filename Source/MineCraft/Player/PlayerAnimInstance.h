// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../GameInfo.h"
#include "Animation/AnimInstance.h"
#include "PlayerAnimInstance.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class EPlayerAnimType : uint8
{
	Default,
	Jump,
	Fall,
	Death,
	Attack,
	Build,
	Crouch
};
UCLASS()
class MINECRAFT_API UPlayerAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float	mMoveSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float	mMoveDir;

	// 현재 공격가능한 상황인지를 판단하는 변수이다.
	bool	mAttackEnable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UAnimMontage* AttackAnimMontage;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	EPlayerAnimType	mAnimType;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool	mOnGround;

	bool	mCanJump;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UAnimMontage* mJumpRecoveryAdditiveMontage;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float	mAdditiveAlpha;

public:
	UPlayerAnimInstance();

public:
	void SetAnimType(EPlayerAnimType Type)
	{
		mAnimType = Type;
	}

public:
	virtual void NativeInitializeAnimation();
	virtual void NativeUpdateAnimation(float DeltaSeconds);

public:
	void PlayAttackMontage();
	void PlayJump();
	void Crouch();
	void Build();

public:
	UFUNCTION()
	void AnimNotify_TransitionFall();

	UFUNCTION()
	void AnimNotify_FallEnd();

	UFUNCTION()
	void AnimNotify_JumpRecoveryEnd();
};


