#pragma once

#include "CoreMinimal.h"
#include "Subsystem/ModSubsystem.h"
#include "InfiniteZoopSubsystem.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(InfiniteZoop_Log, Display, All);

USTRUCT(BlueprintType)
struct INFINITEZOOP_API FZoopAmountStruct
{
	GENERATED_BODY()

		UPROPERTY(BlueprintReadWrite, Category = "Zoop Subsystem")
		int xAmount = -1;
	UPROPERTY(BlueprintReadWrite, Category = "Zoop Subsystem")
		int yAmount = -1;
	UPROPERTY(BlueprintReadWrite, Category = "Zoop Subsystem")
		int zAmount = -1;
	UPROPERTY(BlueprintReadWrite, Category = "Zoop Subsystem")
		bool isFoundation = true;
	UPROPERTY(BlueprintReadWrite, Category = "Zoop Subsystem")
		bool needsUpdate = true;
};

UCLASS()
class AInfiniteZoopSubsystem : public AModSubsystem
{
	GENERATED_BODY()
public:
	AInfiniteZoopSubsystem();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UPROPERTY(BlueprintReadWrite)
	TMap<APawn*, FZoopAmountStruct> ZoopAmountStructs;

	mutable FCriticalSection* csection;

	UPROPERTY(BlueprintReadWrite, replicated, Category = "Zoop Subsystem")
	int currentZoopAmount = 12;

	UPROPERTY(BlueprintReadWrite, Category = "Zoop Subsystem")
		int xAmount = -1;
	UPROPERTY(BlueprintReadWrite, Category = "Zoop Subsystem")
		int yAmount = -1;
	UPROPERTY(BlueprintReadWrite, Category = "Zoop Subsystem")
		int zAmount = -1;
	UPROPERTY(BlueprintReadWrite, Category = "Zoop Subsystem")
		bool isFoundation = true;
	UPROPERTY(BlueprintReadWrite, Category = "Zoop Subsystem")
		bool needsUpdate = true;

	void SetPublicZoopAmount(int x, int y, int z, bool foundation, bool verticalZoop, APawn* owner, FCriticalSection* lockObj);
	//UPROPERTY(BlueprintReadWrite, Category = "Zoop Subsystem")
	//bool zoopCorners = false;

	//UPROPERTY(BlueprintReadWrite, Category = "Zoop Subsystem")
	//int tempZoopAmount = 0;
};

