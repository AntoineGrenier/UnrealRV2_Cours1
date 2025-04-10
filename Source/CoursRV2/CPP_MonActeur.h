// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_MonActeur.generated.h"

// D�claration d'une �num�ration pour les �tats de l'acteur
UENUM(BlueprintType)
enum class EActorStatus : uint8
{
    Idle UMETA(DisplayName = "Idle"),
    Moving UMETA(DisplayName = "Moving"),
    Attacking UMETA(DisplayName = "Attacking")
};

// D�claration d'une structure pour stocker les donn�es de l'acteur
USTRUCT(BlueprintType)
struct FActorAttributes
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, Category = "Attributes")
    int32 Health;

    UPROPERTY(BlueprintReadWrite, Category = "Attributes")
    int32 Strength;

    UPROPERTY(BlueprintReadWrite, Category = "Attributes")
    FString Name;

    FActorAttributes()
        : Health(100), Strength(50), Name(TEXT("Default")) {
    }
};

UCLASS()
class COURSRV2_API ACPP_MonActeur : public AActor
{
	GENERATED_BODY()
	
public:
    // Constructeur
    ACPP_MonActeur();

protected:
    // Appel� au d�but du jeu
    virtual void BeginPlay() override;

public:
    // Appel� chaque frame
    virtual void Tick(float DeltaTime) override;

    // Fonction pour mettre � jour les attributs
    UFUNCTION(BlueprintCallable, Category = "Attributes")
    void UpdateAttributes(int32 NewHealth, int32 NewStrength);

    // Fonction pour g�rer les �tats de l'acteur
    UFUNCTION(BlueprintCallable, Category = "State")
    void ChangeStatus(EActorStatus NewStatus);

private:
    // Exemple de TArray pour stocker des messages
    TArray<FString> Messages;

    // Exemple de TMap pour stocker des statistiques cl�s-valeurs
    TMap<FString, int32> Statistics;

    // Exemple de TSet pour stocker des tags uniques
    TSet<FString> Tags;

    // �num�ration repr�sentant l'�tat actuel de l'acteur
    UPROPERTY(BlueprintReadWrite, Category = "State", meta = (AllowPrivateAccess = "true"))
    EActorStatus Status;

    // Structure contenant les attributs de l'acteur
    UPROPERTY(BlueprintReadWrite, Category = "Attributes", meta = (AllowPrivateAccess = "true"))
    FActorAttributes Attributes;

};
