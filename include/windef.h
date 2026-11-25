#ifndef _NXEDK_WINDEF_H_
#define _NXEDK_WINDEF_H_

#include <stddef.h>
#include <stdint.h>

#ifndef NTAPI
#define NTAPI
#endif

#ifndef DECLSPEC_IMPORT
#if defined(_WIN32)
#define DECLSPEC_IMPORT __declspec(dllimport)
#else
#define DECLSPEC_IMPORT
#endif
#endif

#ifndef EXTERN_C
#ifdef __cplusplus
#define EXTERN_C extern "C"
#else
#define EXTERN_C extern
#endif
#endif

#ifndef CONST
#define CONST const
#endif

typedef void       VOID, *PVOID;
typedef char       CHAR;
typedef int8_t     SCHAR;
typedef uint8_t    UCHAR;
typedef int16_t    SHORT;
typedef uint16_t   USHORT, WCHAR;
typedef int32_t    LONG, *PLONG, NTSTATUS, BOOL, BOOLEAN, DWORD, *PDWORD, ACCESS_MASK;
typedef uint32_t   ULONG, *PULONG;
typedef int64_t    LONGLONG;
typedef uint64_t   ULONGLONG;
typedef float      FLOAT;
typedef double     DOUBLE;
typedef size_t     SIZE_T, *PSIZE_T;
typedef PVOID      HANDLE;
typedef HANDLE     HMODULE, *PHANDLE;

#ifndef CHAR_MAX
#define CHAR_MAX                            UINT8_MAX
#endif
#ifndef SCHAR_MAX
#define SCHAR_MAX                           INT8_MAX
#endif
#ifndef UCHAR_MAX
#define UCHAR_MAX                           UINT8_MAX
#endif
#define SHORT_MAX                           INT16_MAX
#define USHORT_MAX                          UINT16_MAX
#ifndef LONG_MAX
#define LONG_MAX                            INT32_MAX
#endif
#ifndef ULONG_MAX
#define ULONG_MAX                           UINT32_MAX
#endif
#define LONGLONG_MAX                        INT64_MAX
#define ULONGLONG_MAX                       UINT64_MAX

#define TRUE  1
#define FALSE 0

#define STATUS_SUCCESS                      0x00000000
#define STATUS_INVALID_HANDLE               0xC0000008
#define STATUS_INVALID_PARAMETER            0xC000000D
#define STATUS_NO_SUCH_FILE                 0xC000000F
#define STATUS_END_OF_FILE                  0xC0000011
#define STATUS_NO_MEMORY                    0xC0000017
#define STATUS_ACCESS_DENIED                0xC0000022
#define STATUS_OBJECT_NAME_INVALID          0xC0000033
#define STATUS_OBJECT_NAME_NOT_FOUND        0xC0000034
#define STATUS_OBJECT_NAME_COLLISION        0xC0000035
#define STATUS_OBJECT_PATH_NOT_FOUND        0xC000003A
#define STATUS_INVALID_PAGE_PROTECTION      0xC0000045
#define STATUS_DISK_FULL                    0xC000007F
#define STATUS_INSUFFICIENT_RESOURCES       0xC000009A
#define STATUS_FILE_IS_A_DIRECTORY          0xC00000BA
#define STATUS_NOT_A_DIRECTORY              0xC0000103

#define NT_SUCCESS(Status) (((NTSTATUS)(Status)) >= 0)

#define FILE_OPEN                           0x00000001
#define FILE_CREATE                         0x00000002
#define FILE_OPEN_IF                        0x00000003
#define FILE_OVERWRITE                      0x00000004
#define FILE_OVERWRITE_IF                   0x00000005

#define FILE_READ_DATA                      0x00000001
#define FILE_WRITE_DATA                     0x00000002
#define FILE_APPEND_DATA                    0x00000004

#define FILE_SHARE_READ                     0x00000001  
#define FILE_SHARE_WRITE                    0x00000002  
#define FILE_SHARE_DELETE                   0x00000004  

#define FILE_ATTRIBUTE_READONLY             0x00000001  
#define FILE_ATTRIBUTE_HIDDEN               0x00000002  
#define FILE_ATTRIBUTE_SYSTEM               0x00000004  
#define FILE_ATTRIBUTE_DIRECTORY            0x00000010  
#define FILE_ATTRIBUTE_ARCHIVE              0x00000020  
#define FILE_ATTRIBUTE_DEVICE               0x00000040  
#define FILE_ATTRIBUTE_NORMAL               0x00000080  
#define FILE_ATTRIBUTE_TEMPORARY            0x00000100 

#define FILE_DIRECTORY_FILE                 0x00000001
#define FILE_SYNCHRONOUS_IO_NONALERT        0x00000020
#define FILE_NON_DIRECTORY_FILE             0x00000040

#define SYNCHRONIZE                         0x00100000

#define PAGE_NOACCESS                       0x00000001     
#define PAGE_READONLY                       0x00000002     
#define PAGE_READWRITE                      0x00000004     
#define PAGE_WRITECOPY                      0x00000008     
#define PAGE_EXECUTE                        0x00000010     
#define PAGE_EXECUTE_READ                   0x00000020     
#define PAGE_EXECUTE_READWRITE              0x00000040     
#define PAGE_EXECUTE_WRITECOPY              0x00000080     
#define PAGE_GUARD                          0x00000100     
#define PAGE_NOCACHE                        0x00000200     
#define PAGE_WRITECOMBINE                   0x00000400

#define MEM_COMMIT                          0x00001000     
#define MEM_RESERVE                         0x00002000     
#define MEM_DECOMMIT                        0x00004000     
#define MEM_RELEASE                         0x00008000     
#define MEM_FREE                            0x00010000
#define MEM_LARGE_PAGES                     0x20000000

// ExCreateThread creation flags. Zero starts a normal title thread.
#define EX_CREATE_THREAD_SUSPENDED          0x00000001
#define EX_CREATE_THREAD_SYSTEM             0x00000002
#define EX_CREATE_THREAD_PRIORITY_CLASS_1   0x00000020
#define EX_CREATE_THREAD_PRIORITY_CLASS_2   0x00000040
// The first output is a KTHREAD pointer instead of a handle.
#define EX_CREATE_THREAD_RETURN_KTHREAD     0x00000080

// Reported flags whose behavior has not been verified on hardware.
#define EX_CREATE_THREAD_TLS_STATIC         0x00000008
#define EX_CREATE_THREAD_TITLE_EXECUTION    0x00000100
#define EX_CREATE_THREAD_HIDDEN             0x00000400

// Select at most one logical CPU.
#define EX_CREATE_THREAD_AFFINITY_CPU0      0x01000000
#define EX_CREATE_THREAD_AFFINITY_CPU1      0x02000000
#define EX_CREATE_THREAD_AFFINITY_CPU2      0x04000000
#define EX_CREATE_THREAD_AFFINITY_CPU3      0x08000000
#define EX_CREATE_THREAD_AFFINITY_CPU4      0x10000000
#define EX_CREATE_THREAD_AFFINITY_CPU5      0x20000000

typedef NTSTATUS (*THREAD_START_ROUTINE)(PVOID StartContext);

typedef enum _PROCESSOR_MODE {
    KernelMode,
    UserMode
} KPROCESSOR_MODE;

typedef enum _EVENT_TYPE {
    NotificationEvent,
    SynchronizationEvent
} EVENT_TYPE;

typedef struct _ANSI_STRING {
    USHORT Length;
    USHORT MaximumLength;
    CHAR *Buffer;
} ANSI_STRING, *PANSI_STRING;

typedef struct _UNICODE_STRING {
    USHORT Length;
    USHORT MaximumLength;
    WCHAR *Buffer;
} UNICODE_STRING, *PUNICODE_STRING;

typedef ANSI_STRING X_ANSI_STRING, *PX_ANSI_STRING;
typedef UNICODE_STRING X_UNICODE_STRING, *PX_UNICODE_STRING;

typedef struct _X_OBJECT_ATTRIBUTES {
    HANDLE RootDirectory;
    PANSI_STRING ObjectName;
    ULONG Attributes;
} X_OBJECT_ATTRIBUTES, *PX_OBJECT_ATTRIBUTES, *POBJECT_ATTRIBUTES;

typedef struct _IO_STATUS_BLOCK {
    union {
        NTSTATUS Status;
        PVOID Pointer;
    };
    ULONG Information;
} IO_STATUS_BLOCK, *PIO_STATUS_BLOCK;

typedef IO_STATUS_BLOCK X_IO_STATUS_BLOCK, *PX_IO_STATUS_BLOCK;

typedef struct _SECURITY_ATTRIBUTES {
    ULONG Length;
    PVOID SecurityDescriptor;
    LONG InheritHandle;
} SECURITY_ATTRIBUTES, *PSECURITY_ATTRIBUTES;

typedef struct _X_INPUT_GAMEPAD {
    USHORT Buttons;
    UCHAR LeftTrigger;
    UCHAR RightTrigger;
    SHORT ThumbLX;
    SHORT ThumbLY;
    SHORT ThumbRX;
    SHORT ThumbRY;
} X_INPUT_GAMEPAD, *PX_INPUT_GAMEPAD;

typedef struct _X_INPUT_STATE {
    ULONG PacketNumber;
    X_INPUT_GAMEPAD Gamepad;
} X_INPUT_STATE, *PX_INPUT_STATE;

typedef struct _X_INPUT_VIBRATION {
    USHORT LeftMotorSpeed;
    USHORT RightMotorSpeed;
} X_INPUT_VIBRATION, *PX_INPUT_VIBRATION;

typedef struct _X_INPUT_CAPABILITIES {
    UCHAR Type;
    UCHAR SubType;
    USHORT Flags;
    X_INPUT_GAMEPAD Gamepad;
    X_INPUT_VIBRATION Vibration;
} X_INPUT_CAPABILITIES, *PX_INPUT_CAPABILITIES;

typedef struct _X_INPUT_KEYSTROKE {
    USHORT VirtualKey;
    WCHAR Unicode;
    USHORT Flags;
    UCHAR UserIndex;
    UCHAR HidCode;
} X_INPUT_KEYSTROKE, *PX_INPUT_KEYSTROKE;

typedef VOID NTAPI IO_APC_ROUTINE(PVOID Context, PIO_STATUS_BLOCK IoStatus, ULONG Reserved);
typedef IO_APC_ROUTINE *PIO_APC_ROUTINE;

typedef enum _LDI_STATUS {
    LDI_SUCCESS,
    LDI_INIT_ERR,
    LDI_BAD_MAGIC,
    LDI_BUFFER_TOO_SMALL,
    LDI_DECOMPRESS_ERR
} LDI_STATUS;

typedef struct _LDI_CONFIG {
    ULONG WindowSize;
    ULONG CpuType;
} LDI_CONFIG, *PLDI_CONFIG;

typedef PVOID NTAPI LDI_ALLOCATE(ULONG Size);
typedef VOID NTAPI LDI_FREE(PVOID Address);

typedef enum _REGION {
    REGION_AUTO,
    REGION_TITLE,
    REGION_SYSTEM
} REGION;

typedef union _LARGE_INTEGER {
    struct {
        LONG HighPart;
        DWORD LowPart;
    };
    struct {
        LONG HighPart;
        DWORD LowPart;
    } u;
    LONGLONG QuadPart;
} LARGE_INTEGER, *PLARGE_INTEGER;

typedef enum _X_FILE_INFORMATION_CLASS
{
    FileDirectoryInformation = 1,
    FileFullDirectoryInformation,
    FileBothDirectoryInformation,
    FileBasicInformation,
    FileStandardInformation,
    FileInternalInformation,
    FileEaInformation,
    FileAccessInformation,
    FileNameInformation,
    FileRenameInformation,
    FileLinkInformation,
    FileNamesInformation,
    FileDispositionInformation,
    FilePositionInformation,
    FileFullEaInformation,
    FileModeInformation,
    FileAlignmentInformation,
    FileAllInformation,
    FileAllocationInformation,
    FileEndOfFileInformation,
    FileAlternateNameInformation,
    FileStreamInformation,
    FileMountPartitionInformation,
    FileMountPartitionsInformation,
    FilePipeRemoteInformation,
    FileSectorInformation,
    FileXctdCompressionInformation,
    FileCompressionInformation,
    FileObjectIdInformation,
    FileCompletionInformation,
    FileMoveClusterInformation,
    FileIoPriorityInformation,
    FileReparsePointInformation,
    FileNetworkOpenInformation,
    FileAttributeTagInformation,
    FileTrackingInformation,
    FileMaximumInformation
} X_FILE_INFORMATION_CLASS;

#pragma pack(push, 1)

typedef struct _X_FILE_BASIC_INFORMATION
{
    LARGE_INTEGER CreationTime;
    LARGE_INTEGER LastAccessTime;
    LARGE_INTEGER LastWriteTime;
    LARGE_INTEGER ChangeTime;
    ULONGLONG Attributes;
} X_FILE_BASIC_INFORMATION, *PX_FILE_BASIC_INFORMATION;

typedef struct _X_FILE_INTERNAL_INFORMATION
{
    ULONGLONG IndexNumber;
} X_FILE_INTERNAL_INFORMATION, *PX_FILE_INTERNAL_INFORMATION;

typedef struct _X_FILE_RENAME_INFORMATION
{
    ULONG ReplaceExisting;
    ULONG RootDirectory;
    X_ANSI_STRING FileName;
} X_FILE_RENAME_INFORMATION, *PX_FILE_RENAME_INFORMATION;

typedef struct _X_FILE_DISPOSITION_INFORMATION
{
    UCHAR DeleteFile;
} X_FILE_DISPOSITION_INFORMATION, *PX_FILE_DISPOSITION_INFORMATION;

typedef struct _X_FILE_POSITION_INFORMATION
{
    LARGE_INTEGER CurrentByteOffset;
} X_FILE_POSITION_INFORMATION, *PX_FILE_POSITION_INFORMATION;

typedef struct _X_FILE_END_OF_FILE_INFORMATION
{
    LARGE_INTEGER EndOfFile;
} X_FILE_END_OF_FILE_INFORMATION, *PX_FILE_END_OF_FILE_INFORMATION;

typedef struct _X_FILE_XCTD_COMPRESSION_INFORMATION
{
    ULONG Unknown;
} X_FILE_XCTD_COMPRESSION_INFORMATION, *PX_FILE_XCTD_COMPRESSION_INFORMATION;

typedef struct _X_FILE_COMPLETION_INFORMATION
{
    HANDLE Handle;
    ULONG Key;
} X_FILE_COMPLETION_INFORMATION, *PX_FILE_COMPLETION_INFORMATION;

typedef struct _X_FILE_NETWORK_OPEN_INFORMATION
{
    LARGE_INTEGER CreationTime;
    LARGE_INTEGER LastAccessTime;
    LARGE_INTEGER LastWriteTime;
    LARGE_INTEGER ChangeTime;
    LARGE_INTEGER AllocationSize;
    LARGE_INTEGER EndOfFile;
    ULONG Attributes;
    ULONG Pad;
} X_FILE_NETWORK_OPEN_INFORMATION, *PX_FILE_NETWORK_OPEN_INFORMATION;

#pragma pack(pop)

typedef struct _X_MEMORY_BASIC_INFORMATION {
    PVOID BaseAddress;
    PVOID AllocationBase;
    ULONG AllocationProtect;
    SIZE_T RegionSize;
    ULONG State;
    ULONG Protect;
    ULONG Type;
} X_MEMORY_BASIC_INFORMATION;

typedef struct _X_RTL_CRITICAL_SECTION {
    struct {
        UCHAR Type;
        UCHAR Absolute;
        UCHAR Size;
        UCHAR Inserted;
        LONG SignalState;
        struct
        {
            ULONG Flink;
            ULONG Blink;
        } WaitListHead;
    } Header;
    LONG LockCount;
    LONG RecursionCount;
    ULONG OwningThread;
} X_RTL_CRITICAL_SECTION, RTL_CRITICAL_SECTION, CRITICAL_SECTION;

/* Layouts not established by the catalog are intentionally opaque. */
struct _NXEDK_OPAQUE_EXPORT;
typedef struct _CRYPT_AES_STATE CRYPT_AES_STATE;
typedef struct _CRYPT_DES_STATE CRYPT_DES_STATE;
typedef struct _CRYPT_HMAC_MD5_STATE CRYPT_HMAC_MD5_STATE;
typedef struct _CRYPT_SHA512_STATE CRYPT_SHA512_STATE;
typedef struct _FILE_DIRECTORY_INFORMATION FILE_DIRECTORY_INFORMATION;
typedef struct _LDI_CONTEXT LDI_CONTEXT;
typedef struct _MESSAGEBOX_RESULT MESSAGEBOX_RESULT;
typedef struct _XAM_OVERLAPPED XAM_OVERLAPPED;
typedef struct _XAPC XAPC;
typedef struct _XCONTENT_AGGREGATE_DATA XCONTENT_AGGREGATE_DATA;
typedef struct _XDPC XDPC;
typedef struct _XECRYPT_AES_STATE XECRYPT_AES_STATE;
typedef struct _XECRYPT_DES3_STATE XECRYPT_DES3_STATE;
typedef struct _XECRYPT_DES_STATE XECRYPT_DES_STATE;
typedef struct _XECRYPT_HMACSHA_STATE XECRYPT_HMACSHA_STATE;
typedef struct _XECRYPT_MD5_STATE XECRYPT_MD5_STATE;
typedef struct _XECRYPT_RC4_STATE XECRYPT_RC4_STATE;
typedef struct _XECRYPT_RSA XECRYPT_RSA;
typedef struct _XECRYPT_SHA256_STATE XECRYPT_SHA256_STATE;
typedef struct _XECRYPT_SHA512_STATE XECRYPT_SHA512_STATE;
typedef struct _XECRYPT_SHA_STATE XECRYPT_SHA_STATE;
typedef struct _XECRYPT_SIG XECRYPT_SIG;
typedef struct _XE_CONSOLE_CERTIFICATE XE_CONSOLE_CERTIFICATE;
typedef struct _XE_CONSOLE_ID XE_CONSOLE_ID;
typedef struct _XMA_CONTEXT_INIT XMA_CONTEXT_INIT;
typedef struct _XMA_LOOP_DATA XMA_LOOP_DATA;
typedef struct _XMSGSTARTIOREQUEST_UNKNOWNARG XMSGSTARTIOREQUEST_UNKNOWNARG;
typedef struct _XNADDR XNADDR;
typedef struct _XNDNS XNDNS;
typedef struct _XNQOS XNQOS;
typedef struct _XNetStartupParams XNetStartupParams;
typedef struct _XOVERLAPPED XOVERLAPPED;
typedef struct _XSOCKADDR XSOCKADDR;
typedef struct _XSOCKADDR_IN XSOCKADDR_IN;
typedef struct _XWSABUF XWSABUF;
typedef struct _XWSAOVERLAPPED XWSAOVERLAPPED;
typedef struct _X_ASSET_ID X_ASSET_ID;
typedef struct _X_AVATAR_METADATA X_AVATAR_METADATA;
typedef struct _X_CONTENT_DEVICE_DATA X_CONTENT_DEVICE_DATA;
typedef struct _X_D3DFILTER_PARAMETERS X_D3DFILTER_PARAMETERS;
typedef struct _X_DASH_APP_INFO X_DASH_APP_INFO;
typedef struct _X_DASH_BACKSTACK_DATA X_DASH_BACKSTACK_DATA;
typedef struct _X_DISPLAY_INFO X_DISPLAY_INFO;
typedef struct _X_ERWLOCK X_ERWLOCK;
typedef struct _X_EXCEPTION_RECORD X_EXCEPTION_RECORD;
typedef struct _X_EX_TITLE_TERMINATE_REGISTRATION X_EX_TITLE_TERMINATE_REGISTRATION;
typedef struct _X_KEVENT X_KEVENT;
typedef struct _X_KSEMAPHORE X_KSEMAPHORE;
typedef struct _X_KTHREAD X_KTHREAD;
typedef struct _X_MM_QUERY_STATISTICS_RESULT X_MM_QUERY_STATISTICS_RESULT;
typedef struct _X_NUI_DEVICE_STATUS X_NUI_DEVICE_STATUS;
typedef struct _X_PASSPORT_SESSION_TOKEN X_PASSPORT_SESSION_TOKEN;
typedef struct _X_PROFILEENUMRESULT X_PROFILEENUMRESULT;
typedef struct _X_PROFILE_CREATION_INFO X_PROFILE_CREATION_INFO;
typedef struct _X_SECURITY_FAILURE_INFORMATION X_SECURITY_FAILURE_INFORMATION;
typedef struct _X_SINGLE_LIST_ENTRY X_SINGLE_LIST_ENTRY;
typedef struct _X_SLIST_HEADER X_SLIST_HEADER;
typedef struct _X_SMC_DATA X_SMC_DATA;
typedef struct _X_STATS_DETAILS X_STATS_DETAILS;
typedef struct _X_SWAPDISC_ERROR_MESSAGE X_SWAPDISC_ERROR_MESSAGE;
typedef struct _X_TIME_FIELDS X_TIME_FIELDS;
typedef struct _X_USER_DATA X_USER_DATA;
typedef struct _X_USER_PAYMENT_INFO X_USER_PAYMENT_INFO;
typedef struct _X_USER_PROFILE_SETTING X_USER_PROFILE_SETTING;
typedef struct _X_USER_SIGNIN_INFO X_USER_SIGNIN_INFO;
typedef struct _X_VIDEO_MODE X_VIDEO_MODE;
typedef struct _X_WSADATA X_WSADATA;
typedef struct _X_XAMACCOUNTINFO X_XAMACCOUNTINFO;
typedef struct _x_fd_set x_fd_set;
typedef struct _xex2_header xex2_header;

#endif /* _NXEDK_WINDEF_H_ */
