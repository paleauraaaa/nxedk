#ifndef _NXEDK_XBOXKRNL_H_
#define _NXEDK_XBOXKRNL_H_

#include "windef.h"

/* Prototypes are inferred from Xenia and community declarations, not retail ABI tests.
   Empty parameter lists mark unknown signatures; do not call them as declared. */
#ifdef __cplusplus
extern "C"
{
#endif

DECLSPEC_IMPORT VOID NTAPI DbgBreakPoint(void);

DECLSPEC_IMPORT
VOID
NTAPI
DbgBreakPointWithStatus(
    ULONG status
    );

DECLSPEC_IMPORT VOID NTAPI DbgPrint(CONST CHAR *format, ...);

DECLSPEC_IMPORT
VOID
NTAPI
DbgPrompt(
    CONST CHAR *prompt,
    CHAR *response,
    ULONG response_size
    );

DECLSPEC_IMPORT
BOOL
NTAPI
DumpGetRawDumpInfo(
    PVOID a1,
    BOOL a2
    );

DECLSPEC_IMPORT
ULONG
NTAPI
DumpWriteDump(
    ULONG a1,
    ULONG a2,
    ULONG a3
    );

DECLSPEC_IMPORT VOID NTAPI ExAcquireReadWriteLockExclusive( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI ExAcquireReadWriteLockShared( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI ExAllocatePool( /* unknown */ );

DECLSPEC_IMPORT PVOID NTAPI ExAllocatePoolWithTag(ULONG size, ULONG tag);

DECLSPEC_IMPORT VOID NTAPI ExAllocatePoolTypeWithTag( /* unknown */ );

EXTERN_C DECLSPEC_IMPORT struct _NXEDK_OPAQUE_EXPORT ExConsoleGameRegion;

DECLSPEC_IMPORT
NTSTATUS
NTAPI
ExCreateThread(
    PHANDLE Handle,
    DWORD StackSize,
    PDWORD ThreadId,
    PVOID XapiThreadStartup,
    THREAD_START_ROUTINE StartAddress,
    PVOID StartContext,
    DWORD CreationFlags
    );

EXTERN_C DECLSPEC_IMPORT struct _NXEDK_OPAQUE_EXPORT ExEventObjectType;

DECLSPEC_IMPORT VOID NTAPI ExFreePool(PVOID address);

DECLSPEC_IMPORT
ULONG
NTAPI
ExGetXConfigSetting(
    USHORT category,
    USHORT setting,
    PVOID buffer_ptr,
    USHORT buffer_size,
    USHORT *required_size_ptr
    );

DECLSPEC_IMPORT
VOID
NTAPI
ExInitializeReadWriteLock(
    X_ERWLOCK *lock_ptr
    );

EXTERN_C DECLSPEC_IMPORT struct _NXEDK_OPAQUE_EXPORT ExMutantObjectType;

DECLSPEC_IMPORT
ULONG
NTAPI
ExQueryPoolBlockSize(
    PVOID address
    );

DECLSPEC_IMPORT VOID NTAPI ExRegisterThreadNotification( /* unknown */ );

DECLSPEC_IMPORT
VOID
NTAPI
ExRegisterTitleTerminateNotification(
    X_EX_TITLE_TERMINATE_REGISTRATION *reg,
    ULONG create
    );

DECLSPEC_IMPORT VOID NTAPI ExReleaseReadWriteLock( /* unknown */ );

EXTERN_C DECLSPEC_IMPORT struct _NXEDK_OPAQUE_EXPORT ExSemaphoreObjectType;

DECLSPEC_IMPORT
ULONG
NTAPI
ExSetXConfigSetting(
    USHORT category,
    USHORT setting,
    PVOID buffer_ptr,
    ULONG buffer_size
    );

DECLSPEC_IMPORT
ULONG
NTAPI
ExTerminateThread(
    ULONG exit_code
    );

DECLSPEC_IMPORT VOID NTAPI ExTerminateTitleProcess( /* unknown */ );

EXTERN_C DECLSPEC_IMPORT struct _NXEDK_OPAQUE_EXPORT ExThreadObjectType;

EXTERN_C DECLSPEC_IMPORT struct _NXEDK_OPAQUE_EXPORT ExTimerObjectType;

DECLSPEC_IMPORT
VOID
NTAPI
MmDoubleMapMemory(
    PVOID tgt_virtual_address,
    PVOID src_virtual_address,
    ULONG page_count,
    DWORD Flags
    );

DECLSPEC_IMPORT
VOID
NTAPI
MmUnmapMemory(
    PVOID virtual_address,
    ULONG page_count
    );

DECLSPEC_IMPORT VOID NTAPI XeKeysGetConsoleCertificate( /* unknown */ );

DECLSPEC_IMPORT
ULONG
NTAPI
FscGetCacheElementCount(
    ULONG r3
    );

DECLSPEC_IMPORT
ULONG
NTAPI
FscSetCacheElementCount(
    ULONG unk_0,
    ULONG unk_1
    );

DECLSPEC_IMPORT ULONG NTAPI HalGetCurrentAVPack(void);

DECLSPEC_IMPORT
ULONG
NTAPI
HalGpioControl(
    ULONG idx,
    ULONG val,
    ULONG mask
    );

DECLSPEC_IMPORT
VOID
NTAPI
HalOpenCloseODDTray(
    ULONG open_close
    );

DECLSPEC_IMPORT
VOID
NTAPI
HalReadWritePCISpace(
    UCHAR bus,
    UCHAR dev,
    UCHAR fn,
    PVOID data,
    ULONG size,
    BOOL read_or_write
    );

DECLSPEC_IMPORT
VOID
NTAPI
HalRegisterPowerDownNotification(
    ULONG *a1,
    BOOL a2
    );

DECLSPEC_IMPORT
VOID
NTAPI
HalRegisterSMCNotification(
    ULONG *a1,
    BOOL a2
    );

DECLSPEC_IMPORT
VOID
NTAPI
HalReturnToFirmware(
    ULONG routine
    );

DECLSPEC_IMPORT
VOID
NTAPI
HalSendSMCMessage(
    X_SMC_DATA *smc_message,
    X_SMC_DATA *smc_response
    );

DECLSPEC_IMPORT
VOID
NTAPI
HalSetAudioEnable(
    BOOL state
    );

DECLSPEC_IMPORT
PVOID 
NTAPI
InterlockedFlushSList(
    X_SLIST_HEADER *plist_ptr
    );

DECLSPEC_IMPORT
PVOID 
NTAPI
InterlockedPopEntrySList(
    X_SLIST_HEADER *plist_ptr
    );

DECLSPEC_IMPORT
PVOID 
NTAPI
InterlockedPushEntrySList(
    X_SLIST_HEADER *plist_ptr,
    X_SINGLE_LIST_ENTRY *entry
    );

DECLSPEC_IMPORT VOID NTAPI IoAcquireDeviceObjectLock( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI IoAllocateIrp( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI IoBuildAsynchronousFsdRequest( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI IoBuildDeviceIoControlRequest( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI IoBuildSynchronousFsdRequest( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI IoCallDriver( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI IoCheckShareAccess( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI IoCompleteRequest( /* unknown */ );

EXTERN_C DECLSPEC_IMPORT struct _NXEDK_OPAQUE_EXPORT IoCompletionObjectType;

DECLSPEC_IMPORT VOID NTAPI IoCreateDevice( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI IoCreateFile( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI IoDeleteDevice( /* unknown */ );

EXTERN_C DECLSPEC_IMPORT struct _NXEDK_OPAQUE_EXPORT IoDeviceObjectType;

DECLSPEC_IMPORT VOID NTAPI IoDismountVolume( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI IoDismountVolumeByFileHandle( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI IoDismountVolumeByName( /* unknown */ );

EXTERN_C DECLSPEC_IMPORT struct _NXEDK_OPAQUE_EXPORT IoFileObjectType;

DECLSPEC_IMPORT VOID NTAPI IoFreeIrp( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI IoInitializeIrp( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI IoInvalidDeviceRequest( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI ExSetBetaFeaturesEnabled( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI IoQueueThreadIrp( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI IoReleaseDeviceObjectLock( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI IoRemoveShareAccess( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI IoSetIoCompletion( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI IoSetShareAccess( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI IoStartNextPacket( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI IoStartNextPacketByKey( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI IoStartPacket( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI IoSynchronousDeviceIoControlRequest( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI IoSynchronousFsdRequest( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeAcquireSpinLockAtRaisedIrql( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeAlertResumeThread( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeAlertThread( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeBlowFuses( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeBoostPriorityThread( /* unknown */ );

DECLSPEC_IMPORT
VOID
NTAPI
KeBugCheck(
    ULONG code
    );

DECLSPEC_IMPORT
VOID
NTAPI
KeBugCheckEx(
    ULONG code,
    ULONG param1,
    ULONG param2,
    ULONG param3,
    ULONG param4
    );

DECLSPEC_IMPORT VOID NTAPI KeCancelTimer( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeConnectInterrupt( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeContextFromKframes( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeContextToKframes( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeCreateUserMode( /* unknown */ );

EXTERN_C DECLSPEC_IMPORT struct _NXEDK_OPAQUE_EXPORT KeDebugMonitorData;

DECLSPEC_IMPORT
NTSTATUS
NTAPI
KeDelayExecutionThread(
    ULONG ProcessorMode,
    BOOLEAN Alertable,
    PLARGE_INTEGER Interval
    );

DECLSPEC_IMPORT VOID NTAPI KeDeleteUserMode( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeDisconnectInterrupt( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeEnableFpuExceptions( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeEnablePPUPerformanceMonitor( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeEnterCriticalRegion(void);

DECLSPEC_IMPORT VOID NTAPI KeEnterUserMode( /* unknown */ );

DECLSPEC_IMPORT
VOID
NTAPI
KeFlushCacheRange(
    PVOID base_address,
    ULONG size
    );

DECLSPEC_IMPORT VOID NTAPI KeFlushCurrentEntireTb( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeFlushEntireTb( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeFlushUserModeCurrentTb( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeFlushUserModeTb( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeGetCurrentProcessType( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeGetPMWRegister( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeGetPRVRegister( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeGetSocRegister( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeGetSpecialPurposeRegister( /* unknown */ );

DECLSPEC_IMPORT ULONG NTAPI KeLockL2(void);

DECLSPEC_IMPORT VOID NTAPI KeUnlockL2(void);

DECLSPEC_IMPORT
VOID
NTAPI
KeInitializeApc(
    XAPC *apc,
    PVOID thread_ptr,
    PVOID kernel_routine,
    PVOID rundown_routine,
    PVOID normal_routine,
    ULONG processor_mode,
    PVOID normal_context
    );

DECLSPEC_IMPORT VOID NTAPI KeInitializeDeviceQueue( /* unknown */ );

DECLSPEC_IMPORT
VOID
NTAPI
KeInitializeDpc(
    XDPC *dpc,
    PVOID routine,
    PVOID context
    );

DECLSPEC_IMPORT
VOID
NTAPI
KeInitializeEvent(
    X_KEVENT *event_ptr,
    ULONG event_type,
    ULONG initial_state
    );

DECLSPEC_IMPORT VOID NTAPI KeInitializeInterrupt( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeInitializeMutant( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeInitializeQueue( /* unknown */ );

DECLSPEC_IMPORT
VOID
NTAPI
KeInitializeSemaphore(
    X_KSEMAPHORE *semaphore_ptr,
    ULONG count,
    ULONG limit
    );

DECLSPEC_IMPORT VOID NTAPI KeInitializeTimerEx( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeInsertByKeyDeviceQueue( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeInsertDeviceQueue( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeInsertHeadQueue( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeInsertQueue( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeInsertQueueApc( /* unknown */ );

DECLSPEC_IMPORT
ULONG
NTAPI
KeInsertQueueDpc(
    XDPC *dpc,
    ULONG arg1,
    ULONG arg2
    );

DECLSPEC_IMPORT VOID NTAPI KeIpiGenericCall( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeLeaveCriticalRegion(void);

DECLSPEC_IMPORT VOID NTAPI KeLeaveUserMode( /* unknown */ );

DECLSPEC_IMPORT
ULONG
NTAPI
KePulseEvent(
    X_KEVENT *event_ptr,
    ULONG increment,
    ULONG wait
    );

DECLSPEC_IMPORT VOID NTAPI KeQueryBackgroundProcessors( /* unknown */ );

DECLSPEC_IMPORT
ULONG
NTAPI
KeQueryBasePriorityThread(
    PVOID thread_ptr
    );

DECLSPEC_IMPORT ULONGLONG NTAPI KeQueryInterruptTime(void);

DECLSPEC_IMPORT ULONG NTAPI KeQueryPerformanceFrequency(void);

DECLSPEC_IMPORT VOID NTAPI KeQuerySystemTime( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeRaiseIrqlToDpcLevel( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeRegisterDriverNotification( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeReleaseMutant( /* unknown */ );

DECLSPEC_IMPORT
ULONG
NTAPI
KeReleaseSemaphore(
    X_KSEMAPHORE *semaphore_ptr,
    ULONG increment,
    ULONG adjustment,
    ULONG wait
    );

DECLSPEC_IMPORT VOID NTAPI KeReleaseSpinLockFromRaisedIrql( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeRemoveByKeyDeviceQueue( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeRemoveDeviceQueue( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeRemoveEntryDeviceQueue( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeRemoveQueue( /* unknown */ );

DECLSPEC_IMPORT
ULONG
NTAPI
KeRemoveQueueDpc(
    XDPC *dpc
    );

DECLSPEC_IMPORT
ULONG
NTAPI
KeResetEvent(
    X_KEVENT *event_ptr
    );

DECLSPEC_IMPORT VOID NTAPI KeRestoreFloatingPointState( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeRestoreVectorUnitState( /* unknown */ );

DECLSPEC_IMPORT
ULONG
NTAPI
KeResumeThread(
    X_KTHREAD *thread_ptr
    );

DECLSPEC_IMPORT VOID NTAPI KeRetireDpcList( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeRundownQueue( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeSaveFloatingPointState( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeSaveVectorUnitState( /* unknown */ );

DECLSPEC_IMPORT
ULONG
NTAPI
KeSetAffinityThread(
    PVOID thread_ptr,
    ULONG affinity,
    ULONG *previous_affinity_ptr
    );

DECLSPEC_IMPORT VOID NTAPI KeSetBackgroundProcessors( /* unknown */ );

DECLSPEC_IMPORT
ULONG
NTAPI
KeSetBasePriorityThread(
    PVOID thread_ptr,
    ULONG increment
    );

DECLSPEC_IMPORT VOID NTAPI KeSetCurrentProcessType( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeSetCurrentStackPointers( /* unknown */ );

DECLSPEC_IMPORT
ULONG
NTAPI
KeSetDisableBoostThread(
    X_KTHREAD *thread_ptr,
    ULONG disabled
    );

DECLSPEC_IMPORT
ULONG
NTAPI
KeSetEvent(
    X_KEVENT *event_ptr,
    ULONG increment,
    ULONG wait
    );

DECLSPEC_IMPORT VOID NTAPI KeSetEventBoostPriority( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeSetPMWRegister( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeSetPowerMode( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeSetPRVRegister( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeSetPriorityClassThread( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeSetPriorityThread( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeSetSocRegister( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeSetSpecialPurposeRegister( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeSetTimer( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeSetTimerEx( /* unknown */ );

DECLSPEC_IMPORT
VOID
NTAPI
KeStallExecutionProcessor(
    ULONG milliseconds
    );

DECLSPEC_IMPORT VOID NTAPI KeSuspendThread( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeSweepDcacheRange( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeSweepIcacheRange( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeTestAlertThread( /* unknown */ );

EXTERN_C DECLSPEC_IMPORT struct _NXEDK_OPAQUE_EXPORT KeTimeStampBundle;

DECLSPEC_IMPORT VOID NTAPI KeTryToAcquireSpinLockAtRaisedIrql( /* unknown */ );

DECLSPEC_IMPORT
ULONG
NTAPI
KeWaitForMultipleObjects(
    ULONG count,
    ULONG *objects_ptr,
    ULONG wait_type,
    ULONG wait_reason,
    ULONG processor_mode,
    ULONG alertable,
    ULONGLONG *timeout_ptr,
    PVOID wait_block_array_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
KeWaitForSingleObject(
    PVOID object_ptr,
    ULONG wait_reason,
    ULONG processor_mode,
    ULONG alertable,
    ULONGLONG *timeout_ptr
    );

DECLSPEC_IMPORT VOID NTAPI KfAcquireSpinLock( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KfRaiseIrql( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KfLowerIrql( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KfReleaseSpinLock( /* unknown */ );

EXTERN_C DECLSPEC_IMPORT struct _NXEDK_OPAQUE_EXPORT KiBugCheckData;

DECLSPEC_IMPORT
LDI_STATUS
NTAPI
LDICreateDecompression(
    ULONG *data_block_max,
    LDI_CONFIG *config,
    LDI_ALLOCATE *allocate_fn,
    LDI_FREE *free_fn,
    PVOID mem,
    ULONG *data_block_max_plus_1800,
    LDI_CONTEXT **out_context
    );

DECLSPEC_IMPORT
LDI_STATUS
NTAPI
LDIDecompress(
    LDI_CONTEXT *context,
    CONST PVOID compressed,
    ULONG compressed_size,
    PVOID decompressed,
    ULONG *in_out_decompressed_size
    );

DECLSPEC_IMPORT
LDI_STATUS
NTAPI
LDIDestroyDecompression(
    LDI_CONTEXT *context
    );

DECLSPEC_IMPORT
ULONG
NTAPI
MmAllocatePhysicalMemory(
    DWORD Flags,
    SIZE_T RegionSize,
    ULONG Protect
    );

DECLSPEC_IMPORT
PVOID
NTAPI
MmAllocatePhysicalMemoryEx(
    DWORD Flags,
    SIZE_T RegionSize,
    DWORD Protect,
    DWORD min_addr_range,
    DWORD max_addr_range,
    DWORD alignment
    );

DECLSPEC_IMPORT
ULONG
NTAPI
MmCreateKernelStack(
    ULONG stack_size,
    ULONG r4
    );

DECLSPEC_IMPORT
ULONG
NTAPI
MmDeleteKernelStack(
    PVOID stack_base,
    PVOID stack_end
    );

DECLSPEC_IMPORT
VOID
NTAPI
MmFreePhysicalMemory(
    DWORD Type,
    PVOID BaseAddress
    );

DECLSPEC_IMPORT
ULONG
NTAPI
MmGetPhysicalAddress(
    PVOID BaseAddress
    );

DECLSPEC_IMPORT VOID NTAPI MmIsAddressValid( /* unknown */ );

DECLSPEC_IMPORT
PVOID 
NTAPI
MmLockAndMapSegmentArray(
    REGION region,
    PVOID *segments,
    ULONG size_in_bytes,
    DWORD Flags
    );

DECLSPEC_IMPORT
VOID
NTAPI
MmLockUnlockBufferPages(
    PVOID base_address,
    ULONG page_count,
    BOOL lock_unlock
    );

DECLSPEC_IMPORT
ULONG
NTAPI
MmMapIoSpace(
    ULONG unk0,
    PVOID src_address,
    ULONG size,
    DWORD Flags
    );

DECLSPEC_IMPORT
NTSTATUS
NTAPI
MmPersistPhysicalMemoryAllocation(
    PVOID address,
    ULONG unk
    );

DECLSPEC_IMPORT
ULONG
NTAPI
MmQueryAddressProtect(
    PVOID BaseAddress
    );

DECLSPEC_IMPORT
ULONG
NTAPI
MmQueryAllocationSize(
    PVOID base_address
    );

DECLSPEC_IMPORT
ULONG
NTAPI
MmQueryStatistics(
    X_MM_QUERY_STATISTICS_RESULT *stats_ptr
    );

DECLSPEC_IMPORT
VOID
NTAPI
MmSetAddressProtect(
    PVOID base_address,
    SIZE_T RegionSize,
    ULONG Protect
    );

DECLSPEC_IMPORT
VOID
NTAPI
MmSplitPhysicalMemoryAllocation(
    PVOID a1,
    PVOID a2
    );

DECLSPEC_IMPORT
VOID
NTAPI
MmUnlockAndUnmapSegmentArray(
    PVOID virtual_address
    );

DECLSPEC_IMPORT
VOID
NTAPI
MmUnmapIoSpace(
    PVOID base_address,
    ULONG size
    );

EXTERN_C DECLSPEC_IMPORT UCHAR Nls844UnicodeCaseTable[];

DECLSPEC_IMPORT
ULONG
NTAPI
NtAllocateVirtualMemory(
    PVOID BaseAddress,
    PSIZE_T RegionSize,
    ULONG AllocationType,
    ULONG Protect,
    ULONG debug_memory
    );

DECLSPEC_IMPORT
ULONG
NTAPI
NtCancelTimer(
    ULONG timer_handle,
    ULONG *current_state_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
NtClearEvent(
    HANDLE Handle
    );

DECLSPEC_IMPORT
ULONG
NTAPI
NtClose(
    HANDLE handle
    );

DECLSPEC_IMPORT VOID NTAPI NtCreateDirectoryObject( /* unknown */ );

DECLSPEC_IMPORT
ULONG
NTAPI
NtCreateEvent(
    PHANDLE Handle,
    POBJECT_ATTRIBUTES ObjectAttributes,
    EVENT_TYPE EventType,
    BOOLEAN InitialState
    );

DECLSPEC_IMPORT
ULONG
NTAPI
NtCreateFile(
    PHANDLE FileHandle,
    ACCESS_MASK DesiredAccess,
    POBJECT_ATTRIBUTES ObjectAttributes,
    PIO_STATUS_BLOCK IoStatusBlock,
    PLARGE_INTEGER AllocationSize,
    ULONG FileAttributes,
    ULONG ShareAccess,
    ULONG CreationDisposition,
    ULONG CreateOptions
    );

DECLSPEC_IMPORT
ULONG
NTAPI
NtCreateIoCompletion(
    ULONG *out_handle,
    ULONG desired_access,
    PVOID object_attribs,
    ULONG num_concurrent_threads
    );

DECLSPEC_IMPORT
ULONG
NTAPI
NtCreateMutant(
    ULONG *handle_out,
    POBJECT_ATTRIBUTES obj_attributes,
    ULONG initial_owner
    );

DECLSPEC_IMPORT
ULONG
NTAPI
NtCreateSemaphore(
    PHANDLE Handle,
    PVOID obj_attributes_ptr,
    ULONG count,
    ULONG limit
    );

DECLSPEC_IMPORT VOID NTAPI NtCreateSymbolicLinkObject( /* unknown */ );

DECLSPEC_IMPORT
ULONG
NTAPI
NtCreateTimer(
    PHANDLE Handle,
    PVOID obj_attributes_ptr,
    ULONG timer_type
    );

DECLSPEC_IMPORT VOID NTAPI NtDeleteFile( /* unknown */ );

DECLSPEC_IMPORT
ULONG
NTAPI
NtDeviceIoControlFile(
    HANDLE Handle,
    ULONG event_handle,
    ULONG apc_routine,
    ULONG apc_context,
    PIO_STATUS_BLOCK io_status_block,
    ULONG io_control_code,
    PVOID input_buffer,
    ULONG input_buffer_len,
    PVOID output_buffer,
    ULONG output_buffer_len
    );

DECLSPEC_IMPORT
ULONG
NTAPI
NtDuplicateObject(
    HANDLE Handle,
    ULONG *new_handle_ptr,
    ULONG options
    );

DECLSPEC_IMPORT
ULONG
NTAPI
NtFlushBuffersFile(
    HANDLE Handle,
    PIO_STATUS_BLOCK IoStatusBlock
    );

DECLSPEC_IMPORT
ULONG
NTAPI
NtFreeVirtualMemory(
    PVOID *BaseAddress,
    PSIZE_T RegionSize,
    ULONG FreeType,
    ULONG debug_memory
    );

DECLSPEC_IMPORT VOID NTAPI NtMakeTemporaryObject( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI NtOpenDirectoryObject( /* unknown */ );

DECLSPEC_IMPORT
ULONG
NTAPI
NtOpenFile(
    ULONG *handle_out,
    ULONG desired_access,
    POBJECT_ATTRIBUTES object_attributes,
    PIO_STATUS_BLOCK io_status_block,
    ULONG open_options
    );

DECLSPEC_IMPORT
ULONG
NTAPI
NtOpenSymbolicLinkObject(
    ULONG *handle_out,
    POBJECT_ATTRIBUTES object_attrs
    );

DECLSPEC_IMPORT
ULONG
NTAPI
NtProtectVirtualMemory(
    PVOID      *BaseAddress,
    PSIZE_T     RegionSize,
    ULONG       Protect,
    PULONG      OldProtect,
    ULONG       debug_memory
    );

DECLSPEC_IMPORT
ULONG
NTAPI
NtPulseEvent(
    HANDLE Handle,
    PLONG PreviousState
    );

DECLSPEC_IMPORT VOID NTAPI NtQueueApcThread( /* unknown */ );

DECLSPEC_IMPORT
NTSTATUS
NTAPI
NtQueryDirectoryFile(
    HANDLE file_handle,
    HANDLE event_handle,
    PIO_APC_ROUTINE apc_routine,
    PVOID apc_context,
    PIO_STATUS_BLOCK io_status_block,
    FILE_DIRECTORY_INFORMATION *file_info_ptr,
    ULONG length,
    ANSI_STRING *file_name,
    ULONG restart_scan
    );

DECLSPEC_IMPORT VOID NTAPI NtQueryDirectoryObject( /* unknown */ );

DECLSPEC_IMPORT
ULONG
NTAPI
NtQueryEvent(
    HANDLE Handle,
    ULONG *out_struc
    );

DECLSPEC_IMPORT
ULONG
NTAPI
NtQueryFullAttributesFile(
    POBJECT_ATTRIBUTES obj_attribs,
    X_FILE_NETWORK_OPEN_INFORMATION *file_info
    );

DECLSPEC_IMPORT
ULONG
NTAPI
NtQueryInformationFile(
    HANDLE Handle,
    PIO_STATUS_BLOCK IoStatusBlock,
    PVOID info_ptr,
    ULONG info_length,
    ULONG info_class
    );

DECLSPEC_IMPORT VOID NTAPI NtQueryIoCompletion( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI NtQueryMutant( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI NtQuerySemaphore( /* unknown */ );

DECLSPEC_IMPORT
ULONG
NTAPI
NtQuerySymbolicLinkObject(
    HANDLE Handle,
    X_ANSI_STRING *target
    );

DECLSPEC_IMPORT VOID NTAPI NtQueryTimer( /* unknown */ );

DECLSPEC_IMPORT
ULONG
NTAPI
NtQueryVirtualMemory(
    PVOID BaseAddress,
    X_MEMORY_BASIC_INFORMATION *MemoryBasicInformation,
    ULONG region_type
    );

DECLSPEC_IMPORT
ULONG
NTAPI
NtQueryVolumeInformationFile(
    HANDLE Handle,
    PIO_STATUS_BLOCK IoStatusBlock,
    PVOID info_ptr,
    ULONG info_length,
    ULONG info_class
    );

DECLSPEC_IMPORT
ULONG
NTAPI
NtReadFile(
    HANDLE Handle,
    HANDLE Event,
    PIO_APC_ROUTINE ApcRoutine,
    PVOID ApcContext,
    PIO_STATUS_BLOCK IoStatusBlock,
    PVOID Buffer,
    ULONG Length,
    PLARGE_INTEGER ByteOffset
    );

DECLSPEC_IMPORT
ULONG
NTAPI
NtReadFileScatter(
    HANDLE Handle,
    ULONG event_handle,
    PVOID apc_routine_ptr,
    PVOID apc_context,
    PIO_STATUS_BLOCK io_status_block,
    ULONG *segment_array,
    ULONG length,
    ULONGLONG *byte_offset_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
NtReleaseMutant(
    ULONG mutant_handle,
    ULONG *previous_count
    );

DECLSPEC_IMPORT
ULONG
NTAPI
NtReleaseSemaphore(
    ULONG sem_handle,
    ULONG release_count,
    ULONG *previous_count_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
NtRemoveIoCompletion(
    HANDLE Handle,
    ULONG *key_context,
    ULONG *apc_context,
    PIO_STATUS_BLOCK io_status_block,
    ULONGLONG *timeout
    );

DECLSPEC_IMPORT
ULONG
NTAPI
NtResumeThread(
    HANDLE Handle,
    ULONG *suspend_count_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
NtSetEvent(
    HANDLE Handle,
    PLONG PreviousState
    );

DECLSPEC_IMPORT
ULONG
NTAPI
NtSetInformationFile(
    HANDLE Handle,
    PIO_STATUS_BLOCK io_status_block,
    PVOID info_ptr,
    ULONG info_length,
    ULONG info_class
    );

DECLSPEC_IMPORT
ULONG
NTAPI
NtSetIoCompletion(
    HANDLE Handle,
    ULONG key_context,
    ULONG apc_context,
    ULONG completion_status,
    ULONG num_bytes
    );

DECLSPEC_IMPORT VOID NTAPI NtSetSystemTime( /* unknown */ );

DECLSPEC_IMPORT
ULONG
NTAPI
NtSetTimerEx(
    ULONG timer_handle,
    ULONGLONG *due_time_ptr,
    PVOID routine_ptr,
    ULONG mode,
    PVOID routine_arg,
    ULONG resume,
    ULONG period_ms,
    ULONG *unk_zero
    );

DECLSPEC_IMPORT
ULONG
NTAPI
NtSignalAndWaitForSingleObjectEx(
    ULONG signal_handle,
    ULONG wait_handle,
    ULONG wait_mode,
    ULONG alertable,
    ULONGLONG *timeout_ptr
    );

DECLSPEC_IMPORT VOID NTAPI NtSuspendThread( /* unknown */ );

DECLSPEC_IMPORT
ULONG
NTAPI
NtWaitForSingleObjectEx(
    HANDLE Handle,
    KPROCESSOR_MODE WaitMode,
    BOOLEAN Alertable,
    PLARGE_INTEGER Timeout
    );

DECLSPEC_IMPORT
ULONG
NTAPI
NtWaitForMultipleObjectsEx(
    ULONG count,
    ULONG *handles,
    ULONG wait_type,
    ULONG wait_mode,
    ULONG alertable,
    ULONGLONG *timeout_ptr
    );

DECLSPEC_IMPORT
NTSTATUS
NTAPI
NtWriteFile(
    HANDLE Handle,
    HANDLE Event,
    PIO_APC_ROUTINE ApcRoutine,
    PVOID ApcContext,
    PIO_STATUS_BLOCK IoStatusBlock,
    PVOID Buffer,
    ULONG Length,
    PLARGE_INTEGER ByteOffset
    );

DECLSPEC_IMPORT
NTSTATUS
NTAPI
NtWriteFileGather(
    HANDLE file_handle,
    HANDLE event_handle,
    PIO_APC_ROUTINE apc_routine,
    PVOID apc_context,
    PIO_STATUS_BLOCK io_status_block,
    PVOID segment_array,
    ULONG length,
    LONGLONG *byte_offset_ptr
    );

DECLSPEC_IMPORT ULONG NTAPI NtYieldExecution(void);

DECLSPEC_IMPORT VOID NTAPI ObCreateObject( /* unknown */ );

DECLSPEC_IMPORT
ULONG
NTAPI
ObCreateSymbolicLink(
    X_ANSI_STRING *path_ptr,
    X_ANSI_STRING *target_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
ObDeleteSymbolicLink(
    X_ANSI_STRING *path_ptr
    );

DECLSPEC_IMPORT VOID NTAPI ObDereferenceObject( /* unknown */ );

EXTERN_C DECLSPEC_IMPORT struct _NXEDK_OPAQUE_EXPORT ObDirectoryObjectType;

DECLSPEC_IMPORT VOID NTAPI ObGetWaitableObject( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI ObInsertObject( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI ObIsTitleObject( /* unknown */ );

DECLSPEC_IMPORT
ULONG
NTAPI
ObLookupAnyThreadByThreadId(
    ULONG thread_id,
    ULONG *out_object_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
ObLookupThreadByThreadId(
    ULONG thread_id,
    ULONG *out_object_ptr
    );

DECLSPEC_IMPORT VOID NTAPI ObMakeTemporaryObject( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI ObOpenObjectByName( /* unknown */ );

DECLSPEC_IMPORT
ULONG
NTAPI
ObOpenObjectByPointer(
    PVOID object_ptr,
    ULONG *out_handle_ptr
    );

DECLSPEC_IMPORT
VOID
NTAPI
ObReferenceObject(
    ULONG native_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
ObReferenceObjectByHandle(
    HANDLE Handle,
    ULONG object_type_ptr,
    ULONG *out_object_ptr
    );

DECLSPEC_IMPORT VOID NTAPI ObReferenceObjectByName( /* unknown */ );

EXTERN_C DECLSPEC_IMPORT struct _NXEDK_OPAQUE_EXPORT ObSymbolicLinkObjectType;

DECLSPEC_IMPORT VOID NTAPI ObTranslateSymbolicLink( /* unknown */ );

DECLSPEC_IMPORT
NTSTATUS
NTAPI
RtlAnsiStringToUnicodeString(
    UNICODE_STRING *dest,
    ANSI_STRING *src,
    BOOL allocate_dest
    );

DECLSPEC_IMPORT
NTSTATUS
NTAPI
RtlAppendStringToString(
    ANSI_STRING *dest,
    ANSI_STRING *src
    );

DECLSPEC_IMPORT
NTSTATUS
NTAPI
RtlAppendUnicodeStringToString(
    UNICODE_STRING *dest,
    UNICODE_STRING *src
    );

DECLSPEC_IMPORT
NTSTATUS
NTAPI
RtlAppendUnicodeToString(
    UNICODE_STRING *dest,
    WCHAR *src
    );

DECLSPEC_IMPORT
VOID
NTAPI
RtlAssert(
    CONST CHAR *cond,
    CONST CHAR *source_file,
    ULONG line,
    CONST CHAR *prefix
    );

DECLSPEC_IMPORT
VOID
NTAPI
RtlCaptureContext(
    PVOID out_context
    );

DECLSPEC_IMPORT
ULONG
NTAPI
RtlCompareMemory(
    PVOID source1,
    PVOID source2,
    ULONG length
    );

DECLSPEC_IMPORT
ULONG
NTAPI
RtlCompareMemoryUlong(
    PVOID source,
    ULONG length,
    ULONG pattern
    );

DECLSPEC_IMPORT
ULONG
NTAPI
RtlCompareString(
    PVOID string_1,
    PVOID string_2,
    ULONG case_insensitive
    );

DECLSPEC_IMPORT
ULONG
NTAPI
RtlCompareStringN(
    CONST CHAR *string_1,
    ULONG string_1_len,
    CONST CHAR *string_2,
    ULONG string_2_len,
    ULONG case_insensitive
    );

DECLSPEC_IMPORT
LONG
NTAPI
RtlCompareUnicodeString(
    UNICODE_STRING *s1,
    UNICODE_STRING *s2,
    BOOL case_insensitive
    );

DECLSPEC_IMPORT
LONG
NTAPI
RtlCompareUnicodeStringN(
    CONST WCHAR *s1,
    ULONG l1,
    CONST WCHAR *s2,
    ULONG l2,
    BOOL case_insensitive
    );

DECLSPEC_IMPORT
LONG
NTAPI
RtlCompareUtf8ToUnicode(
    CONST CHAR *s1,
    ULONG l1,
    CONST WCHAR *s2,
    ULONG l2,
    BOOL case_insensitive
    );

DECLSPEC_IMPORT
VOID
NTAPI
RtlCopyString(
    X_ANSI_STRING *destination,
    X_ANSI_STRING *source
    );

DECLSPEC_IMPORT
VOID
NTAPI
RtlCopyUnicodeString(
    X_UNICODE_STRING *destination,
    X_UNICODE_STRING *source
    );

DECLSPEC_IMPORT
BOOL
NTAPI
RtlCreateUnicodeString(
    UNICODE_STRING *unicode_str,
    CONST WCHAR *c_wstr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
RtlDowncaseUnicodeChar(
    USHORT unicode_char
    );

DECLSPEC_IMPORT
VOID
NTAPI
RtlEnterCriticalSection(
    X_RTL_CRITICAL_SECTION *cs
    );

DECLSPEC_IMPORT
VOID
NTAPI
RtlFillMemoryUlong(
    PVOID destination,
    ULONG length,
    ULONG pattern
    );

DECLSPEC_IMPORT
VOID
NTAPI
RtlFreeAnsiString(
    X_ANSI_STRING *string
    );

DECLSPEC_IMPORT
VOID
NTAPI
RtlFreeUnicodeString(
    X_UNICODE_STRING *string
    );

DECLSPEC_IMPORT
VOID
NTAPI
RtlGetCallersAddress(
    PVOID callers_address,
    PVOID callers_caller
    );

DECLSPEC_IMPORT VOID NTAPI RtlGetStackLimits( /* unknown */ );

DECLSPEC_IMPORT
PVOID 
NTAPI
RtlImageXexHeaderField(
    xex2_header *xex_header,
    ULONG field_dword
    );

DECLSPEC_IMPORT
VOID
NTAPI
RtlInitAnsiString(
    X_ANSI_STRING *destination,
    CONST CHAR *source
    );

DECLSPEC_IMPORT
PVOID 
NTAPI
RtlInitUnicodeString(
    X_UNICODE_STRING *destination,
    CONST USHORT *source
    );

DECLSPEC_IMPORT
VOID
NTAPI
RtlInitializeCriticalSection(
    X_RTL_CRITICAL_SECTION *cs
    );

DECLSPEC_IMPORT
ULONG
NTAPI
RtlInitializeCriticalSectionAndSpinCount(
    X_RTL_CRITICAL_SECTION *cs,
    ULONG spin_count
    );

DECLSPEC_IMPORT
VOID
NTAPI
RtlLeaveCriticalSection(
    X_RTL_CRITICAL_SECTION *cs
    );

DECLSPEC_IMPORT
PVOID 
NTAPI
RtlLookupFunctionEntry(
    PVOID a1
    );

DECLSPEC_IMPORT
ULONG
NTAPI
RtlLowerChar(
    ULONG in
    );

DECLSPEC_IMPORT
ULONG
NTAPI
RtlMultiByteToUnicodeN(
    USHORT *destination_ptr,
    ULONG destination_len,
    ULONG *written_ptr,
    UCHAR *source_ptr,
    ULONG source_len
    );

DECLSPEC_IMPORT
NTSTATUS
NTAPI
RtlMultiByteToUnicodeSize(
    ULONG *unicode_s_size,
    CONST CHAR *c_str,
    ULONG c_str_size
    );

DECLSPEC_IMPORT
ULONG
NTAPI
RtlNtStatusToDosError(
    ULONG source_status
    );

DECLSPEC_IMPORT
VOID
NTAPI
RtlRaiseException(
    X_EXCEPTION_RECORD *record
    );

DECLSPEC_IMPORT
VOID
NTAPI
RtlRaiseStatus(
    NTSTATUS status
    );

DECLSPEC_IMPORT VOID NTAPI RtlRip( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI _scprintf( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI RtlScprintf( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI _snprintf( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI RtlSnprintf( /* unknown */ );

/* Keep the kernel spelling from colliding with the C runtime declaration. */
#if defined(__clang__)
DECLSPEC_IMPORT VOID NTAPI NxkSprintf( /* unknown */ ) __asm__("sprintf");
#endif

DECLSPEC_IMPORT VOID NTAPI RtlSprintf( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI _scwprintf( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI RtlScwprintf( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI _snwprintf( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI RtlSnwprintf( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI swprintf( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI RtlSwprintf( /* unknown */ );

DECLSPEC_IMPORT
ULONG
NTAPI
RtlTimeFieldsToTime(
    X_TIME_FIELDS *time_fields_ptr,
    ULONGLONG *time_ptr
    );

DECLSPEC_IMPORT
VOID
NTAPI
RtlTimeToTimeFields(
    ULONGLONG *time_ptr,
    X_TIME_FIELDS *time_fields_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
RtlTryEnterCriticalSection(
    X_RTL_CRITICAL_SECTION *cs
    );

DECLSPEC_IMPORT
ULONG
NTAPI
RtlUnicodeStringToAnsiString(
    X_ANSI_STRING *destination_ptr,
    X_UNICODE_STRING *source_ptr,
    ULONG alloc_dest
    );

DECLSPEC_IMPORT
ULONG
NTAPI
RtlUnicodeToMultiByteN(
    UCHAR *destination_ptr,
    ULONG destination_len,
    ULONG *written_ptr,
    USHORT *source_ptr,
    ULONG source_len
    );

DECLSPEC_IMPORT
NTSTATUS
NTAPI
RtlUnicodeToMultiByteSize(
    ULONG *c_str_size,
    CONST WCHAR *unicode_s,
    ULONG unicode_s_size
    );

DECLSPEC_IMPORT
ULONG
NTAPI
RtlUnicodeToUtf8(
    CONST WCHAR *unicode_s,
    ULONG unicode_s_size,
    BOOL really_unicode_or_ascii,
    CHAR *utf8_s,
    ULONG utf8_s_size
    );

DECLSPEC_IMPORT
ULONG
NTAPI
RtlUnicodeToUtf8Size(
    CONST WCHAR *unicode_s,
    ULONG unicode_s_size,
    BOOL really_unicode_or_ascii
    );

DECLSPEC_IMPORT VOID NTAPI RtlUnwind(void);

DECLSPEC_IMPORT VOID NTAPI RtlUnwind2(void);

DECLSPEC_IMPORT
ULONG
NTAPI
RtlUpcaseUnicodeChar(
    ULONG SourceCharacter
    );

DECLSPEC_IMPORT
ULONG
NTAPI
RtlUpperChar(
    ULONG in
    );

DECLSPEC_IMPORT VOID NTAPI RtlVirtualUnwind(void);

DECLSPEC_IMPORT VOID NTAPI _vscprintf( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI RtlVscprintf( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI _vsnprintf( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI RtlVsnprintf( /* unknown */ );

#if defined(__clang__)
DECLSPEC_IMPORT VOID NTAPI NxkVsprintf( /* unknown */ ) __asm__("vsprintf");
#endif

DECLSPEC_IMPORT VOID NTAPI RtlVsprintf( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI _vscwprintf( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI RtlVscwprintf( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI _vsnwprintf( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI RtlVsnwprintf( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI vswprintf( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI RtlVswprintf( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeTlsAlloc( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI TlsAlloc( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeTlsFree( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI TlsFree( /* unknown */ );

DECLSPEC_IMPORT
ULONG
NTAPI
KeTlsGetValue(
    ULONG tls_index
    );

DECLSPEC_IMPORT
ULONG
NTAPI
TlsGetValue(
    ULONG tls_index
    );

DECLSPEC_IMPORT
ULONG
NTAPI
KeTlsSetValue(
    ULONG tls_index,
    ULONG tls_value
    );

DECLSPEC_IMPORT
ULONG
NTAPI
TlsSetValue(
    ULONG tls_index,
    ULONG tls_value
    );

EXTERN_C DECLSPEC_IMPORT struct _NXEDK_OPAQUE_EXPORT XboxHardwareInfo;

EXTERN_C DECLSPEC_IMPORT struct _NXEDK_OPAQUE_EXPORT XboxKrnlBaseVersion;

EXTERN_C DECLSPEC_IMPORT struct _NXEDK_OPAQUE_EXPORT XboxKrnlVersion;

DECLSPEC_IMPORT
VOID
NTAPI
XeCryptAesKey(
    XECRYPT_AES_STATE *state_ptr,
    PVOID key
    );

DECLSPEC_IMPORT
VOID
NTAPI
XeCryptAesEcb(
    XECRYPT_AES_STATE *state_ptr,
    PVOID inp_ptr,
    PVOID out_ptr,
    ULONG encrypt
    );

DECLSPEC_IMPORT
VOID
NTAPI
XeCryptAesCbc(
    XECRYPT_AES_STATE *state_ptr,
    PVOID inp_ptr,
    ULONG inp_size,
    PVOID out_ptr,
    PVOID feed_ptr,
    ULONG encrypt
    );

DECLSPEC_IMPORT
BOOL
NTAPI
XeCryptBnDwLeDhEqualBase(
    CONST ULONGLONG *input,
    CONST ULONGLONG *table
    );

DECLSPEC_IMPORT
BOOL
NTAPI
XeCryptBnDwLeDhInvalBase(
    CONST ULONGLONG *input,
    CONST ULONGLONG *table
    );

DECLSPEC_IMPORT
BOOL
NTAPI
XeCryptBnDwLeDhModExp(
    CONST ULONGLONG *input,
    CONST ULONGLONG *exponent,
    CONST ULONGLONG *output,
    CONST ULONGLONG *table
    );

DECLSPEC_IMPORT
VOID
NTAPI
XeCryptBnDw_Copy(
    CONST ULONG *source,
    ULONG *dest,
    ULONG dword_count
    );

DECLSPEC_IMPORT
VOID
NTAPI
XeCryptBnDw_SwapLeBe(
    CONST ULONG *input,
    ULONG *output,
    ULONG dword_count
    );

DECLSPEC_IMPORT
VOID
NTAPI
XeCryptBnDw_Zero(
    ULONG *data,
    ULONG dword_count
    );

DECLSPEC_IMPORT
VOID
NTAPI
XeCryptBnDwLePkcs1Format(
    CONST UCHAR *digest,
    LONG flags,
    UCHAR *output,
    ULONG size
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XeCryptBnDwLePkcs1Verify(
    PVOID hash,
    PVOID sig,
    ULONG size
    );

DECLSPEC_IMPORT
BOOL
NTAPI
XeCryptBnQwBeSigCreate(
    ULONGLONG *output,
    CONST UCHAR *hash,
    CONST UCHAR *salt,
    CONST UCHAR *rsakey
    );

DECLSPEC_IMPORT
VOID
NTAPI
XeCryptBnQwBeSigFormat(
    UCHAR *output,
    CONST UCHAR *hash,
    CONST UCHAR *salt
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XeCryptBnQwBeSigVerify(
    XECRYPT_SIG *sig,
    PVOID hash,
    CONST CHAR *salt,
    XECRYPT_RSA *rsa
    );

DECLSPEC_IMPORT
BOOL
NTAPI
XeCryptBnQwNeModExp(
    ULONGLONG *output,
    CONST ULONGLONG *input,
    CONST ULONGLONG *exponent,
    CONST ULONGLONG *modulus,
    ULONG size
    );

DECLSPEC_IMPORT
BOOL
NTAPI
XeCryptBnQwNeModExpRoot(
    ULONGLONG *output,
    CONST ULONGLONG *input,
    CONST ULONGLONG *P,
    CONST ULONGLONG *Q,
    CONST ULONGLONG *DP,
    CONST ULONGLONG *DQ,
    CONST ULONGLONG *CR,
    ULONG size
    );

DECLSPEC_IMPORT
ULONGLONG
NTAPI
XeCryptBnQwNeModInv(
    ULONGLONG input
    );

DECLSPEC_IMPORT
VOID
NTAPI
XeCryptBnQwNeModMul(
    CONST ULONGLONG *input1,
    CONST ULONGLONG *input2,
    ULONGLONG *output,
    ULONGLONG inverse_mod,
    CONST ULONGLONG *modulus,
    ULONG size
    );

DECLSPEC_IMPORT
BOOL
NTAPI
XeCryptBnQwNeRsaKeyGen(
    ULONG bitcount,
    ULONG pub_exponent,
    UCHAR *pub_rsakey,
    UCHAR *priv_rsakey
    );

DECLSPEC_IMPORT
BOOL
NTAPI
XeCryptBnQwNeRsaPrvCrypt(
    CONST ULONGLONG *input,
    ULONGLONG *output,
    UCHAR *rsakey
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XeCryptBnQwNeRsaPubCrypt(
    ULONGLONG *qw_a,
    ULONGLONG *qw_b,
    XECRYPT_RSA *rsa
    );

DECLSPEC_IMPORT
VOID
NTAPI
XeCryptBnQw_Copy(
    CONST ULONGLONG *source,
    ULONGLONG *dest,
    ULONG qword_count
    );

DECLSPEC_IMPORT
VOID
NTAPI
XeCryptBnQw_SwapDwQw(
    CONST ULONGLONG *input,
    ULONGLONG *output,
    ULONG dword_count
    );

DECLSPEC_IMPORT
VOID
NTAPI
XeCryptBnQw_SwapDwQwLeBe(
    ULONGLONG *qw_inp,
    ULONGLONG *qw_out,
    ULONG size
    );

DECLSPEC_IMPORT
VOID
NTAPI
XeCryptBnQw_SwapLeBe(
    CONST ULONGLONG *input,
    ULONGLONG *output,
    ULONG qword_count
    );

DECLSPEC_IMPORT
VOID
NTAPI
XeCryptBnQw_Zero(
    ULONGLONG *buffer,
    ULONG qword_count
    );

DECLSPEC_IMPORT
VOID
NTAPI
XeCryptChainAndSumMac(
    CONST ULONG *cd,
    CONST ULONG *ab,
    CONST ULONG *input,
    ULONG dword_count,
    ULONG *output
    );

DECLSPEC_IMPORT
VOID
NTAPI
XeCryptDesParity(
    PVOID inp,
    ULONG inp_size,
    PVOID out_ptr
    );

DECLSPEC_IMPORT
VOID
NTAPI
XeCryptDesKey(
    XECRYPT_DES_STATE *state_ptr,
    ULONGLONG *key
    );

DECLSPEC_IMPORT
VOID
NTAPI
XeCryptDesEcb(
    XECRYPT_DES_STATE *state_ptr,
    ULONGLONG *inp,
    ULONGLONG *out,
    ULONG encrypt
    );

DECLSPEC_IMPORT
VOID
NTAPI
XeCryptDesCbc(
    CONST CRYPT_DES_STATE *state,
    CONST UCHAR *input,
    ULONG size,
    UCHAR *output,
    UCHAR *feed,
    BOOL encrypt
    );

DECLSPEC_IMPORT
VOID
NTAPI
XeCryptDes3Key(
    XECRYPT_DES3_STATE *state_ptr,
    ULONGLONG *key
    );

DECLSPEC_IMPORT
VOID
NTAPI
XeCryptDes3Ecb(
    XECRYPT_DES3_STATE *state_ptr,
    ULONGLONG *inp,
    ULONGLONG *out,
    ULONG encrypt
    );

DECLSPEC_IMPORT
VOID
NTAPI
XeCryptDes3Cbc(
    XECRYPT_DES3_STATE *state_ptr,
    ULONGLONG *inp,
    ULONG inp_size,
    ULONGLONG *out,
    ULONGLONG *feed,
    ULONG encrypt
    );

DECLSPEC_IMPORT
VOID
NTAPI
XeCryptHmacMd5Init(
    CRYPT_HMAC_MD5_STATE *state,
    CONST UCHAR *key,
    ULONG key_size
    );

DECLSPEC_IMPORT
VOID
NTAPI
XeCryptHmacMd5Update(
    CRYPT_HMAC_MD5_STATE *state,
    CONST UCHAR *input,
    ULONG input_size
    );

DECLSPEC_IMPORT
VOID
NTAPI
XeCryptHmacMd5Final(
    CRYPT_HMAC_MD5_STATE *state,
    UCHAR *digest,
    ULONG digest_size
    );

DECLSPEC_IMPORT
VOID
NTAPI
XeCryptHmacMd5(
    CONST UCHAR *input1,
    ULONG input1_size,
    CONST UCHAR *input2,
    ULONG input2_size,
    CONST UCHAR *input3,
    ULONG input3_size,
    UCHAR *digest,
    ULONG digest_size
    );

DECLSPEC_IMPORT
VOID
NTAPI
XeCryptHmacShaInit(
    XECRYPT_HMACSHA_STATE *sha_state_ptr,
    PVOID key_ptr,
    ULONG key_size
    );

DECLSPEC_IMPORT
VOID
NTAPI
XeCryptHmacShaUpdate(
    XECRYPT_HMACSHA_STATE *sha_state_ptr,
    PVOID input,
    ULONG input_size
    );

DECLSPEC_IMPORT
VOID
NTAPI
XeCryptHmacShaFinal(
    XECRYPT_HMACSHA_STATE *sha_state_ptr,
    UCHAR *out,
    ULONG out_size
    );

DECLSPEC_IMPORT
VOID
NTAPI
XeCryptHmacSha(
    PVOID key,
    ULONG key_size_in,
    PVOID inp_1,
    ULONG inp_1_size,
    PVOID inp_2,
    ULONG inp_2_size,
    PVOID inp_3,
    ULONG inp_3_size,
    PVOID out,
    ULONG out_size
    );

DECLSPEC_IMPORT
VOID
NTAPI
XeCryptHmacShaVerify(
    CONST UCHAR *input1,
    ULONG input1_size,
    CONST UCHAR *input2,
    ULONG input2_size,
    CONST UCHAR *input3,
    ULONG input3_size,
    CONST UCHAR *expected_digest,
    ULONG expected_digest_size
    );

DECLSPEC_IMPORT
VOID
NTAPI
XeCryptMd5Init(
    XECRYPT_MD5_STATE *md5_state
    );

DECLSPEC_IMPORT
VOID
NTAPI
XeCryptMd5Update(
    XECRYPT_MD5_STATE *md5_state,
    PVOID input,
    ULONG input_size
    );

DECLSPEC_IMPORT
VOID
NTAPI
XeCryptMd5Final(
    XECRYPT_MD5_STATE *md5_state,
    UCHAR *out,
    ULONG out_size
    );

DECLSPEC_IMPORT
VOID
NTAPI
XeCryptMd5(
    PVOID input_1,
    ULONG input_1_size,
    PVOID input_2,
    ULONG input_2_size,
    PVOID input_3,
    ULONG input_3_size,
    PVOID output,
    ULONG output_size
    );

DECLSPEC_IMPORT
VOID
NTAPI
XeCryptParveEcb(
    CONST UCHAR *key,
    CONST UCHAR *sbox,
    CONST UCHAR *input,
    UCHAR *output
    );

DECLSPEC_IMPORT
VOID
NTAPI
XeCryptParveCbcMac(
    CONST UCHAR *key,
    CONST UCHAR *sbox,
    CONST UCHAR *iv,
    CONST UCHAR *input,
    ULONG size,
    UCHAR *output
    );

DECLSPEC_IMPORT
VOID
NTAPI
XeCryptRandom(
    PVOID buf,
    ULONG buf_size
    );

DECLSPEC_IMPORT
VOID
NTAPI
XeCryptRc4Key(
    XECRYPT_RC4_STATE *rc4_ctx,
    PVOID key,
    ULONG key_size
    );

DECLSPEC_IMPORT
VOID
NTAPI
XeCryptRc4Ecb(
    XECRYPT_RC4_STATE *rc4_ctx,
    PVOID data,
    ULONG size
    );

DECLSPEC_IMPORT
VOID
NTAPI
XeCryptRc4(
    PVOID key,
    ULONG key_size,
    PVOID data,
    ULONG size
    );

DECLSPEC_IMPORT
VOID
NTAPI
XeCryptRotSumSha(
    PVOID inp_1,
    ULONG inp_1_size,
    PVOID inp_2,
    ULONG inp_2_size,
    PVOID out,
    ULONG out_size
    );

DECLSPEC_IMPORT
VOID
NTAPI
XeCryptShaInit(
    XECRYPT_SHA_STATE *sha_state
    );

DECLSPEC_IMPORT
VOID
NTAPI
XeCryptShaUpdate(
    XECRYPT_SHA_STATE *sha_state,
    PVOID input,
    ULONG input_size
    );

DECLSPEC_IMPORT
VOID
NTAPI
XeCryptShaFinal(
    XECRYPT_SHA_STATE *sha_state,
    UCHAR *out,
    ULONG out_size
    );

DECLSPEC_IMPORT
VOID
NTAPI
XeCryptSha(
    PVOID input_1,
    ULONG input_1_size,
    PVOID input_2,
    ULONG input_2_size,
    PVOID input_3,
    ULONG input_3_size,
    PVOID output,
    ULONG output_size
    );

EXTERN_C DECLSPEC_IMPORT HMODULE XexExecutableModuleHandle;

DECLSPEC_IMPORT
ULONG
NTAPI
XexCheckExecutablePrivilege(
    ULONG privilege
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XexGetModuleHandle(
    CONST CHAR *module_name,
    ULONG *hmodule_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XexGetModuleSection(
    PVOID hmodule,
    CONST CHAR *name,
    ULONG *data_ptr,
    ULONG *size_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XexGetProcedureAddress(
    PVOID hmodule,
    ULONG ordinal,
    ULONG *out_function_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XexLoadExecutable(
    CONST CHAR *module_name,
    ULONG module_flags,
    ULONG min_version,
    ULONG *hmodule_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XexLoadImage(
    CONST CHAR *module_name,
    ULONG module_flags,
    ULONG min_version,
    ULONG *hmodule_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XexLoadImageFromMemory(
    ULONG *buffer,
    ULONG size,
    CONST CHAR *module_name,
    ULONG module_flags,
    ULONG min_version,
    ULONG *hmodule_ptr
    );

DECLSPEC_IMPORT VOID NTAPI XexLoadImageHeaders( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XexPcToFileHeader( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KiApcNormalRoutineNop_( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XexRegisterLoader( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XexRegisterPatchDescriptor( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XexSendDeferredNotifications( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XexStartExecutable( /* unknown */ );

DECLSPEC_IMPORT
ULONG
NTAPI
XexUnloadImage(
    PVOID hmodule
    );

DECLSPEC_IMPORT VOID NTAPI XexUnloadImageAndExitThread( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XexUnloadTitleModules( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XexVerifyImageHeaders( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI __C_specific_handler( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI DbgLoadImageSymbols( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI DbgUnLoadImageSymbols( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI RtlImageDirectoryEntryToData( /* unknown */ );

DECLSPEC_IMPORT
PVOID 
NTAPI
RtlImageNtHeader(
    PVOID module
    );

DECLSPEC_IMPORT VOID NTAPI ExDebugMonitorService( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI MmDbgReadCheck( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI MmDbgReleaseAddress( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI MmDbgWriteCheck( /* unknown */ );

EXTERN_C DECLSPEC_IMPORT struct _NXEDK_OPAQUE_EXPORT ExLoadedCommandLine;

EXTERN_C DECLSPEC_IMPORT struct _NXEDK_OPAQUE_EXPORT ExLoadedImageName;

DECLSPEC_IMPORT BOOL NTAPI VdBlockUntilGUIIdle(void);

DECLSPEC_IMPORT ULONG NTAPI VdCallGraphicsNotificationRoutines(void);

DECLSPEC_IMPORT
VOID
NTAPI
VdDisplayFatalError(
    ULONG code
    );

DECLSPEC_IMPORT ULONG NTAPI VdEnableClosedCaption(void);

DECLSPEC_IMPORT
ULONG
NTAPI
VdEnableDisableClockGating(
    ULONG enabled
    );

DECLSPEC_IMPORT
VOID
NTAPI
VdEnableDisablePowerSavingMode(
    BOOL power_saving_mode
    );

DECLSPEC_IMPORT
VOID
NTAPI
VdEnableRingBufferRPtrWriteBack(
    PVOID ptr,
    LONG block_size_log2
    );

DECLSPEC_IMPORT ULONG NTAPI VdGenerateGPUCSCCoefficients(void);

DECLSPEC_IMPORT ULONG NTAPI VdGetClosedCaptionReadyStatus(void);

DECLSPEC_IMPORT
VOID
NTAPI
VdGetCurrentDisplayGamma(
    ULONG *type_ptr,
    FLOAT *power_ptr
    );

DECLSPEC_IMPORT
VOID
NTAPI
VdGetCurrentDisplayInformation(
    X_DISPLAY_INFO *display_info
    );

DECLSPEC_IMPORT ULONG NTAPI VdGetDisplayModeOverride(void);

DECLSPEC_IMPORT ULONG NTAPI VdGetGraphicsAsicID(void);

DECLSPEC_IMPORT
VOID
NTAPI
VdGetSystemCommandBuffer(
    PVOID a1,
    PVOID a2
    );

EXTERN_C DECLSPEC_IMPORT ULONG VdGlobalDevice;

EXTERN_C DECLSPEC_IMPORT ULONG VdGlobalXamDevice;

EXTERN_C DECLSPEC_IMPORT ULONG VdGpuClockInMHz;

EXTERN_C DECLSPEC_IMPORT UCHAR VdHSIOCalibrationLock;

DECLSPEC_IMPORT ULONG NTAPI VdInitializeEngines(void);

DECLSPEC_IMPORT
VOID
NTAPI
VdInitializeRingBuffer(
    PVOID ptr,
    LONG size_log2
    );

DECLSPEC_IMPORT ULONG NTAPI VdInitializeScaler(void);

DECLSPEC_IMPORT
ULONG
NTAPI
VdInitializeScalerCommandBuffer(
    ULONG scaler_source_xy,
    ULONG scaler_source_wh,
    ULONG scaled_output_xy,
    ULONG scaled_output_wh,
    ULONG front_buffer_wh,
    ULONG vertical_filter_type,
    X_D3DFILTER_PARAMETERS *vertical_filter_params,
    ULONG horizontal_filter_type,
    X_D3DFILTER_PARAMETERS *horizontal_filter_params,
    PVOID unk9,
    PVOID dest_ptr,
    ULONG dest_count
    );

DECLSPEC_IMPORT ULONG NTAPI VdIsHSIOTrainingSucceeded(void);

DECLSPEC_IMPORT ULONG NTAPI VdPersistDisplay(void);

DECLSPEC_IMPORT ULONG NTAPI VdQuerySystemCommandBuffer(void);

DECLSPEC_IMPORT ULONG NTAPI VdQueryVideoFlags(void);

DECLSPEC_IMPORT
VOID
NTAPI
VdQueryVideoMode(
    X_VIDEO_MODE *video_mode
    );

DECLSPEC_IMPORT ULONG NTAPI VdReadDVERegisterUlong(void);

DECLSPEC_IMPORT ULONG NTAPI VdReadWriteHSIOCalibrationFlag(void);

DECLSPEC_IMPORT ULONG NTAPI VdRegisterGraphicsNotification(void);

DECLSPEC_IMPORT ULONG NTAPI VdRegisterXamGraphicsNotification(void);

DECLSPEC_IMPORT ULONG NTAPI VdSendClosedCaptionData(void);

DECLSPEC_IMPORT ULONG NTAPI VdSetCGMSOption(void);

DECLSPEC_IMPORT ULONG NTAPI VdSetColorProfileAdjustment(void);

DECLSPEC_IMPORT ULONG NTAPI VdSetCscMatricesOverride(void);

DECLSPEC_IMPORT
ULONG
NTAPI
VdSetDisplayMode(
    DWORD Flags
    );

DECLSPEC_IMPORT ULONG NTAPI VdSetDisplayModeOverride(void);

DECLSPEC_IMPORT ULONG NTAPI VdSetGraphicsInterruptCallback(void);

DECLSPEC_IMPORT VOID NTAPI VdSetHDCPOption( /* unknown */ );

DECLSPEC_IMPORT ULONG NTAPI VdSetMacrovisionOption(void);

DECLSPEC_IMPORT ULONG NTAPI VdSetSystemCommandBuffer(void);

DECLSPEC_IMPORT ULONG NTAPI VdSetSystemCommandBufferGpuIdentifierAddress(void);

DECLSPEC_IMPORT ULONG NTAPI VdSetWSSData(void);

DECLSPEC_IMPORT ULONG NTAPI VdSetWSSOption(void);

DECLSPEC_IMPORT VOID NTAPI VdShutdownEngines(void);

DECLSPEC_IMPORT ULONG NTAPI VdTurnDisplayOff(void);

DECLSPEC_IMPORT ULONG NTAPI VdTurnDisplayOn(void);

DECLSPEC_IMPORT
ULONG
NTAPI
KiApcNormalRoutineNop(
    ULONG unk0,
    ULONG unk1
    );

DECLSPEC_IMPORT
ULONG
NTAPI
VdVerifyMEInitCommand(
    ULONG unk0,
    ULONG unk1
    );

DECLSPEC_IMPORT ULONG NTAPI VdWriteDVERegisterUlong(void);

DECLSPEC_IMPORT VOID NTAPI XVoicedHeadsetPresent( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XVoicedSubmitPacket( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XVoicedClose( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XVoicedActivate( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XInputdGetCapabilities( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XInputdReadState( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XInputdWriteState( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XInputdNotify( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XInputdRawState( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI HidGetCapabilities( /* unknown */ );

DECLSPEC_IMPORT
NTSTATUS
NTAPI
HidReadKeys(
    ULONG unk1,
    ULONG unk2,
    ULONG unk3
    );

DECLSPEC_IMPORT VOID NTAPI XInputdGetDeviceStats( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XInputdResetDevice( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XInputdSetRingOfLight( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XInputdSetRFPowerMode( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XInputdSetRadioFrequency( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI HidGetLastInputTime( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XAudioRenderDriverInitialize( /* unknown */ );

DECLSPEC_IMPORT
ULONG
NTAPI
XAudioRegisterRenderDriverClient(
    ULONG *callback_ptr,
    ULONG *driver_ptr
    );

DECLSPEC_IMPORT VOID NTAPI XAudioUnregisterRenderDriverClient( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XAudioSubmitRenderDriverFrame( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XAudioRenderDriverLock( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XAudioGetVoiceCategoryVolumeChangeMask( /* unknown */ );

DECLSPEC_IMPORT
ULONG
NTAPI
XAudioGetVoiceCategoryVolume(
    ULONG unk,
    FLOAT *out_ptr
    );

DECLSPEC_IMPORT VOID NTAPI XAudioSetVoiceCategoryVolume( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XAudioBeginDigitalBypassMode( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XAudioEndDigitalBypassMode( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XAudioSubmitDigitalPacket( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XAudioQueryDriverPerformance( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XAudioGetRenderDriverThread( /* unknown */ );

DECLSPEC_IMPORT
ULONG
NTAPI
XAudioGetSpeakerConfig(
    ULONG *config_ptr
    );

DECLSPEC_IMPORT VOID NTAPI XAudioSetSpeakerConfig( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI NicSetUnicastAddress( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI NicAttach( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI NicDetach( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI NicXmit( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI NicUpdateMcastMembership( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI NicFlushXmitQueue( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI NicShutdown( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI NicGetLinkState( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI NicGetStats( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI NicGetOpt( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI NicSetOpt( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI DrvSetSysReqCallback( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI DrvSetUserBindingCallback( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI DrvSetContentStorageCallback( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI DrvSetAutobind( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI DrvGetContentStorageNotification( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI MtpdBeginTransaction( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI MtpdCancelTransaction( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI MtpdEndTransaction( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI MtpdGetCurrentDevices( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI MtpdReadData( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI MtpdReadEvent( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI MtpdResetDevice( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI MtpdSendData( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI MtpdVerifyProximity( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XUsbcamSetCaptureMode( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XUsbcamGetConfig( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XUsbcamSetConfig( /* unknown */ );

DECLSPEC_IMPORT ULONG NTAPI XUsbcamGetState(void);

DECLSPEC_IMPORT VOID NTAPI XUsbcamReadFrame( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XUsbcamSnapshot( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XUsbcamSetView( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XUsbcamGetView( /* unknown */ );

DECLSPEC_IMPORT
ULONG
NTAPI
XUsbcamCreate(
    ULONG buffer,
    ULONG buffer_size,
    ULONG *handle_out
    );

DECLSPEC_IMPORT VOID NTAPI XUsbcamDestroy( /* unknown */ );

DECLSPEC_IMPORT
ULONG
NTAPI
XMACreateContext(
    ULONG *context_out_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XMAInitializeContext(
    PVOID context_ptr,
    XMA_CONTEXT_INIT *context_init
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XMAReleaseContext(
    PVOID context_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XMAEnableContext(
    PVOID context_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XMADisableContext(
    PVOID context_ptr,
    ULONG wait
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XMAGetOutputBufferWriteOffset(
    PVOID context_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XMASetOutputBufferReadOffset(
    PVOID context_ptr,
    ULONG value
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XMAGetOutputBufferReadOffset(
    PVOID context_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XMASetOutputBufferValid(
    PVOID context_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XMAIsOutputBufferValid(
    PVOID context_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XMASetInputBuffer0Valid(
    PVOID context_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XMAIsInputBuffer0Valid(
    PVOID context_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XMASetInputBuffer1Valid(
    PVOID context_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XMAIsInputBuffer1Valid(
    PVOID context_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XMASetInputBuffer0(
    PVOID context_ptr,
    PVOID buffer,
    ULONG packet_count
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XMASetInputBuffer1(
    PVOID context_ptr,
    PVOID buffer,
    ULONG packet_count
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XMAGetPacketMetadata(
    PVOID context_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XMABlockWhileInUse(
    PVOID context_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XMASetLoopData(
    PVOID context_ptr,
    XMA_LOOP_DATA *loop_data
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XMASetInputBufferReadOffset(
    PVOID context_ptr,
    ULONG value
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XMAGetInputBufferReadOffset(
    PVOID context_ptr
    );

DECLSPEC_IMPORT VOID NTAPI ExIsBetaFeatureEnabled( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XeKeysGetFactoryChallenge( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XeKeysSetFactoryResponse( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XeKeysInitializeFuses( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XeKeysSaveBootLoader( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XeKeysSaveKeyVault( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XeKeysGetStatus( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XeKeysGeneratePrivateKey( /* unknown */ );

DECLSPEC_IMPORT
ULONG
NTAPI
XeKeysGetKeyProperties(
    ULONG key
    );

DECLSPEC_IMPORT VOID NTAPI XeKeysSetKey( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XeKeysGenerateRandomKey( /* unknown */ );

DECLSPEC_IMPORT
ULONG
NTAPI
XeKeysGetKey(
    USHORT key,
    PVOID key_buffer,
    ULONG *key_length
    );

DECLSPEC_IMPORT VOID NTAPI XeKeysGetDigest( /* unknown */ );

DECLSPEC_IMPORT
ULONG
NTAPI
XeKeysGetConsoleID(
    XE_CONSOLE_ID *raw_bytes,
    CONST CHAR *hex_string
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XeKeysGetConsoleType(
    ULONG *type_out
    );

DECLSPEC_IMPORT VOID NTAPI XeKeysQwNeRsaPrvCrypt( /* unknown */ );

DECLSPEC_IMPORT
ULONG
NTAPI
XeKeysHmacSha(
    ULONG key_num,
    PVOID inp_1,
    ULONG inp_1_size,
    PVOID inp_2,
    ULONG inp_2_size,
    PVOID inp_3,
    ULONG inp_3_size,
    PVOID out,
    ULONG out_size
    );

DECLSPEC_IMPORT VOID NTAPI XInputdPassThroughRFCommand( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XeKeysAesCbc( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XeKeysDes2Cbc( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XeKeysDesCbc( /* unknown */ );

DECLSPEC_IMPORT
ULONG
NTAPI
XeKeysObscureKey(
    PVOID input,
    PVOID output
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XeKeysHmacShaUsingKey(
    PVOID obscured_key,
    PVOID inp_1,
    ULONG inp_1_size,
    PVOID inp_2,
    ULONG inp_2_size,
    PVOID inp_3,
    ULONG inp_3_size,
    PVOID out,
    ULONG out_size
    );

DECLSPEC_IMPORT VOID NTAPI XeKeysSaveBootLoaderEx( /* unknown */ );

DECLSPEC_IMPORT
ULONG
NTAPI
XeKeysAesCbcUsingKey(
    PVOID obscured_key,
    PVOID inp_ptr,
    ULONG inp_size,
    PVOID out_ptr,
    PVOID feed_ptr,
    ULONG encrypt
    );

DECLSPEC_IMPORT VOID NTAPI XeKeysDes2CbcUsingKey( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XeKeysDesCbcUsingKey( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XeKeysObfuscate( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XeKeysUnObfuscate( /* unknown */ );

DECLSPEC_IMPORT
ULONG
NTAPI
XeKeysConsolePrivateKeySign(
    PVOID hash,
    XE_CONSOLE_CERTIFICATE *output
    );

DECLSPEC_IMPORT VOID NTAPI XeKeysConsoleSignatureVerification( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XeKeysVerifyRSASignature( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI StfsCreateDevice( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI StfsControlDevice( /* unknown */ );

DECLSPEC_IMPORT ULONG NTAPI VdSwap(void);

EXTERN_C DECLSPEC_IMPORT ULONG HalFsbInterruptCount;

DECLSPEC_IMPORT VOID NTAPI XeKeysSaveSystemUpdate( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XeKeysLockSystemUpdate( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XeKeysExecute( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XeKeysGetVersions( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XInputdPowerDownDevice( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI AniBlockOnAnimation( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI AniTerminateAnimation( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XUsbcamReset( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI AniSetLogo( /* unknown */ );

EXTERN_C DECLSPEC_IMPORT struct _NXEDK_OPAQUE_EXPORT KeCertMonitorData;

DECLSPEC_IMPORT BOOL NTAPI HalIsExecutingPowerDownDpc(void);

DECLSPEC_IMPORT VOID NTAPI VdInitializeEDRAM(void);

DECLSPEC_IMPORT ULONG NTAPI VdRetrainEDRAM(void);

DECLSPEC_IMPORT ULONG NTAPI VdRetrainEDRAMWorker(void);

EXTERN_C DECLSPEC_IMPORT struct _NXEDK_OPAQUE_EXPORT VdHSIOTrainCount;

DECLSPEC_IMPORT
VOID
NTAPI
HalGetPowerUpCause(
    UCHAR *response
    );

EXTERN_C DECLSPEC_IMPORT struct _NXEDK_OPAQUE_EXPORT VdHSIOTrainingStatus;

EXTERN_C DECLSPEC_IMPORT struct _NXEDK_OPAQUE_EXPORT RgcBindInfo;

DECLSPEC_IMPORT ULONG NTAPI VdReadEEDIDBlock(void);

DECLSPEC_IMPORT ULONG NTAPI VdEnumerateVideoModes(void);

DECLSPEC_IMPORT
ULONG
NTAPI
VdEnableHDCP(
    ULONG a1
    );

DECLSPEC_IMPORT ULONG NTAPI VdRegisterHDCPNotification(void);

DECLSPEC_IMPORT VOID NTAPI HidReadMouseChanges( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI DumpSetCollectionFacility( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XexTransformImageKey( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XAudioOverrideSpeakerConfig( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XInputdReadTextKeystroke( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI DrvXenonButtonPressed( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI DrvBindToUser( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XexGetModuleImportVersions( /* unknown */ );

DECLSPEC_IMPORT
ULONG
NTAPI
RtlComputeCrc32(
    ULONG seed,
    PVOID buffer,
    ULONG length
    );

DECLSPEC_IMPORT VOID NTAPI XeKeysSetRevocationList( /* unknown */ );

DECLSPEC_IMPORT
VOID
NTAPI
HalRegisterPowerDownCallback(
    PVOID callback
    );

DECLSPEC_IMPORT ULONG NTAPI VdGetDisplayDiscoveryData(void);

DECLSPEC_IMPORT VOID NTAPI XInputdSendStayAliveRequest( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XVoicedSendVPort( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XVoicedGetBatteryStatus( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XInputdFFGetDeviceInfo( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XInputdFFSetEffect( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XInputdFFUpdateEffect( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XInputdFFEffectOperation( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XInputdFFDeviceControl( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XInputdFFSetDeviceGain( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XInputdFFCancelIo( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XInputdFFSetRumble( /* unknown */ );

DECLSPEC_IMPORT
ULONG
NTAPI
NtAllocateEncryptedMemory(
    ULONG unk,
    SIZE_T RegionSize,
    PVOID BaseAddress
    );

DECLSPEC_IMPORT
ULONG
NTAPI
NtFreeEncryptedMemory(
    ULONG region_type,
    ULONG *base_address_ptr
    );

DECLSPEC_IMPORT VOID NTAPI XeKeysExSaveKeyVault( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XeKeysExSetKey( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XeKeysExGetKey( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI DrvSetDeviceConfigChangeCallback( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI DrvDeviceConfigChange( /* unknown */ );

DECLSPEC_IMPORT
VOID
NTAPI
HalRegisterHdDvdRomNotification(
    ULONG *a1,
    BOOL a2
    );

DECLSPEC_IMPORT VOID NTAPI XeKeysSecurityInitialize( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XeKeysSecurityLoadSettings( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XeKeysSecuritySaveSettings( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XeKeysSecuritySetDetected( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XeKeysSecurityGetDetected( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XeKeysSecuritySetActivated( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XeKeysSecurityGetActivated( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XeKeysDvdAuthAP25InstallTable( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XeKeysReserved665( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XeKeysDvdAuthAP25GetTableVersion( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XeKeysReserved666( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XeKeysGetProtectedFlag( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XeKeysSetProtectedFlag( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeEnablePFMInterrupt( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeDisablePFMInterrupt( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeSetProfilerISR( /* unknown */ );

DECLSPEC_IMPORT ULONG NTAPI VdStartDisplayDiscovery(void);

DECLSPEC_IMPORT ULONG NTAPI VdSetHDCPRevocationList(void);

DECLSPEC_IMPORT VOID NTAPI XeKeysGetUpdateSequence( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XeKeysDvdAuthExActivate( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeGetImagePageTableEntry( /* unknown */ );

DECLSPEC_IMPORT
VOID
NTAPI
HalRegisterBackgroundModeTransitionCallback(
    PVOID callback
    );

DECLSPEC_IMPORT VOID NTAPI AniStartBootAnimation( /* unknown */ );

DECLSPEC_IMPORT
BOOL
NTAPI
HalClampUnclampOutputDACs(
    BOOL state
    );

DECLSPEC_IMPORT VOID NTAPI HalPowerDownToBackgroundMode(void);

DECLSPEC_IMPORT
VOID
NTAPI
HalNotifyAddRemoveBackgroundTask(
    BOOL add_remove
    );

DECLSPEC_IMPORT VOID NTAPI HalCallBackgroundModeNotificationRoutines(void);

EXTERN_C DECLSPEC_IMPORT ULONG HalFsbResetCount;

DECLSPEC_IMPORT
VOID
NTAPI
HalGetMemoryInformation(
    ULONG *out1,
    ULONG *out2
    );

DECLSPEC_IMPORT VOID NTAPI XInputdGetLastTextInputTime( /* unknown */ );

DECLSPEC_IMPORT ULONG NTAPI VdEnableWMAProOverHDMI(void);

DECLSPEC_IMPORT VOID NTAPI XeKeysRevokeSaveSettings( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XInputdSetTextMessengerIndicator( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI MicDeviceRequest( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XeKeysGetMediaID( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XeKeysLoadKeyVault( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XeKeysReserved691( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeGetVidInfo( /* unknown */ );

DECLSPEC_IMPORT
BOOL
NTAPI
HalNotifyBackgroundModeTransitionComplete(
    ULONG a1,
    ULONG a2
    );

DECLSPEC_IMPORT VOID NTAPI IoAcquireCancelSpinLock( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI IoReleaseCancelSpinLock( /* unknown */ );

DECLSPEC_IMPORT
ULONG
NTAPI
NtCancelIoFile(
    HANDLE Handle
    );

DECLSPEC_IMPORT VOID NTAPI NtCancelIoFileEx( /* unknown */ );

DECLSPEC_IMPORT BOOL NTAPI HalFinalizePowerLossRecovery(void);

DECLSPEC_IMPORT
VOID
NTAPI
HalSetPowerLossRecovery(
    BOOL state
    );

DECLSPEC_IMPORT
ULONG
NTAPI
ExReadModifyWriteXConfigSettingUlong(
    USHORT category,
    USHORT setting,
    ULONG bit_affected,
    ULONG flag
    );

DECLSPEC_IMPORT
VOID
NTAPI
HalRegisterXamPowerDownCallback(
    PVOID callback
    );

DECLSPEC_IMPORT VOID NTAPI ExCancelAlarm( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI ExInitializeAlarm( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI ExSetAlarm( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XexActivationGetNonce( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XexActivationSetLicense( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI IptvSetBoundaryKey( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI IptvSetSessionKey( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI IptvVerifyOmac1Signature( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI IptvGetAesCtrTransform( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI SataCdRomRecordReset( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XInputdSetTextDeviceKeyLocks( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XInputdGetTextDeviceKeyLocks( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XexActivationVerifyOwnership( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XexDisableVerboseDbgPrint( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI SvodCreateDevice( /* unknown */ );

DECLSPEC_IMPORT
USHORT
NTAPI
RtlCaptureStackBackTrace(
    ULONG frames_to_skip,
    ULONG frames_to_capture,
    PVOID back_trace,
    ULONG *back_trace_hash
    );

DECLSPEC_IMPORT VOID NTAPI XeKeysRevokeUpdateDynamic( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XexImportTraceEnable( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI ExRegisterXConfigNotification( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XeKeysSecuritySetStat( /* unknown */ );

DECLSPEC_IMPORT
VOID
NTAPI
VdQueryRealVideoMode(
    X_VIDEO_MODE *video_mode
    );

DECLSPEC_IMPORT VOID NTAPI XexSetExecutablePrivilege( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XAudioSuspendRenderDriverClients( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI IptvGetSessionKeyHash( /* unknown */ );

DECLSPEC_IMPORT ULONG NTAPI VdSetCGMSState(void);

DECLSPEC_IMPORT ULONG NTAPI VdSetSCMSState(void);

DECLSPEC_IMPORT VOID NTAPI KeFlushMultipleTb( /* unknown */ );

DECLSPEC_IMPORT ULONG NTAPI VdGetOption(void);

DECLSPEC_IMPORT ULONG NTAPI VdSetOption(void);

EXTERN_C DECLSPEC_IMPORT struct _NXEDK_OPAQUE_EXPORT UsbdBootEnumerationDoneEvent;

EXTERN_C DECLSPEC_IMPORT struct _NXEDK_OPAQUE_EXPORT StfsDeviceErrorEvent;

DECLSPEC_IMPORT VOID NTAPI ExTryToAcquireReadWriteLockExclusive( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI ExTryToAcquireReadWriteLockShared( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XexSetLastKdcTime( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XInputdControl( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI RmcDeviceRequest( /* unknown */ );

DECLSPEC_IMPORT
LDI_STATUS
NTAPI
LDIResetDecompression(
    LDI_CONTEXT *context
    );

DECLSPEC_IMPORT VOID NTAPI NicRegisterDevice( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI UsbdAddDeviceComplete( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI UsbdCancelAsyncTransfer( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI UsbdGetDeviceSpeed( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI UsbdGetDeviceTopology( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI UsbdGetEndpointDescriptor( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI UsbdIsDeviceAuthenticated( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI UsbdOpenDefaultEndpoint( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI UsbdOpenEndpoint( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI UsbdQueueAsyncTransfer( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI UsbdQueueCloseDefaultEndpoint( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI UsbdQueueCloseEndpoint( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI UsbdRemoveDeviceComplete( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeRemoveQueueApc( /* unknown */ );

EXTERN_C DECLSPEC_IMPORT struct _NXEDK_OPAQUE_EXPORT UsbdDriverLoadRequiredEvent;

DECLSPEC_IMPORT VOID NTAPI UsbdGetRequiredDrivers( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI UsbdRegisterDriverObject( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI UsbdUnregisterDriverObject( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI UsbdCallAndBlockOnDpcRoutine( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI UsbdResetDevice( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI UsbdGetDeviceDescriptor( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI NomnilGetExtension( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI NomnilStartCloseDevice( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI WifiBeginAuthentication( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI WifiCheckCounterMeasures( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI WifiChooseAuthenCipherSetFromBSSID( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI WifiCompleteAuthentication( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI WifiGetAssociationIE( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI WifiOnMICError( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI WifiPrepareAuthenticationContext( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI WifiRecvEAPOLPacket( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI WifiDeduceNetworkType( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI NicUnregisterDevice( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI DumpXitThread( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XInputdSetWifiChannel( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI NomnilSetLed( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI WifiCalculateRegulatoryDomain( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI WifiSelectAdHocChannel( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI WifiChannelToFrequency( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI MmGetPoolPagesType( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI ExExpansionInstall( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI ExExpansionCall( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI PsCamDeviceRequest( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI McaDeviceRequest( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI DetroitDeviceRequest( /* unknown */ );

DECLSPEC_IMPORT
VOID
NTAPI
XeCryptSha256Init(
    XECRYPT_SHA256_STATE *sha_state
    );

DECLSPEC_IMPORT
VOID
NTAPI
XeCryptSha256Update(
    XECRYPT_SHA256_STATE *sha_state,
    PVOID input,
    ULONG input_size
    );

DECLSPEC_IMPORT
VOID
NTAPI
XeCryptSha256Final(
    XECRYPT_SHA256_STATE *sha_state,
    UCHAR *out,
    ULONG out_size
    );

DECLSPEC_IMPORT
VOID
NTAPI
XeCryptSha256(
    CONST UCHAR *input1,
    ULONG input1_size,
    CONST UCHAR *input2,
    ULONG input2_size,
    CONST UCHAR *input3,
    ULONG input3_size,
    UCHAR *digest,
    ULONG digest_size
    );

DECLSPEC_IMPORT
VOID
NTAPI
XeCryptSha384Init(
    CRYPT_SHA512_STATE *state
    );

DECLSPEC_IMPORT
VOID
NTAPI
XeCryptSha384Update(
    CRYPT_SHA512_STATE *state,
    CONST UCHAR *input,
    ULONG input_size
    );

DECLSPEC_IMPORT VOID NTAPI XInputdGetDevicePid( /* unknown */ );

DECLSPEC_IMPORT UCHAR NTAPI HalGetNotedArgonErrors(void);

DECLSPEC_IMPORT
VOID
NTAPI
XeCryptSha384Final(
    CRYPT_SHA512_STATE *state,
    UCHAR *digest,
    ULONG digest_size
    );

DECLSPEC_IMPORT
NTSTATUS
NTAPI
HalReadArgonEeprom(
    ULONG a1,
    UCHAR *buf,
    USHORT size,
    USHORT *a4
    );

DECLSPEC_IMPORT
NTSTATUS
NTAPI
HalWriteArgonEeprom(
    ULONG a1,
    UCHAR *buf,
    USHORT size,
    USHORT *a4
    );

DECLSPEC_IMPORT VOID NTAPI XeKeysFcrtLoad( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XeKeysFcrtSave( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XeKeysFcrtSet( /* unknown */ );

DECLSPEC_IMPORT
VOID
NTAPI
XeCryptSha384(
    CONST UCHAR *input1,
    ULONG input1_size,
    CONST UCHAR *input2,
    ULONG input2_size,
    CONST UCHAR *input3,
    ULONG input3_size,
    UCHAR *digest,
    ULONG digest_size
    );

DECLSPEC_IMPORT
VOID
NTAPI
XeCryptSha512Init(
    XECRYPT_SHA512_STATE *sha_state
    );

DECLSPEC_IMPORT VOID NTAPI XAudioRegisterRenderDriverMECClient( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XAudioUnregisterRenderDriverMECClient( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XAudioCaptureRenderDriverFrame( /* unknown */ );

DECLSPEC_IMPORT
VOID
NTAPI
XeCryptSha512Update(
    XECRYPT_SHA512_STATE *sha_state,
    PVOID input,
    ULONG input_size
    );

DECLSPEC_IMPORT
VOID
NTAPI
XeCryptSha512Final(
    XECRYPT_SHA256_STATE *sha_state,
    UCHAR *out,
    ULONG out_size
    );

DECLSPEC_IMPORT
VOID
NTAPI
XeCryptSha512(
    CONST UCHAR *input1,
    ULONG input1_size,
    CONST UCHAR *input2,
    ULONG input2_size,
    CONST UCHAR *input3,
    ULONG input3_size,
    UCHAR *digest,
    ULONG digest_size
    );

DECLSPEC_IMPORT
LONG
NTAPI
XeCryptBnQwNeCompare(
    CONST ULONGLONG *input1,
    CONST ULONGLONG *input2,
    ULONG qword_count
    );

DECLSPEC_IMPORT VOID NTAPI XVoicedGetDirectionalData( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI DrvSetMicArrayStartCallback( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI DevAuthGetStatistics( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI NullCableRequest( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XeKeysRevokeIsDeviceRevoked( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI DumpUpdateDumpSettings( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI EtxConsumerDisableEventType( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI EtxConsumerEnableEventType( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI EtxConsumerProcessLogs( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI EtxConsumerRegister( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI EtxConsumerUnregister( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI EtxProducerLog( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI EtxProducerLogV( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI EtxProducerRegister( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI EtxProducerUnregister( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI EtxConsumerFlushBuffers( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI EtxProducerLogXwpp( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI EtxProducerLogXwppV( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI UsbdEnableDisableRootHubPort( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI EtxBufferRegister( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI EtxBufferUnregister( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI DumpRegisterDedicatedDataBlock( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XeKeysDvdAuthExSave( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XeKeysDvdAuthExInstall( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XexShimDisable( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XexShimEnable( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XexShimEntryDisable( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XexShimEntryEnable( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XexShimEntryRegister( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XexShimLock( /* unknown */ );

EXTERN_C DECLSPEC_IMPORT struct _NXEDK_OPAQUE_EXPORT XboxKrnlVersion4Digit;

DECLSPEC_IMPORT VOID NTAPI XeKeysObfuscateEx( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XeKeysUnObfuscateEx( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XexTitleHash( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XexTitleHashClose( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XexTitleHashContinue( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XexTitleHashOpen( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XAudioGetRenderDriverTic( /* unknown */ );

DECLSPEC_IMPORT
ULONG
NTAPI
XAudioEnableDucker(
    ULONG unk
    );

DECLSPEC_IMPORT VOID NTAPI XAudioSetDuckerLevel( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XAudioIsDuckerEnabled( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XAudioGetDuckerLevel( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XAudioGetDuckerThreshold( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XAudioSetDuckerThreshold( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XAudioGetDuckerAttackTime( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XAudioSetDuckerAttackTime( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XAudioGetDuckerReleaseTime( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XAudioSetDuckerReleaseTime( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XAudioGetDuckerHoldTime( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XAudioSetDuckerHoldTime( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI DevAuthShouldAlwaysEnforce( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XAudioGetUnderrunCount( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI DrvSetAudioLatencyCallback( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XVoicedIsActiveProcess( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeExecuteOnProtectedStack( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XeKeysVerifyPIRSSignature( /* unknown */ );

DECLSPEC_IMPORT
VOID
NTAPI
XeCryptAesCtr(
    CONST CRYPT_AES_STATE *state,
    CONST UCHAR *input,
    ULONG size,
    UCHAR *output,
    UCHAR *counter
    );

DECLSPEC_IMPORT
VOID
NTAPI
XeCryptAesCbcMac(
    CONST UCHAR *key,
    CONST UCHAR *input,
    ULONG size,
    UCHAR *output
    );

DECLSPEC_IMPORT
VOID
NTAPI
XeCryptAesDmMac(
    CONST UCHAR *key,
    CONST UCHAR *input,
    ULONG size,
    UCHAR *output
    );

DECLSPEC_IMPORT VOID NTAPI EmaExecute( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XeKeysGetTruncatedSecondaryConsoleId( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI ExFreeDebugPool( /* unknown */ );

DECLSPEC_IMPORT ULONG NTAPI VdQueryVideoCapabilities(void);

DECLSPEC_IMPORT VOID NTAPI UsbdGetDeviceRootPortType( /* unknown */ );

DECLSPEC_IMPORT ULONG NTAPI VdGet3dVideoFormat(void);

DECLSPEC_IMPORT ULONG NTAPI VdGetWSS2Data(void);

DECLSPEC_IMPORT ULONG NTAPI VdSet3dVideoFormat(void);

DECLSPEC_IMPORT ULONG NTAPI VdSetWSS2Data(void);

DECLSPEC_IMPORT VOID NTAPI XexReserveCodeBuffer( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XexCommitCodeBuffer( /* unknown */ );

DECLSPEC_IMPORT
VOID
NTAPI
RtlSetVectoredExceptionHandler(
    PVOID handler
    );

DECLSPEC_IMPORT VOID NTAPI RtlClearVectoredExceptionHandler(void);

DECLSPEC_IMPORT VOID NTAPI XAudioSetProcessFrameCallback( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI UsbdGetRootHubDeviceNode( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI UsbdGetPortDeviceNode( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI UsbdGetNatalHub( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI UsbdGetNatalHardwareVersion( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI UsbdNatalHubRegisterNotificationCallback( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeCallAndBlockOnDpcRoutine( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeCallAndWaitForDpcRoutine( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI TidDeviceRequest( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI DmPrintData( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI VdSetStudioRGBMode( /* unknown */ );

/* Linker spelling at ordinal 889: ?VdSetStudioRGBMode@@YAXXZ; C spelling: VdSetStudioRGBMode. */

DECLSPEC_IMPORT VOID NTAPI UsbdTitleDriverResetAllUnrecognizedPorts( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI UsbdTitleDriverSetUnrecognizedPort( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI UsbdResetEndpoint( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI UsbdSetTimer( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI UsbdCancelTimer( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI UsbdQueueIsochTransfer( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeSetPageRelocationCallback( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XexRegisterUsermodeModule( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI SerenityDongleRequest( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI TitleDeviceAuthRequest( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI KeRegisterSwapNotification( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XInputdGetFailedConnectionOrBind( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XInputdSetFailedConnectionOrBindCallback( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XInputdSetMinMaxAuthDelay( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI VgcHandler_SetHandlers( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI VvcHandlerCancelTransfers( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI VvcHandlerRetrieveVoiceExtension( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI MmResetLowestAvailablePages( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI VeSetHandlers( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI HalConfigureVeDevice(void);

DECLSPEC_IMPORT VOID NTAPI XeCryptSha224Init( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XeCryptAesCreateKeySchedule( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XeCryptAesEncryptOne( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XeCryptAesDecryptOne( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XeCryptAesCbcEncrypt( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XeCryptAesCbcDecrypt( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XeCryptAesGcmInitialize( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XeCryptAesGcmUpdate( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XeCryptAesGcmFinalize( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XeCryptEccGetCurveParameters( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XeCryptEccEcdhGenerateKeypair( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XeCryptEccEcdhExponentiate( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XeCryptEccEcdsaGenerateSignature( /* unknown */ );

DECLSPEC_IMPORT VOID NTAPI XeCryptEccEcdsaVerifySignature( /* unknown */ );

#ifdef __cplusplus
}
#endif

#endif /* _NXEDK_XBOXKRNL_H_ */
