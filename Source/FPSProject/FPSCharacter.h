// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "FPSProjectile.h"
#include "FPSCharacter.generated.h"

UCLASS()
class FPSPROJECT_API AFPSCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFPSCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Projectile class to spawn
	UPROPERTY(EditAnywhere, Category = Projectile)
		TSubclassOf<class AFPSProjectile> ProjectileClass;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
		void MoveForward(float Value);

	UFUNCTION()
		void MoveRight(float Value);

	//Sets jump flag when button is pressed
	UFUNCTION()
		void StartJump();

	//Clears jump flag when button is released
	UFUNCTION()
		void StopJump();

	//Function that handles firing projectiles
	UFUNCTION()
		void Fire();

	//FPS Camera
	UPROPERTY(VisibleAnywhere)
		UCameraComponent* FPSCameraComponent;

	//First-person mesh (arms), visible only to the owning player
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		USkeletalMeshComponent* FPSMesh;

	//Gun muzzle offset from the camera location
	UPROPERTY(EditAnwhere, BlueprintReadWrite, Category = Gameplay)
		FVector MuzzleOffset;




};
