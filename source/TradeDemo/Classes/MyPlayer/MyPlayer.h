// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "TradeDemo/Interfaces/IDamagable/Damagable.h"
#include "TradeDemo/Interfaces/IInteractable/Interactable.h"
#include "TradeDemo/Classes/Inventory/Inventory.h"
#include "MyPlayer.generated.h"

// A class that represents the player character. It contains properties such as
// health, speed, and inventory that can be modified during the game.
UCLASS()
class TRADEDEMO_API AMyPlayer : public APawn, public IDamagable, public IInteractable
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPlayer();

	/** Property replication */
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	/** Called for forwards/backwards input **/
	void MoveForward(float Value);
	
	/** Called for side to side input **/
	void MoveRight(float Value);

	/**
	 * Called via input to turn at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of the desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to look up / down at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of the desired turn rate
	 */
	void LookUpAtRate(float Rate);

	/**
	 * Rotate controller based on mouse X movement
	 * @param Value	The input value from mouse movement
	 */
	void Turn(float Value);

	/**
	 * Rotate controller based on mouse Y movement
	 * @param Value	The input value from mouse movement
	 */
	void LookUp(float Value);

	/**
	 * Initiate Jumping for the Character
	 */
	void Jump();

	/**
	 * Terminate Jumping for the Character
	 */
	void StopJumping();

	/**
	 * Initiate Crouching for the Character
	 */
	void Crouch();

	/**
	 * Terminate Crouching for the Character
	 */
	void UnCrouch();

	// Health / Networking / Replication Code 


	/** The player's maximum health. This is the highest value of their health can be. This value is a value of the player's health, which starts at when spawned.*/
	UPROPERTY(EditDefaultsOnly, Category = "Health")
	float MaxHealth;

	/** The player's current health. When reduced to 0, they are considered dead.*/
	UPROPERTY(ReplicatedUsing = OnRep_CurrentHealth)
	float CurrentHealth;

	/** RepNotify for changes made to current health.*/
	UFUNCTION()
	void OnRep_CurrentHealth();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	// UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
	// float Health;
    
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
	float Speed;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
	float Money;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
	UInventory* Inventory;

	//virtual void TakeDamage(float Amount) override;
	virtual void Interact() override;

	/** Getter for Max Health.*/
	UFUNCTION(BlueprintPure, Category="Player")
	FORCEINLINE float GetMaxHealth() const { return MaxHealth; } 

	/** Getter for Current Health.*/
	UFUNCTION(BlueprintPure, Category="Player")
	FORCEINLINE float GetCurrentHealth() const { return CurrentHealth; }

	/** Setter for Current Health. Clamps the value between 0 and MaxHealth and calls OnHealthUpdate. Should only be called on the server.*/
	UFUNCTION(BlueprintCallable, Category="Player")
	void SetCurrentHealth(float healthValue);

	/** Event for taking damage. Overridden from APawn.*/
	UFUNCTION(BlueprintCallable, Category = "Player")
	virtual float TakeDamage( float DamageTaken, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser ) override;

private:
	/** Camera boom positioning the camera behind the character. **/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	/** Camera that follows the character **/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;

	/** Base Turn Rate, in degrees/second. Other scaling may affect final turn rate **/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	float BaseTurnRate;

	/** Base Look-Up / Down rate, in degrees / second. Other scaling may affect final turn rate **/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	float BaseLookUpRate;

	/** Turn rate while not aiming **/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	float HipTurnRate;

	/** Look Up rate when not aiming **/ 
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	float HipLookUpRate;
	
	/** Turn rate when aiming **/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	float AimingTurnRate;

	/** Scale factor for mouse look sensitivity. Turn rate when not aiming. **/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"), meta = (ClampMin = "0.0", ClampMax = "1.0", UIMin = "0.0", UIMax = "1.0"))
	float MouseHipTurnRate;

	/** Scale factor for mouse look sensitivity. Look up rate when not aiming. **/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"), meta = (ClampMin = "0.0", ClampMax = "1.0", UIMin = "0.0", UIMax = "1.0"))
	float MouseHipLookUpRate;

	/** Scale factor for mouse look sensitivity. Turn rate when aiming. **/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"), meta = (ClampMin = "0.0", ClampMax = "1.0", UIMin = "0.0", UIMax = "1.0"))
	float MouseAimingTurnRate;

	/** Scale factor for mouse look sensitivity. Look up rate when aiming. **/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"), meta = (ClampMin = "0.0", ClampMax = "1.0", UIMin = "0.0", UIMax = "1.0"))
	float MouseAimingLookUpRate;
	
	

	/** Look up rate when aiming **/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	float AimingLookUpRate;

	
public:
	/** Returns CameraBoom **/
	FORCEINLINE USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	/** Returns FollowCamera **/
	FORCEINLINE UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};
