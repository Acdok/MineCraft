// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/PlayerAnimInstance.h"
#include "MineCraftCharacter.h"
#include "MineCraftPlayerController.h"


UPlayerAnimInstance::UPlayerAnimInstance()
{
	mCanJump = true;

	mAttackEnable = true;

	mAnimType = EPlayerAnimType::Default;

	mAdditiveAlpha = 0.f;
}

void UPlayerAnimInstance::NativeInitializeAnimation()
{
}

void UPlayerAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	AMineCraftCharacter* PlayerCharacter = Cast<AMineCraftCharacter>(TryGetPawnOwner());

	if (IsValid(PlayerCharacter))
	{
		UCharacterMovementComponent* Movement = PlayerCharacter->GetCharacterMovement();

		if (IsValid(Movement))
		{
			
			mMoveSpeed = Movement->Velocity.Length();
			mMoveSpeed /= Movement->MaxWalkSpeed;

			// 캐릭터가 땅을 밟고 있는지 판단한다.
			// IsMovingOnGround : 캐릭터가 땅을 밟고 있으면 true,
			// 아니면 false를 반환한다.
			mOnGround = Movement->IsMovingOnGround();

			if (!mOnGround && mAnimType != EPlayerAnimType::Jump &&
				mAnimType != EPlayerAnimType::Fall)
			{
				mAnimType = EPlayerAnimType::Fall;
			}

		}
		// 이 애님인스턴스를 가지고 있는 캐릭터로부터 해당 캐릭터를 컨트롤 하고 있는 플레이어
		// 컨트롤러를 얻어온다.
		AMineCraftPlayerController* Controller = PlayerCharacter->GetController<AMineCraftPlayerController>();

		// 위에서 얻어온 컨트롤러가 유효한지 체크한다.
		if (IsValid(Controller))
		{
			mMoveDir = Controller->GetMoveDir();
		}
	}
}

void UPlayerAnimInstance::PlayAttackMontage()
{

	mAnimType = EPlayerAnimType::Attack;
		Montage_Play(AttackAnimMontage);
	
}


	void UPlayerAnimInstance::PlayJump()
{
		mCanJump = false;

		mAnimType = EPlayerAnimType::Jump;

	
		// 점프 리커버리 몽타주가 재생되고 있다면 재생을 중지한다.
		if (Montage_IsPlaying(mJumpRecoveryAdditiveMontage))
		{
			Montage_Stop(0.1f, mJumpRecoveryAdditiveMontage);
			mAdditiveAlpha = 0.f;
		}
}

void UPlayerAnimInstance::Crouch()
{
	mAnimType = EPlayerAnimType::Crouch;
}

void UPlayerAnimInstance::Build()
{
	mAnimType = EPlayerAnimType::Build;
}

void UPlayerAnimInstance::AnimNotify_TransitionFall()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Jump!"));
	mAnimType = EPlayerAnimType::Fall;
}

void UPlayerAnimInstance::AnimNotify_FallEnd()
{
	mAnimType = EPlayerAnimType::Default;

	// 리커버리 Additive를 적용하기 위해 값을 1로 변경한다.
	mAdditiveAlpha = 1.f;

	// 리커버리 동작을 재생한다.
	if (!Montage_IsPlaying(mJumpRecoveryAdditiveMontage))
	{
		Montage_SetPosition(mJumpRecoveryAdditiveMontage, 0.f);

		Montage_Play(mJumpRecoveryAdditiveMontage);
	}

	// 다시 점프를 가능한 상태로 만들어준다.
	mCanJump = true;
}

void UPlayerAnimInstance::AnimNotify_JumpRecoveryEnd()
{
	mAdditiveAlpha = 0.f;
}
