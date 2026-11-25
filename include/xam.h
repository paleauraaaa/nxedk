#ifndef _NXEDK_XAM_H_
#define _NXEDK_XAM_H_

#include "windef.h"

/* Prototypes are inferred from Xenia and community declarations, not retail ABI tests.
   Empty parameter lists mark unknown signatures; do not call them as declared. */
#ifdef __cplusplus
extern "C"
{
#endif

DECLSPEC_IMPORT
ULONG
NTAPI
NetDll_WSAStartup(
    ULONG caller,
    USHORT version,
    X_WSADATA *data_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
NetDll_WSACleanup(
    ULONG caller
    );

DECLSPEC_IMPORT
ULONG
NTAPI
NetDll_socket(
    ULONG caller,
    ULONG af,
    ULONG type,
    ULONG protocol
    );

DECLSPEC_IMPORT
ULONG
NTAPI
NetDll_closesocket(
    ULONG caller,
    ULONG socket_handle
    );

DECLSPEC_IMPORT
LONG
NTAPI
NetDll_shutdown(
    ULONG caller,
    ULONG socket_handle,
    LONG how
    );

DECLSPEC_IMPORT
ULONG
NTAPI
NetDll_ioctlsocket(
    ULONG caller,
    ULONG socket_handle,
    ULONG cmd,
    VOID *arg_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
NetDll_setsockopt(
    ULONG caller,
    ULONG socket_handle,
    ULONG level,
    ULONG optname,
    VOID *optval_ptr,
    ULONG optlen
    );

DECLSPEC_IMPORT
ULONG
NTAPI
NetDll_getsockopt(
    ULONG caller,
    ULONG socket_handle,
    ULONG level,
    ULONG optname,
    VOID *optval_ptr,
    ULONG *optlen
    );

DECLSPEC_IMPORT
ULONG
NTAPI
NetDll_getsockname(
    ULONG caller,
    ULONG socket_handle,
    VOID *buf_ptr,
    ULONG *len_ptr
    );

DECLSPEC_IMPORT VOID NTAPI NetDll_getpeername();

DECLSPEC_IMPORT
ULONG
NTAPI
NetDll_bind(
    ULONG caller,
    ULONG socket_handle,
    XSOCKADDR_IN *name,
    ULONG namelen
    );

DECLSPEC_IMPORT
ULONG
NTAPI
NetDll_connect(
    ULONG caller,
    ULONG socket_handle,
    XSOCKADDR *name,
    ULONG namelen
    );

DECLSPEC_IMPORT
ULONG
NTAPI
NetDll_listen(
    ULONG caller,
    ULONG socket_handle,
    LONG backlog
    );

DECLSPEC_IMPORT
ULONG
NTAPI
NetDll_accept(
    ULONG caller,
    ULONG socket_handle,
    XSOCKADDR *addr_ptr,
    ULONG *addrlen_ptr
    );

DECLSPEC_IMPORT
LONG
NTAPI
NetDll_select(
    ULONG caller,
    ULONG nfds,
    x_fd_set *readfds,
    x_fd_set *writefds,
    x_fd_set *exceptfds,
    VOID *timeout_ptr
    );

DECLSPEC_IMPORT VOID NTAPI NetDll_WSAGetOverlappedResult();

DECLSPEC_IMPORT VOID NTAPI NetDll_WSACancelOverlappedIO();

DECLSPEC_IMPORT
ULONG
NTAPI
NetDll_recv(
    ULONG caller,
    ULONG socket_handle,
    VOID *buf_ptr,
    ULONG buf_len,
    ULONG flags
    );

DECLSPEC_IMPORT VOID NTAPI NetDll_WSARecv();

DECLSPEC_IMPORT
ULONG
NTAPI
NetDll_recvfrom(
    ULONG caller,
    ULONG socket_handle,
    VOID *buf_ptr,
    ULONG buf_len,
    ULONG flags,
    XSOCKADDR_IN *from_ptr,
    ULONG *fromlen_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
NetDll_WSARecvFrom(
    ULONG caller,
    ULONG socket,
    XWSABUF *buffers_ptr,
    ULONG buffer_count,
    ULONG *num_bytes_recv,
    ULONG *flags_ptr,
    XSOCKADDR_IN *from_addr,
    XWSAOVERLAPPED *overlapped_ptr,
    VOID *completion_routine_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
NetDll_send(
    ULONG caller,
    ULONG socket_handle,
    VOID *buf_ptr,
    ULONG buf_len,
    ULONG flags
    );

DECLSPEC_IMPORT VOID NTAPI NetDll_WSASend();

DECLSPEC_IMPORT
ULONG
NTAPI
NetDll_sendto(
    ULONG caller,
    ULONG socket_handle,
    VOID *buf_ptr,
    ULONG buf_len,
    ULONG flags,
    XSOCKADDR_IN *to_ptr,
    ULONG to_len
    );

DECLSPEC_IMPORT
ULONG
NTAPI
NetDll_WSASendTo(
    ULONG caller,
    ULONG socket_handle,
    XWSABUF *buffers,
    ULONG num_buffers,
    ULONG *num_bytes_sent,
    ULONG flags,
    XSOCKADDR_IN *to_ptr,
    ULONG to_len,
    XWSAOVERLAPPED *overlapped,
    VOID *completion_routine
    );

DECLSPEC_IMPORT
ULONG
NTAPI
NetDll_inet_addr(
    CONST CHAR *addr_ptr
    );

DECLSPEC_IMPORT ULONG NTAPI NetDll_WSAGetLastError(VOID);

DECLSPEC_IMPORT
VOID
NTAPI
NetDll_WSASetLastError(
    ULONG error_code
    );

DECLSPEC_IMPORT ULONG NTAPI NetDll_WSACreateEvent(VOID);

DECLSPEC_IMPORT
ULONG
NTAPI
NetDll_WSACloseEvent(
    ULONG event_handle
    );

DECLSPEC_IMPORT
ULONG
NTAPI
NetDll_WSASetEvent(
    ULONG event_handle
    );

DECLSPEC_IMPORT
ULONG
NTAPI
NetDll_WSAResetEvent(
    ULONG event_handle
    );

DECLSPEC_IMPORT
ULONG
NTAPI
NetDll_WSAWaitForMultipleEvents(
    ULONG num_events,
    ULONG *events,
    ULONG wait_all,
    ULONG timeout,
    ULONG alertable
    );

DECLSPEC_IMPORT
ULONG
NTAPI
NetDll___WSAFDIsSet(
    ULONG socket_handle,
    x_fd_set *fd_set
    );

DECLSPEC_IMPORT VOID NTAPI NetDll_WSAEventSelect();

DECLSPEC_IMPORT
ULONG
NTAPI
NetDll_WSAStartupEx(
    ULONG caller,
    USHORT version,
    X_WSADATA *data_ptr,
    ULONG versionReq
    );

DECLSPEC_IMPORT
ULONG
NTAPI
NetDll_XNetStartup(
    ULONG caller,
    XNetStartupParams *params
    );

DECLSPEC_IMPORT
ULONG
NTAPI
NetDll_XNetCleanup(
    ULONG caller,
    VOID *params
    );

DECLSPEC_IMPORT
ULONG
NTAPI
NetDll_XNetRandom(
    ULONG caller,
    VOID *buffer_ptr,
    ULONG length
    );

DECLSPEC_IMPORT
ULONG
NTAPI
NetDll_XNetCreateKey(
    ULONG caller,
    ULONG *key_id,
    ULONG *exchange_key
    );

DECLSPEC_IMPORT
ULONG
NTAPI
NetDll_XNetRegisterKey(
    ULONG caller,
    ULONG *key_id,
    ULONG *exchange_key
    );

DECLSPEC_IMPORT
ULONG
NTAPI
NetDll_XNetUnregisterKey(
    ULONG caller,
    ULONG *key_id
    );

DECLSPEC_IMPORT
ULONG
NTAPI
NetDll_XNetXnAddrToInAddr(
    ULONG caller,
    XNADDR *xn_addr,
    VOID *xid,
    VOID *in_addr
    );

DECLSPEC_IMPORT VOID NTAPI NetDll_XNetServerToInAddr();

DECLSPEC_IMPORT VOID NTAPI NetDll_XNetTsAddrToInAddr();

DECLSPEC_IMPORT
ULONG
NTAPI
NetDll_XNetInAddrToXnAddr(
    ULONG caller,
    VOID *in_addr,
    XNADDR *xn_addr,
    VOID *xid
    );

DECLSPEC_IMPORT VOID NTAPI NetDll_XNetInAddrToServer();

DECLSPEC_IMPORT
VOID
NTAPI
NetDll_XNetInAddrToString(
    ULONG caller,
    ULONG in_addr,
    CONST CHAR *string_out,
    ULONG string_size
    );

DECLSPEC_IMPORT VOID NTAPI NetDll_XNetUnregisterInAddr();

DECLSPEC_IMPORT
ULONG
NTAPI
NetDll_XNetXnAddrToMachineId(
    ULONG caller,
    XNADDR *addr_ptr,
    ULONG *id_ptr
    );

DECLSPEC_IMPORT VOID NTAPI NetDll_XNetConnect();

DECLSPEC_IMPORT VOID NTAPI NetDll_XNetGetConnectStatus();

DECLSPEC_IMPORT
ULONG
NTAPI
NetDll_XNetDnsLookup(
    ULONG caller,
    CONST CHAR *host,
    ULONG event_handle,
    ULONG *pdns
    );

DECLSPEC_IMPORT
ULONG
NTAPI
NetDll_XNetDnsRelease(
    ULONG caller,
    XNDNS *dns
    );

DECLSPEC_IMPORT
ULONG
NTAPI
NetDll_XNetQosListen(
    ULONG caller,
    VOID *id,
    VOID *data,
    ULONG data_size,
    ULONG r7,
    ULONG flags
    );

DECLSPEC_IMPORT VOID NTAPI NetDll_XNetQosLookup();

DECLSPEC_IMPORT
ULONG
NTAPI
NetDll_XNetQosServiceLookup(
    ULONG caller,
    ULONG flags,
    ULONG event_handle,
    ULONG *pqos
    );

DECLSPEC_IMPORT
ULONG
NTAPI
NetDll_XNetQosRelease(
    ULONG caller,
    XNQOS *qos
    );

DECLSPEC_IMPORT
ULONG
NTAPI
NetDll_XNetGetTitleXnAddr(
    ULONG caller,
    XNADDR *addr_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
NetDll_XNetGetDebugXnAddr(
    ULONG caller,
    XNADDR *addr_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
NetDll_XNetGetEthernetLinkStatus(
    ULONG caller
    );

DECLSPEC_IMPORT VOID NTAPI NetDll_XNetGetBroadcastVersionStatus();

DECLSPEC_IMPORT VOID NTAPI NetDll_XNetQosGetListenStats();

DECLSPEC_IMPORT
ULONG
NTAPI
NetDll_XNetGetOpt(
    ULONG one,
    ULONG option_id,
    VOID *buffer_ptr,
    ULONG *buffer_size
    );

DECLSPEC_IMPORT VOID NTAPI NetDll_XNetSetOpt();

DECLSPEC_IMPORT
ULONG
NTAPI
NetDll_XNetStartupEx(
    ULONG caller,
    XNetStartupParams *params,
    ULONG versionReq
    );

DECLSPEC_IMPORT VOID NTAPI NetDll_XNetReplaceKey();

DECLSPEC_IMPORT VOID NTAPI NetDll_XNetGetXnAddrPlatform();

DECLSPEC_IMPORT VOID NTAPI NetDll_XNetGetSystemLinkPort();

DECLSPEC_IMPORT
ULONG
NTAPI
NetDll_XNetSetSystemLinkPort(
    ULONG caller,
    ULONG port
    );

DECLSPEC_IMPORT VOID NTAPI NetDll_XNetDnsReverseLookup();

DECLSPEC_IMPORT VOID NTAPI NetDll_XNetDnsReverseRelease();

DECLSPEC_IMPORT VOID NTAPI NetDll_XnpLoadConfigParams();

DECLSPEC_IMPORT VOID NTAPI NetDll_XnpSaveConfigParams();

DECLSPEC_IMPORT VOID NTAPI NetDll_XnpConfigUPnP();

DECLSPEC_IMPORT VOID NTAPI NetDll_XnpConfig();

DECLSPEC_IMPORT VOID NTAPI NetDll_XnpGetConfigStatus();

DECLSPEC_IMPORT VOID NTAPI NetDll_XnpLoadMachineAccount();

DECLSPEC_IMPORT VOID NTAPI NetDll_XnpSaveMachineAccount();

DECLSPEC_IMPORT VOID NTAPI NetDll_XnpCapture();

DECLSPEC_IMPORT VOID NTAPI NetDll_XnpEthernetInterceptSetCallbacks();

DECLSPEC_IMPORT VOID NTAPI NetDll_XnpEthernetInterceptXmit();

DECLSPEC_IMPORT VOID NTAPI NetDll_XnpEthernetInterceptRecv();

DECLSPEC_IMPORT VOID NTAPI NetDll_XnpLogonGetStatus();

DECLSPEC_IMPORT VOID NTAPI NetDll_XnpLogonGetQFlags();

DECLSPEC_IMPORT VOID NTAPI NetDll_XnpLogonSetQFlags();

DECLSPEC_IMPORT VOID NTAPI NetDll_XnpLogonSetQEvent();

DECLSPEC_IMPORT VOID NTAPI NetDll_XnpLogonClearQEvent();

DECLSPEC_IMPORT VOID NTAPI NetDll_XnpLogonGetQVals();

DECLSPEC_IMPORT VOID NTAPI NetDll_XnpLogonSetQVals();

DECLSPEC_IMPORT VOID NTAPI NetDll_XnpLogonSetPState();

DECLSPEC_IMPORT VOID NTAPI NetDll_XnpGetVlanXboxName();

DECLSPEC_IMPORT VOID NTAPI NetDll_XnpSetVlanXboxName();

DECLSPEC_IMPORT VOID NTAPI NetDll_XnpGetActiveSocketList();

DECLSPEC_IMPORT VOID NTAPI NetDll_XnpNoteSystemTime();

DECLSPEC_IMPORT VOID NTAPI NetDll_XnpRegisterKeyForCallerType();

DECLSPEC_IMPORT VOID NTAPI NetDll_XnpUnregisterKeyForCallerType();

DECLSPEC_IMPORT VOID NTAPI NetDll_XnpLogonGetChallenge();

DECLSPEC_IMPORT VOID NTAPI NetDll_XnpLogonClearChallenge();

DECLSPEC_IMPORT VOID NTAPI NetDll_XnpLogonSetChallengeResponse();

DECLSPEC_IMPORT VOID NTAPI NetDll_XnpGetSecAssocList();

DECLSPEC_IMPORT VOID NTAPI NetDll_XnpGetKeyList();

DECLSPEC_IMPORT VOID NTAPI NetDll_XnpGetQosLookupList();

DECLSPEC_IMPORT VOID NTAPI NetDll_XnpPersistTitleState();

DECLSPEC_IMPORT VOID NTAPI NetDll_XnpReplaceKeyForCallerType();

DECLSPEC_IMPORT VOID NTAPI NetDll_XnpEthernetInterceptSetExtendedReceiveCallback();

DECLSPEC_IMPORT VOID NTAPI NetDll_XnpQosHistoryLoad();

DECLSPEC_IMPORT VOID NTAPI NetDll_XnpQosHistorySaveMeasurements();

DECLSPEC_IMPORT VOID NTAPI NetDll_XnpQosHistoryGetEntries();

DECLSPEC_IMPORT VOID NTAPI NetDll_XnpQosHistoryGetAggregateMeasurement();

DECLSPEC_IMPORT VOID NTAPI NetDll_XnpToolSetCallbacks();

DECLSPEC_IMPORT VOID NTAPI NetDll_XnpToolIpProxyInject();

DECLSPEC_IMPORT VOID NTAPI NetDll_XnpUpdateConfigParams();

DECLSPEC_IMPORT VOID NTAPI NetDll_XnpEthernetInterceptXmitAsIp();

DECLSPEC_IMPORT VOID NTAPI NetDll_XnpConfigUPnPPortAndExternalAddr();

DECLSPEC_IMPORT VOID NTAPI NetDll_XmlDownloadStart();

DECLSPEC_IMPORT VOID NTAPI NetDll_XmlDownloadContinue();

DECLSPEC_IMPORT VOID NTAPI NetDll_XmlDownloadStop();

DECLSPEC_IMPORT VOID NTAPI NetDll_XmlDownloadGetParseTime();

DECLSPEC_IMPORT VOID NTAPI NetDll_XmlDownloadGetReceivedDataSize();

DECLSPEC_IMPORT VOID NTAPI XnpGetXwppMemoryLogSnapshot();

DECLSPEC_IMPORT VOID NTAPI XnpGetXwppRuntimeFilter();

DECLSPEC_IMPORT VOID NTAPI NetDll_XHttpStartup();

DECLSPEC_IMPORT VOID NTAPI NetDll_XHttpShutdown();

DECLSPEC_IMPORT VOID NTAPI NetDll_XHttpOpen();

DECLSPEC_IMPORT VOID NTAPI NetDll_XHttpCloseHandle();

DECLSPEC_IMPORT VOID NTAPI NetDll_XHttpConnect();

DECLSPEC_IMPORT VOID NTAPI NetDll_XHttpSetStatusCallback();

DECLSPEC_IMPORT VOID NTAPI NetDll_XHttpOpenRequest();

DECLSPEC_IMPORT VOID NTAPI NetDll_XHttpOpenRequestUsingMemory();

DECLSPEC_IMPORT VOID NTAPI NetDll_XHttpSendRequest();

DECLSPEC_IMPORT VOID NTAPI NetDll_XHttpReceiveResponse();

DECLSPEC_IMPORT VOID NTAPI NetDll_XHttpQueryHeaders();

DECLSPEC_IMPORT VOID NTAPI NetDll_XHttpReadData();

DECLSPEC_IMPORT VOID NTAPI NetDll_XHttpWriteData();

DECLSPEC_IMPORT VOID NTAPI NetDll_XHttpQueryOption();

DECLSPEC_IMPORT VOID NTAPI NetDll_XHttpSetOption();

DECLSPEC_IMPORT VOID NTAPI NetDll_XHttpDoWork();

DECLSPEC_IMPORT VOID NTAPI NetDll_XHttpSetCredentials();

DECLSPEC_IMPORT VOID NTAPI NetDll_XHttpQueryAuthSchemes();

DECLSPEC_IMPORT VOID NTAPI NetDll_XHttpCrackUrlW();

DECLSPEC_IMPORT VOID NTAPI NetDll_XHttpCrackUrl();

DECLSPEC_IMPORT VOID NTAPI NetDll_XHttpCreateUrl();

DECLSPEC_IMPORT VOID NTAPI NetDll_XHttpCreateUrlW();

DECLSPEC_IMPORT VOID NTAPI NetDll_XHttpResetPerfCounters();

DECLSPEC_IMPORT VOID NTAPI NetDll_XHttpGetPerfCounters();

DECLSPEC_IMPORT VOID NTAPI NetDll_UpnpStartup();

DECLSPEC_IMPORT VOID NTAPI NetDll_UpnpCleanup();

DECLSPEC_IMPORT VOID NTAPI NetDll_UpnpSearchCreate();

DECLSPEC_IMPORT VOID NTAPI NetDll_UpnpSearchGetDevices();

DECLSPEC_IMPORT VOID NTAPI NetDll_UpnpDescribeCreate();

DECLSPEC_IMPORT VOID NTAPI NetDll_UpnpDescribeGetResults();

DECLSPEC_IMPORT VOID NTAPI NetDll_UpnpActionCalculateWorkBufferSize();

DECLSPEC_IMPORT VOID NTAPI NetDll_UpnpActionCreate();

DECLSPEC_IMPORT VOID NTAPI NetDll_UpnpActionGetResults();

DECLSPEC_IMPORT VOID NTAPI NetDll_UpnpEventCreate();

DECLSPEC_IMPORT VOID NTAPI NetDll_UpnpEventGetCurrentState();

DECLSPEC_IMPORT VOID NTAPI NetDll_UpnpEventUnsubscribe();

DECLSPEC_IMPORT VOID NTAPI NetDll_UpnpDoWork();

DECLSPEC_IMPORT VOID NTAPI NetDll_UpnpCloseHandle();

DECLSPEC_IMPORT VOID NTAPI XNetLogonGetLoggedOnUsers();

DECLSPEC_IMPORT VOID NTAPI XNetLogonGetNatType();

DECLSPEC_IMPORT VOID NTAPI XNetLogonTaskStart();

DECLSPEC_IMPORT VOID NTAPI XNetLogonTaskClose();

DECLSPEC_IMPORT VOID NTAPI XNetLogonTaskContinue();

DECLSPEC_IMPORT VOID NTAPI XNetLogonGetServiceInfo();

DECLSPEC_IMPORT VOID NTAPI XNetLogonGetUserPrivileges();

DECLSPEC_IMPORT VOID NTAPI XNetLogonSetConsoleCertificate();

DECLSPEC_IMPORT VOID NTAPI XNetLogonGetMachineID();

DECLSPEC_IMPORT VOID NTAPI XNetLogonGetTitleID();

DECLSPEC_IMPORT VOID NTAPI XNetLogonGetTitleVersion();

DECLSPEC_IMPORT VOID NTAPI XNetLogonGetServiceNetworkID();

DECLSPEC_IMPORT VOID NTAPI XNetLogonGetDnsString();

DECLSPEC_IMPORT VOID NTAPI XNetLogonSetTitleID();

DECLSPEC_IMPORT VOID NTAPI XNetLogonGetExtendedStatus();

DECLSPEC_IMPORT VOID NTAPI XNetLogonClearTicketCaches();

DECLSPEC_IMPORT VOID NTAPI XNetLogonInitOverrideInfo();

DECLSPEC_IMPORT VOID NTAPI XNetLogonGetLastUPnPStatus();

DECLSPEC_IMPORT VOID NTAPI XNetLogonGetFlowToken();

DECLSPEC_IMPORT VOID NTAPI XNetLogonGetTicketOpt();

DECLSPEC_IMPORT VOID NTAPI XNetLogonSetTicketOpt();

DECLSPEC_IMPORT VOID NTAPI XNetLogonGetState();

DECLSPEC_IMPORT
ULONG
NTAPI
XamInputGetCapabilities(
    ULONG user_index,
    ULONG flags,
    X_INPUT_CAPABILITIES *caps
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamInputGetState(
    ULONG user_index,
    ULONG flags,
    X_INPUT_STATE *input_state
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamInputSetState(
    ULONG user_index,
    ULONG flags,
    X_INPUT_VIBRATION *vibration
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamInputGetKeystroke(
    ULONG user_index,
    ULONG flags,
    X_INPUT_KEYSTROKE *keystroke
    );

DECLSPEC_IMPORT VOID NTAPI XamInputEnableAutobind();

DECLSPEC_IMPORT VOID NTAPI XamInputRawState();

DECLSPEC_IMPORT VOID NTAPI XamEnableSystemAppInput();

DECLSPEC_IMPORT VOID NTAPI XamInputGetDeviceStats();

DECLSPEC_IMPORT
ULONG
NTAPI
XamInputGetKeystrokeEx(
    ULONG *user_index_ptr,
    ULONG flags,
    X_INPUT_KEYSTROKE *keystroke
    );

DECLSPEC_IMPORT VOID NTAPI XamInputGetKeystrokeHud();

DECLSPEC_IMPORT VOID NTAPI XamInputSetLayoutKeyboard();

DECLSPEC_IMPORT VOID NTAPI XamInputToggleKeyLocks();

DECLSPEC_IMPORT VOID NTAPI XamInputResetLayoutKeyboard();

DECLSPEC_IMPORT VOID NTAPI XamInputGetKeystrokeHudEx();

DECLSPEC_IMPORT VOID NTAPI XamInputSetKeyboardTranslationHud();

DECLSPEC_IMPORT VOID NTAPI XamSetInactivityTime();

DECLSPEC_IMPORT
ULONG
NTAPI
XamEnableInactivityProcessing(
    ULONG inactivity_index,
    ULONG enable
    );

DECLSPEC_IMPORT VOID NTAPI XamResetInactivity(VOID);

DECLSPEC_IMPORT VOID NTAPI XamSetInactivityTimeFromConfig();

DECLSPEC_IMPORT
VOID
NTAPI
XamLoaderGetMediaInfo(
    ULONG *media_type,
    ULONG *unk2
    );

DECLSPEC_IMPORT
VOID
NTAPI
XamLoaderLaunchTitle(
    CONST CHAR *raw_name_ptr,
    ULONG flags
    );

DECLSPEC_IMPORT
VOID
NTAPI
XamLaunchNewImage(
    CONST CHAR *raw_name_ptr,
    ULONG flags
    );

DECLSPEC_IMPORT VOID NTAPI XamLoaderLaunchTitleEx();

DECLSPEC_IMPORT
ULONG
NTAPI
XamLoaderSetLaunchData(
    VOID *data,
    ULONG size
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XSetLaunchData(
    VOID *data,
    ULONG size
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamLoaderGetLaunchDataSize(
    ULONG *size_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XGetLaunchDataSize(
    ULONG *size_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamLoaderGetLaunchData(
    VOID *buffer_ptr,
    ULONG buffer_size
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XGetLaunchData(
    VOID *buffer_ptr,
    ULONG buffer_size
    );

DECLSPEC_IMPORT VOID NTAPI XamLoaderTerminateTitle(VOID);

DECLSPEC_IMPORT VOID NTAPI XamTerminateTitle(VOID);

DECLSPEC_IMPORT ULONG NTAPI XamLoaderGetDvdTrayState(VOID);

DECLSPEC_IMPORT ULONG NTAPI XGetTrayState(VOID);

DECLSPEC_IMPORT VOID NTAPI XamLoaderGetGameInfo();

DECLSPEC_IMPORT VOID NTAPI XamGetGameInfo();

DECLSPEC_IMPORT VOID NTAPI XamLoaderLaunchTitleOnDvd();

DECLSPEC_IMPORT VOID NTAPI XamLoaderSetSpindleSpeed();

DECLSPEC_IMPORT VOID NTAPI XamSetDvdSpindleSpeed();

DECLSPEC_IMPORT VOID NTAPI XamTaskCreateQueue();

DECLSPEC_IMPORT VOID NTAPI XamTaskSchedule();

DECLSPEC_IMPORT VOID NTAPI XamTaskReschedule();

DECLSPEC_IMPORT
ULONG
NTAPI
XamTaskCloseHandle(
    ULONG obj_handle
    );

DECLSPEC_IMPORT VOID NTAPI XamTaskCancel();

DECLSPEC_IMPORT ULONG NTAPI XamTaskShouldExit(VOID);

DECLSPEC_IMPORT VOID NTAPI XamTaskWaitOnCompletion();

DECLSPEC_IMPORT VOID NTAPI XamTaskModify();

DECLSPEC_IMPORT VOID NTAPI XamTaskGetCurrentTask();

DECLSPEC_IMPORT VOID NTAPI XamTaskGetAttributes();

DECLSPEC_IMPORT VOID NTAPI XamExecutingOnBehalfOfTitle();

DECLSPEC_IMPORT VOID NTAPI XamInputSendStayAliveRequest();

DECLSPEC_IMPORT VOID NTAPI XamInputGetUserVibrationLevel();

DECLSPEC_IMPORT
ULONG
NTAPI
XamIsSystemTitleId(
    ULONG title_id
    );

DECLSPEC_IMPORT VOID NTAPI XamLoaderIsTitleTerminatePending();

DECLSPEC_IMPORT VOID NTAPI XamInputSetTextMessengerIndicator();

DECLSPEC_IMPORT VOID NTAPI XamLoaderGetPriorTitleId();

DECLSPEC_IMPORT
ULONG
NTAPI
XamIsXbox1TitleId(
    ULONG title_id
    );

DECLSPEC_IMPORT VOID NTAPI XamInputSetKeyLocks();

DECLSPEC_IMPORT VOID NTAPI XamInputGetKeyLocks();

DECLSPEC_IMPORT VOID NTAPI XamTaskGetStatus();

DECLSPEC_IMPORT VOID NTAPI XamGetRootObj();

DECLSPEC_IMPORT VOID NTAPI XamDevAuthSetFault();

DECLSPEC_IMPORT VOID NTAPI XamGetDefaultSystemImage();

DECLSPEC_IMPORT VOID NTAPI XamGetWCNConfigFile();

DECLSPEC_IMPORT VOID NTAPI XamSetPowerMode();

DECLSPEC_IMPORT VOID NTAPI XamExecuteChallenge();

DECLSPEC_IMPORT VOID NTAPI XamGetDefaultImage();

DECLSPEC_IMPORT VOID NTAPI XamMuteSound();

DECLSPEC_IMPORT ULONG NTAPI XamGetOnlineSchema(VOID);

DECLSPEC_IMPORT VOID NTAPI XamSetDashContext();

DECLSPEC_IMPORT VOID NTAPI XamGetDashContext();

DECLSPEC_IMPORT VOID NTAPI XamIsCurrentTitleDash();

DECLSPEC_IMPORT ULONG NTAPI XamGetCurrentTitleId(VOID);

DECLSPEC_IMPORT VOID NTAPI XamSetCurrentTitleDash();

DECLSPEC_IMPORT VOID NTAPI XamAllocHeapFreeSpace();

DECLSPEC_IMPORT VOID NTAPI XamSetDashContextEx();

DECLSPEC_IMPORT VOID NTAPI XamGetDashContextEx();

DECLSPEC_IMPORT VOID NTAPI XamSetHudContext();

DECLSPEC_IMPORT VOID NTAPI XamGetHudContext();

DECLSPEC_IMPORT VOID NTAPI XCustomGetBannerImage();

DECLSPEC_IMPORT ULONG NTAPI Refresh(VOID);

DECLSPEC_IMPORT ULONG NTAPI XamCustomSetBannerImage(VOID);

DECLSPEC_IMPORT VOID NTAPI XCustomSetAction();

DECLSPEC_IMPORT VOID NTAPI XCustomGetLastActionPress();

DECLSPEC_IMPORT VOID NTAPI XCustomSetDynamicActions();

DECLSPEC_IMPORT VOID NTAPI XCustomBroadcastActionEvent();

DECLSPEC_IMPORT VOID NTAPI XCustomGetLastActionPressEx();

DECLSPEC_IMPORT VOID NTAPI XCustomRegisterDynamicActions(VOID);

DECLSPEC_IMPORT VOID NTAPI XCustomUnregisterDynamicActions();

DECLSPEC_IMPORT VOID NTAPI XCustomGetCurrentGamercard();

DECLSPEC_IMPORT VOID NTAPI XamDbgPrint();

DECLSPEC_IMPORT VOID NTAPI XamDbgSetOutputLevel();

DECLSPEC_IMPORT VOID NTAPI XamDbgSetBreakLevel();

DECLSPEC_IMPORT
VOID
NTAPI
XamLoaderGetMediaInfoEx(
    ULONG *media_type,
    ULONG *unk2,
    ULONG *unk3
    );

DECLSPEC_IMPORT VOID NTAPI XamLoaderSetGameInfo();

DECLSPEC_IMPORT VOID NTAPI XamFormatMessage();

DECLSPEC_IMPORT VOID NTAPI XamUniSortCmpString();

DECLSPEC_IMPORT VOID NTAPI XamFormatTimeString();

DECLSPEC_IMPORT VOID NTAPI XamFormatDateString();

DECLSPEC_IMPORT
ULONG
NTAPI
XamGetLocaleDateFormat(
    ULONG locale
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamAlloc(
    ULONG flags,
    ULONG size,
    ULONG *out_ptr
    );

DECLSPEC_IMPORT VOID NTAPI XamAllocEx();

DECLSPEC_IMPORT
ULONG
NTAPI
XamFree(
    ULONG *ptr
    );

DECLSPEC_IMPORT VOID NTAPI XamAllocSize();

DECLSPEC_IMPORT VOID NTAPI XamAllocMountIPTVHeap();

DECLSPEC_IMPORT VOID NTAPI XamAllocUnmountIPTVHeap();

DECLSPEC_IMPORT VOID NTAPI XamAllocFreeIPTVHeap();

DECLSPEC_IMPORT VOID NTAPI XamDeviceRemap();

DECLSPEC_IMPORT VOID NTAPI XamLoaderGetClearCache();

DECLSPEC_IMPORT VOID NTAPI XamLoaderSetClearCache();

DECLSPEC_IMPORT
ULONG
NTAPI
XMsgInProcessCall(
    ULONG app,
    ULONG message,
    ULONG arg1,
    ULONG arg2
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XMsgCompleteIORequest(
    XAM_OVERLAPPED *overlapped_ptr,
    ULONG result,
    ULONG extended_error,
    ULONG length
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XMsgSystemProcessCall(
    ULONG app,
    ULONG message,
    ULONG buffer,
    ULONG buffer_length
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XMsgStartIORequest(
    ULONG app,
    ULONG message,
    XAM_OVERLAPPED *overlapped_ptr,
    ULONG buffer_ptr,
    ULONG buffer_length
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XMsgCancelIORequest(
    XAM_OVERLAPPED *overlapped_ptr,
    ULONG wait
    );

DECLSPEC_IMPORT VOID NTAPI XMsgAcquireAsyncMessageFromOverlapped();

DECLSPEC_IMPORT VOID NTAPI XMsgReleaseAsyncMessageToOverlapped();

DECLSPEC_IMPORT
ULONG
NTAPI
XamGetOverlappedResult(
    XAM_OVERLAPPED *overlapped_ptr,
    ULONG *length_ptr,
    ULONG wait
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XMsgStartIORequestEx(
    ULONG app,
    ULONG message,
    XAM_OVERLAPPED *overlapped_ptr,
    ULONG buffer_ptr,
    ULONG buffer_length,
    XMSGSTARTIOREQUEST_UNKNOWNARG *unknown_ptr
    );

DECLSPEC_IMPORT VOID NTAPI XamAppAllocateInterappWorkspace();

DECLSPEC_IMPORT VOID NTAPI XamAppGetInterappWorkspace();

DECLSPEC_IMPORT VOID NTAPI XamAppFreeInterappWorkspace();

DECLSPEC_IMPORT
ULONG
NTAPI
XamFeatureEnabled(
    ULONG app_id
    );

DECLSPEC_IMPORT VOID NTAPI XamFeatureEnforceImageBudget();

DECLSPEC_IMPORT VOID NTAPI XamFeatureSetMask();

DECLSPEC_IMPORT VOID NTAPI XamFeatureEnableDisable();

DECLSPEC_IMPORT VOID NTAPI XuiControlSetItemAssociation();

DECLSPEC_IMPORT VOID NTAPI XamGetTitleGlobalStorageValue();

DECLSPEC_IMPORT VOID NTAPI XamSetTitleGlobalStorageValue();

DECLSPEC_IMPORT VOID NTAPI XamUserValidateAvatarManifest();

DECLSPEC_IMPORT VOID NTAPI XamUserValidateAvatarMetadata();

DECLSPEC_IMPORT
LONG
NTAPI
XamUserGetDeviceContext(
    ULONG user_index,
    ULONG device_type,
    ULONG *out_ptr
    );

DECLSPEC_IMPORT VOID NTAPI XamUserLookupDevice();

DECLSPEC_IMPORT
LONG
NTAPI
XamUserGetXUID(
    ULONG user_index,
    ULONG type_mask,
    ULONGLONG *xuid_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamUserLogon(
    ULONGLONG *xuids_ptr,
    ULONG flags,
    XAM_OVERLAPPED *overlapped_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamUserGetGamerTag(
    ULONG user_index,
    ULONG buffer,
    ULONG buffer_len
    );

DECLSPEC_IMPORT VOID NTAPI XamUserGetUserIndexMask();

DECLSPEC_IMPORT
ULONG
NTAPI
XamUserGetName(
    ULONG user_index,
    ULONG buffer,
    ULONG buffer_len
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamLookupCommonStringByIndex(
    ULONG string_index
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamUserGetSigninState(
    ULONG user_index
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamUserGetIndexFromXUID(
    ULONGLONG xuid,
    ULONG flags,
    ULONG *index
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamUserCheckPrivilege(
    ULONG user_index,
    ULONG mask,
    ULONG *out_value
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamUserAreUsersFriends(
    ULONG user_index,
    ULONGLONG *xuids_ptr,
    ULONG xuids_count,
    ULONG *are_friends_ptr,
    XAM_OVERLAPPED *overlapped_ptr
    );

DECLSPEC_IMPORT VOID NTAPI XamSetUserPresetPresenceState();

DECLSPEC_IMPORT VOID NTAPI XamGetUserPresetPresenceState();

DECLSPEC_IMPORT
ULONG
NTAPI
XamUserGetUserFlagsFromXUID(
    ULONGLONG xuid
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamUserGetMembershipTierFromXUID(
    ULONGLONG xuid
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamUserGetMembershipTypeFromXUID(
    ULONGLONG xuid
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamUserGetOnlineCountryFromXUID(
    ULONGLONG xuid
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamUserReadProfileSettings(
    ULONG title_id,
    ULONG user_index,
    ULONG xuid_count,
    ULONGLONG *xuids,
    ULONG setting_count,
    ULONG *setting_ids,
    ULONG *buffer_size_ptr,
    VOID *buffer_ptr,
    VOID *overlapped
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamUserWriteProfileSettings(
    ULONG title_id,
    ULONG user_index,
    ULONG setting_count,
    X_USER_PROFILE_SETTING *settings,
    VOID *overlapped
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamUserGetMembershipTier(
    ULONG user_index
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamUserGetMembershipType(
    ULONG user_index
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamUserGetUserFlags(
    ULONG user_index
    );

DECLSPEC_IMPORT VOID NTAPI XamUserGetRequestedUserIndexMask();

DECLSPEC_IMPORT VOID NTAPI XamUserIsGuest();

DECLSPEC_IMPORT VOID NTAPI XamUserProfileSync();

DECLSPEC_IMPORT VOID NTAPI XamUserFlushLogonQueue();

DECLSPEC_IMPORT
ULONG
NTAPI
XamUserIsOnlineEnabled(
    ULONG user_index
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamUserGetCachedUserFlags(
    ULONG user_index
    );

DECLSPEC_IMPORT VOID NTAPI XamAreMixedAccountsSignedIn();

DECLSPEC_IMPORT
ULONG
NTAPI
XamUserLogonEx(
    X_PROFILEENUMRESULT *profile_ptr,
    ULONG flags,
    XAM_OVERLAPPED *overlapped_ptr
    );

DECLSPEC_IMPORT VOID NTAPI XamSetUserShowMessengerFriends();

DECLSPEC_IMPORT VOID NTAPI XamGetUserShowMessengerFriends();

DECLSPEC_IMPORT
LONG
NTAPI
XamUserGetSigninInfo(
    ULONG user_index,
    ULONG flags,
    X_USER_SIGNIN_INFO *info
    );

DECLSPEC_IMPORT VOID NTAPI XamUserIsPartial();

DECLSPEC_IMPORT
ULONG
NTAPI
XamUserGetOnlineLanguageFromXUID(
    ULONGLONG xuid
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamUserReadProfileSettingsEx(
    ULONG title_id,
    ULONG user_index,
    ULONG xuid_count,
    ULONGLONG *xuids,
    ULONG setting_count,
    ULONG *setting_ids,
    ULONG *buffer_size_ptr,
    ULONG *unkn_buffer_size_ptr,
    VOID *buffer_ptr,
    VOID *overlapped
    );

DECLSPEC_IMPORT VOID NTAPI XamSystemUpdaterLogon();

DECLSPEC_IMPORT VOID NTAPI XamUserGetUsersMissingAvatars();

DECLSPEC_IMPORT ULONG NTAPI XamIsChildAccountSignedIn(VOID);

DECLSPEC_IMPORT VOID NTAPI XamUserPrefetchProfileSettings();

DECLSPEC_IMPORT VOID NTAPI XamUserInvalidateProfileSetting();

DECLSPEC_IMPORT
ULONG
NTAPI
XamProfileCreate(
    ULONG flags,
    ULONG *device_id,
    ULONGLONG xuid,
    X_XAMACCOUNTINFO *account,
    X_USER_PAYMENT_INFO *payment_info,
    X_PASSPORT_SESSION_TOKEN *user_token,
    X_PASSPORT_SESSION_TOKEN *owner_token,
    ULONG *profile_info_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamProfileCreateEnumerator(
    ULONG device_id,
    ULONG *handle_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamProfileEnumerate(
    ULONG handle,
    ULONG flags,
    VOID *buffer,
    XAM_OVERLAPPED *overlapped
    );

DECLSPEC_IMPORT VOID NTAPI XamProfileDelete();

DECLSPEC_IMPORT
ULONG
NTAPI
XamProfileGetCreationStatus(
    X_PROFILE_CREATION_INFO *profile_info,
    ULONGLONG *offline_xuid
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamProfileFindAccount(
    ULONGLONG offline_xuid,
    X_XAMACCOUNTINFO *account_ptr,
    ULONG *device_id
    );

DECLSPEC_IMPORT VOID NTAPI XamProfileRenameAccount();

DECLSPEC_IMPORT
ULONG
NTAPI
XamProfileOpen(
    ULONGLONG xuid,
    CONST CHAR *mount_path,
    ULONG flags,
    XCONTENT_AGGREGATE_DATA *content_data_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamProfileClose(
    CONST CHAR *mount_name
    );

DECLSPEC_IMPORT VOID NTAPI XamProfileSaveAccountInfo();

DECLSPEC_IMPORT VOID NTAPI XamProfileLoadAccountInfo();

DECLSPEC_IMPORT VOID NTAPI XamProfileRecoverTitle();

DECLSPEC_IMPORT VOID NTAPI XamProfileSaveWindowsLiveCredentials();

DECLSPEC_IMPORT VOID NTAPI XamProfileLoadWindowsLiveCredentials();

DECLSPEC_IMPORT VOID NTAPI XamProfileIsSaveWindowsLiveCredsEnabled();

DECLSPEC_IMPORT VOID NTAPI XamProfileSetSaveWindowsLiveCredsEnabled();

DECLSPEC_IMPORT VOID NTAPI XamSetProfileReadTestHook();

DECLSPEC_IMPORT VOID NTAPI XamProfileGetLastSync();

DECLSPEC_IMPORT VOID NTAPI XamAccountRecoveryRecoverTitle();

DECLSPEC_IMPORT VOID NTAPI XamProfileControlPec();

DECLSPEC_IMPORT VOID NTAPI XamProfileControlXgi();

DECLSPEC_IMPORT VOID NTAPI XamAppLoad();

DECLSPEC_IMPORT VOID NTAPI XamAppUnloadSelf();

DECLSPEC_IMPORT VOID NTAPI XamAppUnloadStack();

DECLSPEC_IMPORT VOID NTAPI XamSendMessageToLoadedApps();

DECLSPEC_IMPORT VOID NTAPI XamAppRequestLoad();

DECLSPEC_IMPORT VOID NTAPI XamAppUnrequestLoad();

DECLSPEC_IMPORT VOID NTAPI XamNavigate();

DECLSPEC_IMPORT VOID NTAPI XamRegisterSysApp();

DECLSPEC_IMPORT VOID NTAPI XamUnregisterSysApp();

DECLSPEC_IMPORT VOID NTAPI XamAppReinitialize();

DECLSPEC_IMPORT
ULONG
NTAPI
XamCreateEnumeratorHandle(
    ULONG user_index,
    ULONG app_id,
    ULONG open_message,
    ULONG close_message,
    ULONG extra_size,
    ULONG item_count,
    ULONG flags,
    ULONG *out_handle
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamGetPrivateEnumStructureFromHandle(
    ULONG handle,
    ULONG *out_object_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamEnumerate(
    ULONG handle,
    ULONG flags,
    VOID *buffer,
    ULONG buffer_length,
    ULONG *items_returned,
    XAM_OVERLAPPED *overlapped
    );

DECLSPEC_IMPORT VOID NTAPI XamLoadSysApp();

DECLSPEC_IMPORT VOID NTAPI XamUnloadSysApp();

DECLSPEC_IMPORT VOID NTAPI XamReloadSysApp();

DECLSPEC_IMPORT VOID NTAPI XamAppLoadPass2SysApps();

DECLSPEC_IMPORT VOID NTAPI XamProfileGetLiveLegalLocale();

DECLSPEC_IMPORT
ULONG
NTAPI
XamUserIsParentalControlled(
    ULONG user_index
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamContentLaunchImageFromFileInternal(
    CONST CHAR *image_location,
    CONST CHAR *xex_name
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamContentCreate(
    ULONG user_index,
    CONST CHAR *root_name,
    VOID *content_data_ptr,
    ULONG flags,
    ULONG *disposition_ptr,
    ULONG *license_mask_ptr,
    XAM_OVERLAPPED *overlapped_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamContentCreateEx(
    ULONG user_index,
    CONST CHAR *root_name,
    VOID *content_data_ptr,
    ULONG flags,
    ULONG *disposition_ptr,
    ULONG *license_mask_ptr,
    ULONG cache_size,
    ULONGLONG content_size,
    XAM_OVERLAPPED *overlapped_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamContentClose(
    CONST CHAR *root_name,
    XAM_OVERLAPPED *overlapped_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamContentDelete(
    ULONG user_index,
    VOID *content_data_ptr,
    XAM_OVERLAPPED *overlapped_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamContentCreateEnumerator(
    ULONG user_index,
    ULONG device_id,
    ULONG content_type,
    ULONG content_flags,
    ULONG items_per_enumerate,
    ULONG *buffer_size_ptr,
    ULONG *handle_out
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamContentCreateDeviceEnumerator(
    ULONG content_type,
    ULONG content_flags,
    ULONG max_count,
    ULONG *buffer_size_ptr,
    ULONG *handle_out
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamContentGetDeviceData(
    ULONG device_id,
    X_CONTENT_DEVICE_DATA *device_data
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamContentGetDeviceName(
    ULONG device_id,
    ULONG name_buffer_ptr,
    ULONG name_capacity
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamContentSetThumbnail(
    ULONG user_index,
    VOID *content_data_ptr,
    VOID *buffer_ptr,
    ULONG buffer_size,
    XAM_OVERLAPPED *overlapped_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamContentGetThumbnail(
    ULONG user_index,
    VOID *content_data_ptr,
    VOID *buffer_ptr,
    ULONG *buffer_size_ptr,
    XAM_OVERLAPPED *overlapped_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamContentGetCreator(
    ULONG user_index,
    VOID *content_data_ptr,
    ULONG *is_creator_ptr,
    ULONGLONG *creator_xuid_ptr,
    XAM_OVERLAPPED *overlapped_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamContentLaunchImage(
    ULONG user_index,
    VOID *content_data_ptr,
    CONST CHAR *xex_path
    );

DECLSPEC_IMPORT VOID NTAPI XamContentGetAttributes();

DECLSPEC_IMPORT VOID NTAPI XamContentGetDeviceState();

DECLSPEC_IMPORT
ULONG
NTAPI
XamContentGetLicenseMask(
    ULONG *mask_ptr,
    VOID *overlapped_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamContentFlush(
    CONST CHAR *root_name,
    XAM_OVERLAPPED *overlapped_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamContentResolve(
    ULONG user_index,
    VOID *content_data_ptr,
    CONST CHAR *path_ptr,
    ULONG path_size,
    ULONG create_directory,
    CONST CHAR *root_name_ptr,
    XAM_OVERLAPPED *overlapped_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamContentOpenFile(
    ULONG user_index,
    CONST CHAR *root_name,
    CONST CHAR *path,
    ULONG flags,
    ULONG *disposition_ptr,
    ULONG *license_mask_ptr,
    XAM_OVERLAPPED *overlapped_ptr
    );

DECLSPEC_IMPORT VOID NTAPI XamContentInstall();

DECLSPEC_IMPORT VOID NTAPI XamContentLockUnlockPackageHeaders();

DECLSPEC_IMPORT VOID NTAPI XamContentCopyInternal();

DECLSPEC_IMPORT VOID NTAPI XamContentMoveInternal();

DECLSPEC_IMPORT VOID NTAPI XamContentGetMetaDataInternal();

DECLSPEC_IMPORT
ULONG
NTAPI
XamContentCreateEnumeratorInternal(
    ULONGLONG xuid,
    ULONG device_id,
    ULONG content_type,
    ULONG title_id,
    ULONG content_flags,
    ULONG items_per_enumerate,
    ULONG *buffer_size_ptr,
    ULONG *handle_out
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamContentDeleteInternal(
    VOID *content_data_ptr,
    XAM_OVERLAPPED *overlapped_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamContentCreateInternal(
    CONST CHAR *root_name,
    VOID *content_data_ptr,
    ULONG flags,
    ULONG *disposition_ptr,
    ULONG *license_mask_ptr,
    ULONG cache_size,
    ULONGLONG content_size,
    XAM_OVERLAPPED *overlapped_ptr
    );

DECLSPEC_IMPORT VOID NTAPI XamContentSetThumbnailInternal();

DECLSPEC_IMPORT
ULONG
NTAPI
XamContentLaunchImageInternal(
    VOID *content_data_ptr,
    CONST CHAR *xex_path
    );

DECLSPEC_IMPORT VOID NTAPI XamContentWritePackageHeader();

DECLSPEC_IMPORT VOID NTAPI XamContentDismountAndClosePackage();

DECLSPEC_IMPORT
ULONG
NTAPI
XamContentResolveInternal(
    VOID *content_data_ptr,
    CONST CHAR *path_ptr,
    ULONG path_size,
    ULONG create_directory,
    CONST CHAR *root_name_ptr,
    XAM_OVERLAPPED *overlapped_ptr
    );

DECLSPEC_IMPORT VOID NTAPI XamContentGetAttributesInternal();

DECLSPEC_IMPORT VOID NTAPI XamContentOpenFileInternal();

DECLSPEC_IMPORT
ULONG
NTAPI
XamContentAggregateCreateEnumerator(
    ULONGLONG xuid,
    ULONG device_id,
    ULONG content_type,
    ULONG title_id,
    ULONG *handle_out
    );

DECLSPEC_IMPORT VOID NTAPI XamContentCreateAndMountPackage();

DECLSPEC_IMPORT VOID NTAPI XamContentOpenPackageFile();

DECLSPEC_IMPORT VOID NTAPI XamContentMountPackage();

DECLSPEC_IMPORT VOID NTAPI XamContentFlushPackage();

DECLSPEC_IMPORT VOID NTAPI XamContentClosePackageFile();

DECLSPEC_IMPORT VOID NTAPI XamContentDuplicateFileHandle();

DECLSPEC_IMPORT
ULONG
NTAPI
XamGetExecutionId(
    ULONG *info_ptr
    );

DECLSPEC_IMPORT VOID NTAPI XamGetGameRatings();

DECLSPEC_IMPORT ULONG NTAPI XamGetSystemVersion(VOID);

DECLSPEC_IMPORT VOID NTAPI XamContentGetLocalizedString();

DECLSPEC_IMPORT VOID NTAPI XamContentGetDefaultDevice();

DECLSPEC_IMPORT VOID NTAPI XamContentInstallInternal();

DECLSPEC_IMPORT VOID NTAPI XamContentSetMediaMetaDataInternal();

DECLSPEC_IMPORT VOID NTAPI XamContentGetDeviceSerialNumber();

DECLSPEC_IMPORT VOID NTAPI XamContentGetMountedPackageByRootName();

DECLSPEC_IMPORT
VOID
NTAPI
XamContentRegisterChangeCallback(
    ULONG callback
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamNotifyCreateListener(
    ULONGLONG mask,
    ULONG max_version
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XNotifyGetNext(
    ULONG handle,
    ULONG match_id,
    ULONG *id_ptr,
    ULONG *param_ptr
    );

DECLSPEC_IMPORT
VOID
NTAPI
XNotifyPositionUI(
    ULONG position
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XNotifyDelayUI(
    ULONG delay_ms
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XNotifyBroadcast(
    ULONG notification,
    ULONG data
    );

DECLSPEC_IMPORT VOID NTAPI XNotifyRegisterArea();

DECLSPEC_IMPORT
ULONG
NTAPI
XNotifyQueueUI(
    ULONG exnq,
    ULONG dwUserIndex,
    ULONGLONG qwAreas,
    CONST USHORT *displayText_ptr,
    VOID *contextData
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamNotifyCreateListenerInternal(
    ULONGLONG mask,
    ULONG is_system,
    ULONG max_version
    );

DECLSPEC_IMPORT VOID NTAPI XNotifyUISetOptions();

DECLSPEC_IMPORT VOID NTAPI XNotifyUIGetOptions();

DECLSPEC_IMPORT
ULONG
NTAPI
XamContentLaunchImageInternalEx(
    VOID *content_data_ptr,
    CONST CHAR *xex_path,
    ULONG flags
    );

DECLSPEC_IMPORT VOID NTAPI XamShutdown();

DECLSPEC_IMPORT VOID NTAPI XamAllocDevkitHeapAvailable();

DECLSPEC_IMPORT VOID NTAPI XamNotifyCreateListenerRangeInternal();

DECLSPEC_IMPORT VOID NTAPI XNotifyQueueUIEx();

DECLSPEC_IMPORT VOID NTAPI XamAppRequestLoadEx();

DECLSPEC_IMPORT VOID NTAPI XuiPNGTextureLoader();

DECLSPEC_IMPORT VOID NTAPI XuiRenderGetXuiDevice();

DECLSPEC_IMPORT VOID NTAPI XuiDefault_False();

DECLSPEC_IMPORT VOID NTAPI XamUserGetReportingInfo();

DECLSPEC_IMPORT VOID NTAPI XamUpdateStart();

DECLSPEC_IMPORT VOID NTAPI XamUpdateGetProgress();

DECLSPEC_IMPORT VOID NTAPI XamUpdateGetExtenderInstance();

DECLSPEC_IMPORT VOID NTAPI XamUpdateFinish();

DECLSPEC_IMPORT VOID NTAPI XamUpdateAttachExtenderInstance();

DECLSPEC_IMPORT VOID NTAPI XamUpdateAllocateExtenderBuffer();

DECLSPEC_IMPORT VOID NTAPI XamRestartTitleLoadAfterUpdate();

DECLSPEC_IMPORT VOID NTAPI XamUIThreadDisableFontPatching();

DECLSPEC_IMPORT VOID NTAPI XamUpdateGetBaseSystemVersion();

DECLSPEC_IMPORT VOID NTAPI XamUpdateGetCurrentSystemVersion();

DECLSPEC_IMPORT VOID NTAPI XamUIThreadEnableFontPatching();

DECLSPEC_IMPORT VOID NTAPI XamTerminateTitleForUpdate();

DECLSPEC_IMPORT VOID NTAPI XamSystemUpdateInstallLocal();

DECLSPEC_IMPORT VOID NTAPI XamUpdateChainPass3FromPass2();

DECLSPEC_IMPORT
ULONG
NTAPI
XamInputGetCapabilitiesEx(
    ULONG unk,
    ULONG user_index,
    ULONG flags,
    X_INPUT_CAPABILITIES *caps
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamUserIsUnsafeProgrammingAllowed(
    ULONG user_index,
    ULONG unk,
    ULONG *result_ptr
    );

DECLSPEC_IMPORT VOID NTAPI XamDevAuthSetFaultEx();

DECLSPEC_IMPORT VOID NTAPI XamUpdateGetData();

DECLSPEC_IMPORT VOID NTAPI XamCacheIntegrityCheck();

DECLSPEC_IMPORT VOID NTAPI XamCacheStoreFile();

DECLSPEC_IMPORT VOID NTAPI XamCacheFetchFile();

DECLSPEC_IMPORT VOID NTAPI XamCacheOpenFile();

DECLSPEC_IMPORT VOID NTAPI XamCacheCloseFile();

DECLSPEC_IMPORT
ULONG
NTAPI
XamGetCachedTitleName(
    ULONG title_id,
    ULONG title_name_address,
    ULONG *title_name_size_ptr
    );

DECLSPEC_IMPORT VOID NTAPI XamCacheReset();

DECLSPEC_IMPORT VOID NTAPI XamGetCachedGamerTag();

DECLSPEC_IMPORT VOID NTAPI XamGetCachedGamerTagW();

DECLSPEC_IMPORT VOID NTAPI XamCacheDeleteFile();

DECLSPEC_IMPORT VOID NTAPI XamCacheRenameFile();

DECLSPEC_IMPORT
ULONG
NTAPI
XamShowSigninUI(
    ULONG users_needed,
    ULONG flags
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamShowSigninUIEx(
    ULONG users_needed,
    ULONG flags,
    XAM_OVERLAPPED *overlapped_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamShowSigninUIp(
    ULONG user_index,
    ULONG users_needed,
    ULONG flags
    );

DECLSPEC_IMPORT VOID NTAPI XamShowFriendsUI();

DECLSPEC_IMPORT VOID NTAPI XamShowMessagesUI();

DECLSPEC_IMPORT
ULONG
NTAPI
XamShowKeyboardUI(
    ULONG user_index,
    ULONG flags,
    CONST USHORT *default_text,
    CONST USHORT *title,
    CONST USHORT *description,
    CONST USHORT *buffer,
    ULONG buffer_length,
    XAM_OVERLAPPED *overlapped
    );

DECLSPEC_IMPORT VOID NTAPI XamShowQuickChatUI();

DECLSPEC_IMPORT VOID NTAPI XamShowVoiceMailUI();

DECLSPEC_IMPORT
ULONG
NTAPI
XamShowGamerCardUI(
    ULONG user_index
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamShowAchievementsUI(
    ULONG user_index,
    ULONG title_id
    );

DECLSPEC_IMPORT VOID NTAPI XamShowPlayerReviewUI();

DECLSPEC_IMPORT
ULONG
NTAPI
XamShowMarketplaceUI(
    ULONG user_index,
    ULONG ui_type,
    ULONGLONG offer_id,
    ULONG offer_type,
    ULONG content_category,
    ULONG title_id
    );

DECLSPEC_IMPORT VOID NTAPI XamShowPlayersUI();

DECLSPEC_IMPORT VOID NTAPI XamShowUpdaterUI();

DECLSPEC_IMPORT
ULONG
NTAPI
XamShowMessageBoxUI(
    ULONG user_index,
    CONST USHORT *title_ptr,
    CONST USHORT *text_ptr,
    ULONG button_count,
    ULONG *button_ptrs,
    ULONG active_button,
    ULONG flags,
    MESSAGEBOX_RESULT *result_ptr,
    XAM_OVERLAPPED *overlapped
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamShowDeviceSelectorUI(
    ULONG user_index,
    ULONG content_type,
    ULONG content_flags,
    ULONGLONG total_requested,
    ULONG *device_id_ptr,
    XAM_OVERLAPPED *overlapped
    );

DECLSPEC_IMPORT VOID NTAPI XamShowMessageComposeUI();

DECLSPEC_IMPORT VOID NTAPI XamShowGameInviteUI();

DECLSPEC_IMPORT VOID NTAPI XamShowFriendRequestUI();

DECLSPEC_IMPORT
ULONG
NTAPI
XamShowCreateProfileUI(
    ULONG user_index,
    ULONG flag
    );

DECLSPEC_IMPORT VOID NTAPI XamShowGamesUI();

DECLSPEC_IMPORT VOID NTAPI XamShowLiveSignupUI();

DECLSPEC_IMPORT VOID NTAPI XamShowFriendsUIp();

DECLSPEC_IMPORT VOID NTAPI XamShowComplaintUI();

DECLSPEC_IMPORT VOID NTAPI XamShowReputationUI();

DECLSPEC_IMPORT VOID NTAPI XamShowGamerCardUIForXUID();

DECLSPEC_IMPORT
ULONG
NTAPI
XamShowForcedNameChangeUI(
    ULONG user_index
    );

DECLSPEC_IMPORT VOID NTAPI XamShowLiveUpsellUI();

DECLSPEC_IMPORT VOID NTAPI XamShowPasscodeVerifyUI();

DECLSPEC_IMPORT
VOID
NTAPI
XamShowDirtyDiscErrorUI(
    ULONG user_index
    );

DECLSPEC_IMPORT VOID NTAPI XamShowSignupCreditCardUI();

DECLSPEC_IMPORT VOID NTAPI XamShowPrivateChatInviteUI();

DECLSPEC_IMPORT
ULONG
NTAPI
XamShowMessageBoxUIEx(
    ULONG user_index,
    CONST USHORT *title_ptr,
    CONST USHORT *text_ptr,
    ULONG button_count,
    ULONG *button_ptrs,
    ULONG active_button,
    ULONG flags,
    ULONG unknown_unused,
    MESSAGEBOX_RESULT *result_ptr,
    XAM_OVERLAPPED *overlapped
    );

DECLSPEC_IMPORT VOID NTAPI XamShowRecentMessageUI();

DECLSPEC_IMPORT VOID NTAPI XamShowRecentMessageUIEx();

DECLSPEC_IMPORT VOID NTAPI XamShowMessagesUIEx();

DECLSPEC_IMPORT VOID NTAPI XamShowAchievementDetailsUI();

DECLSPEC_IMPORT VOID NTAPI XamShowPersonalizationUI();

DECLSPEC_IMPORT VOID NTAPI XamShowChangeGamerTileUI();

DECLSPEC_IMPORT VOID NTAPI XamShowVoiceSettingsUI();

DECLSPEC_IMPORT VOID NTAPI XamShowVideoChatInviteUI();

DECLSPEC_IMPORT VOID NTAPI XamShowCustomMessageComposeUI();

DECLSPEC_IMPORT VOID NTAPI XamShowCustomPlayerListUI();

DECLSPEC_IMPORT
ULONG
NTAPI
XamShowMarketplaceDownloadItemsUI(
    ULONG user_index,
    ULONG ui_type,
    ULONGLONG *offers,
    ULONG num_offers,
    ULONG *hresult_ptr,
    XAM_OVERLAPPED *overlapped
    );

DECLSPEC_IMPORT VOID NTAPI XamShowMarketplaceUIEx();

DECLSPEC_IMPORT VOID NTAPI XamShowMessageBox();

DECLSPEC_IMPORT VOID NTAPI XamIsSysUiInvokedByXenonButton();

DECLSPEC_IMPORT VOID NTAPI XamIsSysUiInvokedByTitle();

DECLSPEC_IMPORT ULONG NTAPI XamIsUIActive(VOID);

DECLSPEC_IMPORT VOID NTAPI XamSysUiDisableAutoClose();

DECLSPEC_IMPORT
ULONG
NTAPI
XamUserCreateAchievementEnumerator(
    ULONG title_id,
    ULONG user_index,
    ULONGLONG xuid,
    ULONG flags,
    ULONG offset,
    ULONG count,
    ULONG *buffer_size_ptr,
    ULONG *handle_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamReadTile(
    ULONG tile_type,
    ULONG title_id,
    ULONGLONG item_id,
    ULONG user_index,
    ULONG *output_ptr,
    ULONG *buffer_size_ptr,
    VOID *overlapped_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamWriteGamerTile(
    ULONG user_index,
    ULONG title_id,
    ULONG big_tile_id,
    ULONG small_tile_id,
    ULONG for_enumerate,
    XAM_OVERLAPPED *overlapped_ptr
    );

DECLSPEC_IMPORT VOID NTAPI XamWriteTile();

DECLSPEC_IMPORT VOID NTAPI XamReadImage();

DECLSPEC_IMPORT
ULONG
NTAPI
XamUserCreateTitlesPlayedEnumerator(
    ULONG title_id,
    ULONG user_index,
    ULONGLONG xuid,
    ULONG starting_index,
    ULONG game_count,
    ULONG *buffer_size_ptr,
    ULONG *handle_ptr
    );

DECLSPEC_IMPORT VOID NTAPI XamDecompressPNGToTexture();

DECLSPEC_IMPORT
ULONG
NTAPI
XamReadTileToTexture(
    ULONG tile_type,
    ULONG title_id,
    ULONGLONG tile_id,
    ULONG user_index,
    VOID *buffer_ptr,
    ULONG stride,
    ULONG tile_height,
    ULONG overlapped_ptr
    );

DECLSPEC_IMPORT VOID NTAPI XamReadString();

DECLSPEC_IMPORT
ULONG
NTAPI
XamUserCreateStatsEnumerator(
    ULONG title_id,
    ULONG user_index,
    ULONG count,
    ULONG flags,
    ULONG size,
    X_STATS_DETAILS *stats_ptr,
    ULONG *buffer_size_ptr,
    ULONG *handle_ptr
    );

DECLSPEC_IMPORT VOID NTAPI XamPrepareGamerTiles();

DECLSPEC_IMPORT VOID NTAPI XamClearTitle();

DECLSPEC_IMPORT VOID NTAPI XamReadStrings();

DECLSPEC_IMPORT VOID NTAPI XamWriteGamerTileEx();

DECLSPEC_IMPORT
ULONG
NTAPI
XamReadTileEx(
    ULONG tile_type,
    ULONG game_id,
    ULONGLONG item_id,
    ULONG offset,
    ULONG unk1,
    ULONG unk2,
    ULONG *output_ptr,
    ULONG *buffer_size_ptr
    );

DECLSPEC_IMPORT VOID NTAPI XamReadTileToTextureEx();

DECLSPEC_IMPORT VOID NTAPI XamShowMessengerUI();

DECLSPEC_IMPORT VOID NTAPI XamShowKeyboardUIMessenger();

DECLSPEC_IMPORT VOID NTAPI XamShowLiveUpsellUIEx();

DECLSPEC_IMPORT VOID NTAPI XamShowJoinSessionInProgressUI();

DECLSPEC_IMPORT VOID NTAPI XamShowGraduateUserUI();

DECLSPEC_IMPORT VOID NTAPI XamShowGamerCardUIForXUIDp();

DECLSPEC_IMPORT VOID NTAPI XamShowGuideUI();

DECLSPEC_IMPORT
ULONG
NTAPI
XamShowPartyUI(
    ULONG user_index
    );

DECLSPEC_IMPORT VOID NTAPI XamShowPartyInviteUI();

DECLSPEC_IMPORT VOID NTAPI XamUserAddRecentPlayer();

DECLSPEC_IMPORT VOID NTAPI XamUserUpdateRecentPlayer();

DECLSPEC_IMPORT VOID NTAPI XamUserCreatePlayerEnumerator();

DECLSPEC_IMPORT
ULONG
NTAPI
XamParseGamerTileKey(
    X_USER_DATA *key_ptr,
    ULONG *title_id_ptr,
    ULONG *big_tile_id_ptr,
    ULONG *small_tile_id_ptr
    );

DECLSPEC_IMPORT VOID NTAPI XamShowCommunitySessionsUI();

DECLSPEC_IMPORT
ULONG
NTAPI
XamVoiceCreate(
    ULONG user_index,
    ULONG max_attached_packets,
    ULONG *out_voice_ptr
    );

DECLSPEC_IMPORT VOID NTAPI XamVoiceHeadsetPresent();

DECLSPEC_IMPORT
ULONG
NTAPI
XamVoiceSubmitPacket(
    ULONG *unk1,
    ULONG unk2,
    ULONG *unk3
    );

DECLSPEC_IMPORT VOID NTAPI XamVoiceClose();

DECLSPEC_IMPORT VOID NTAPI XamVoiceGetBatteryStatus();

DECLSPEC_IMPORT VOID NTAPI Refresh_();

DECLSPEC_IMPORT VOID NTAPI Refresh_0();

DECLSPEC_IMPORT VOID NTAPI XamShowJoinSessionByIdInProgressUI();

DECLSPEC_IMPORT VOID NTAPI XamShowPartyJoinInProgressUI();

DECLSPEC_IMPORT
ULONG
NTAPI
XamBuildSharedSystemResourceLocator(
    CONST USHORT *filename,
    VOID *buffer_ptr,
    ULONG buffer_count
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamSessionCreateHandle(
    ULONG *handle_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamSessionRefObjByHandle(
    ULONG handle,
    ULONG *obj_ptr
    );

DECLSPEC_IMPORT ULONG NTAPI XamVoiceGetMicArrayStatus(VOID);

DECLSPEC_IMPORT VOID NTAPI XamVoiceSetAudioCaptureRoutine();

DECLSPEC_IMPORT VOID NTAPI XamVoiceGetDirectionalData();

DECLSPEC_IMPORT
ULONG
NTAPI
XamBuildResourceLocator(
    ULONGLONG module,
    CONST USHORT *container,
    CONST USHORT *resource,
    VOID *buffer_ptr,
    ULONG buffer_count
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamBuildLegacySystemResourceLocator(
    CONST USHORT *filename,
    VOID *buffer_ptr,
    ULONG buffer_count
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamBuildGamercardResourceLocator(
    CONST USHORT *filename,
    VOID *buffer_ptr,
    ULONG buffer_count
    );

DECLSPEC_IMPORT VOID NTAPI XamBuildDynamicResourceLocator();

DECLSPEC_IMPORT
ULONG
NTAPI
XamBuildXamResourceLocator(
    CONST USHORT *filename,
    VOID *buffer_ptr,
    ULONG buffer_count
    );

DECLSPEC_IMPORT VOID NTAPI XuiAnimRun();

DECLSPEC_IMPORT VOID NTAPI XuiApplyLocale();

DECLSPEC_IMPORT VOID NTAPI XuiBubbleMessage();

DECLSPEC_IMPORT VOID NTAPI XuiControlIsBackButton();

DECLSPEC_IMPORT VOID NTAPI XuiControlIsNavButton();

DECLSPEC_IMPORT VOID NTAPI XuiCreateObject();

DECLSPEC_IMPORT VOID NTAPI XuiDestroyObject();

DECLSPEC_IMPORT VOID NTAPI XuiDynamicCast();

DECLSPEC_IMPORT VOID NTAPI XuiElementAddChild();

DECLSPEC_IMPORT VOID NTAPI XuiElementFindNamedFrame();

DECLSPEC_IMPORT VOID NTAPI XuiElementGetChildById();

DECLSPEC_IMPORT VOID NTAPI XuiElementGetFirstChild();

DECLSPEC_IMPORT VOID NTAPI XuiElementGetFocus();

DECLSPEC_IMPORT VOID NTAPI XuiElementGetFocusUser();

DECLSPEC_IMPORT VOID NTAPI XuiElementGetId();

DECLSPEC_IMPORT VOID NTAPI XuiElementGetLastChild();

DECLSPEC_IMPORT VOID NTAPI XuiElementGetNext();

DECLSPEC_IMPORT VOID NTAPI XuiElementGetParent();

DECLSPEC_IMPORT VOID NTAPI XuiElementGetUserFocus();

DECLSPEC_IMPORT VOID NTAPI XuiElementInitFocus();

DECLSPEC_IMPORT VOID NTAPI XuiElementInitUserFocus();

DECLSPEC_IMPORT VOID NTAPI XuiElementPlayTimeline();

DECLSPEC_IMPORT VOID NTAPI XuiElementSetBounds();

DECLSPEC_IMPORT VOID NTAPI XuiElementSetFocus();

DECLSPEC_IMPORT VOID NTAPI XuiElementSetUserFocus();

DECLSPEC_IMPORT VOID NTAPI XuiElementTreeGetFocus();

DECLSPEC_IMPORT VOID NTAPI XuiFindClass();

DECLSPEC_IMPORT VOID NTAPI XuiFreeStringTable();

DECLSPEC_IMPORT VOID NTAPI XuiGetBaseObject();

DECLSPEC_IMPORT VOID NTAPI XuiGetClass();

DECLSPEC_IMPORT VOID NTAPI XuiGetObjectClass();

DECLSPEC_IMPORT VOID NTAPI XuiGetOuter();

DECLSPEC_IMPORT VOID NTAPI XuiInit();

DECLSPEC_IMPORT VOID NTAPI XuiLoadFromBinary();

DECLSPEC_IMPORT VOID NTAPI XuiLoadStringTableFromFile();

DECLSPEC_IMPORT VOID NTAPI XuiVisualGetBasePath();

DECLSPEC_IMPORT VOID NTAPI XuiLookupStringTable();

DECLSPEC_IMPORT VOID NTAPI XuiNavButtonGetPressPath();

DECLSPEC_IMPORT VOID NTAPI XuiObjectFromHandle();

DECLSPEC_IMPORT VOID NTAPI XuiObjectGetProperty();

DECLSPEC_IMPORT VOID NTAPI XuiObjectGetPropertyId();

DECLSPEC_IMPORT VOID NTAPI XuiProcessInput();

DECLSPEC_IMPORT VOID NTAPI XuiRegisterClass();

DECLSPEC_IMPORT VOID NTAPI XuiRenderBegin();

DECLSPEC_IMPORT VOID NTAPI XuiRenderCreateDC();

DECLSPEC_IMPORT VOID NTAPI XuiRenderDCDeviceChanged();

DECLSPEC_IMPORT VOID NTAPI XuiRenderDestroyDC();

DECLSPEC_IMPORT VOID NTAPI XuiRenderEnd();

DECLSPEC_IMPORT VOID NTAPI XuiRenderGetBackBufferSize();

DECLSPEC_IMPORT VOID NTAPI XuiRenderInit();

DECLSPEC_IMPORT VOID NTAPI XuiRenderInitShared();

DECLSPEC_IMPORT VOID NTAPI XuiRenderPresent();

DECLSPEC_IMPORT VOID NTAPI XuiRenderSetViewTransform();

DECLSPEC_IMPORT VOID NTAPI XuiRenderUninit();

DECLSPEC_IMPORT VOID NTAPI XamShowNuiGuideUI();

DECLSPEC_IMPORT VOID NTAPI XuiSceneCreate();

DECLSPEC_IMPORT VOID NTAPI XuiSceneNavigateBack();

DECLSPEC_IMPORT VOID NTAPI XuiSceneNavigateFirst();

DECLSPEC_IMPORT VOID NTAPI XuiSceneNavigateForward();

DECLSPEC_IMPORT VOID NTAPI XuiScenePlayBackFromTransition();

DECLSPEC_IMPORT VOID NTAPI XuiScenePlayBackToTransition();

DECLSPEC_IMPORT VOID NTAPI XuiScenePlayFromTransition();

DECLSPEC_IMPORT VOID NTAPI XuiScenePlayToTransition();

DECLSPEC_IMPORT VOID NTAPI XuiSendMessage();

DECLSPEC_IMPORT VOID NTAPI XuiSetLocale();

DECLSPEC_IMPORT VOID NTAPI XuiUninit();

DECLSPEC_IMPORT VOID NTAPI XuiUnregisterClass();

DECLSPEC_IMPORT VOID NTAPI XuiTextElementSetText();

DECLSPEC_IMPORT VOID NTAPI XuiSetTimer();

DECLSPEC_IMPORT VOID NTAPI XuiTimersRun();

DECLSPEC_IMPORT VOID NTAPI XuiTextElementGetText();

DECLSPEC_IMPORT VOID NTAPI XuiVisualSetBasePath();

DECLSPEC_IMPORT VOID NTAPI XuiHandleIsValid();

DECLSPEC_IMPORT VOID NTAPI XuiAlloc();

DECLSPEC_IMPORT VOID NTAPI XuiFree();

DECLSPEC_IMPORT VOID NTAPI XuiDefault_True();

DECLSPEC_IMPORT VOID NTAPI XuiDefault_EmptyString();

DECLSPEC_IMPORT VOID NTAPI XuiDefault_IntegerZero();

DECLSPEC_IMPORT VOID NTAPI XuiCopyString();

DECLSPEC_IMPORT VOID NTAPI XuiRealloc();

DECLSPEC_IMPORT VOID NTAPI XuiControlPlayOptionalVisual();

DECLSPEC_IMPORT VOID NTAPI XuiKillTimer();

DECLSPEC_IMPORT VOID NTAPI XuiElementEnableInput();

DECLSPEC_IMPORT VOID NTAPI XuiElementInputEnabled();

DECLSPEC_IMPORT VOID NTAPI XuiIsInstanceOf();

DECLSPEC_IMPORT VOID NTAPI XuiResourceComposeLocator();

DECLSPEC_IMPORT VOID NTAPI XuiResourceLocatorIsAbsolute();

DECLSPEC_IMPORT VOID NTAPI XuiBroadcastMessage();

DECLSPEC_IMPORT VOID NTAPI XuiElementDisallowRecursiveTimelineControl();

DECLSPEC_IMPORT VOID NTAPI XUIElementPropVal_Construct();

DECLSPEC_IMPORT VOID NTAPI XUIElementPropVal_Destruct();

DECLSPEC_IMPORT VOID NTAPI XUIElementPropVal_SetString();

DECLSPEC_IMPORT VOID NTAPI XuiObjectSetProperty();

DECLSPEC_IMPORT VOID NTAPI XuiElementGetOpacity();

DECLSPEC_IMPORT VOID NTAPI XuiElementSetOpacity();

DECLSPEC_IMPORT VOID NTAPI XuiEditSetTextLimit();

DECLSPEC_IMPORT VOID NTAPI XuiEditGetTextLimit();

DECLSPEC_IMPORT VOID NTAPI XuiSliderSetValue();

DECLSPEC_IMPORT VOID NTAPI XuiSliderGetValue();

DECLSPEC_IMPORT VOID NTAPI XuiSliderSetRange();

DECLSPEC_IMPORT VOID NTAPI XuiElementUnlink();

DECLSPEC_IMPORT VOID NTAPI XuiElementInsertChild();

DECLSPEC_IMPORT VOID NTAPI XuiSceneNavigateBackToFirst();

DECLSPEC_IMPORT VOID NTAPI XuiProgressBarSetRange();

DECLSPEC_IMPORT VOID NTAPI XuiProgressBarSetValue();

DECLSPEC_IMPORT VOID NTAPI XuiProgressBarGetValue();

DECLSPEC_IMPORT VOID NTAPI XuiControlAttachVisual();

DECLSPEC_IMPORT VOID NTAPI XuiCreateTextureBrush();

DECLSPEC_IMPORT VOID NTAPI XuiDestroyBrush();

DECLSPEC_IMPORT VOID NTAPI XUIElementPropVal_SetColorFromUint();

DECLSPEC_IMPORT VOID NTAPI XuiFigureSetFill();

DECLSPEC_IMPORT VOID NTAPI XuiSliderGetRange();

DECLSPEC_IMPORT VOID NTAPI XuiFigureSetTexture();

DECLSPEC_IMPORT VOID NTAPI XuiControlGetItemAssociation();

DECLSPEC_IMPORT VOID NTAPI XuiResourceLoadAll();

DECLSPEC_IMPORT VOID NTAPI XuiImageElementSetImagePath();

DECLSPEC_IMPORT VOID NTAPI XuiImageElementGetImagePath();

DECLSPEC_IMPORT VOID NTAPI XuiControlGetVisual();

DECLSPEC_IMPORT VOID NTAPI XuiControlGetNavigation();

DECLSPEC_IMPORT VOID NTAPI XuiLookupStringTableByIndex();

DECLSPEC_IMPORT VOID NTAPI XUIElementPropVal_SetBool();

DECLSPEC_IMPORT VOID NTAPI XuiElementHasFocus();

DECLSPEC_IMPORT VOID NTAPI XUIElementPropVal_SetUint();

DECLSPEC_IMPORT VOID NTAPI XUIElementPropVal_Clear();

DECLSPEC_IMPORT VOID NTAPI XuiEditSetTextFormatInfo();

DECLSPEC_IMPORT VOID NTAPI XuiCreateSolidBrush();

DECLSPEC_IMPORT VOID NTAPI XuiSceneInterruptTransitions();

DECLSPEC_IMPORT VOID NTAPI XuiResourceOpen();

DECLSPEC_IMPORT VOID NTAPI XuiResourceRead();

DECLSPEC_IMPORT VOID NTAPI XuiResourceClose();

DECLSPEC_IMPORT VOID NTAPI XuiVisualCreateInstance();

DECLSPEC_IMPORT VOID NTAPI XuiElementGetTimeline();

DECLSPEC_IMPORT VOID NTAPI GetCodecVersion();

/* Linker spelling at ordinal 932: GetCodecVersion@CCalMediaInfo; C spelling: GetCodecVersion. */

DECLSPEC_IMPORT VOID NTAPI XuiElementIsDescendant();

DECLSPEC_IMPORT VOID NTAPI XuiSetMessageFilter();

DECLSPEC_IMPORT VOID NTAPI XuiAttachTextureBrush();

DECLSPEC_IMPORT VOID NTAPI XuiElementBeginRender();

DECLSPEC_IMPORT VOID NTAPI XuiElementEndRender();

DECLSPEC_IMPORT VOID NTAPI XuiDrawShape();

DECLSPEC_IMPORT VOID NTAPI XuiSelectBrushEx();

DECLSPEC_IMPORT VOID NTAPI XuiFigureGetShape();

DECLSPEC_IMPORT VOID NTAPI XuiFillRect();

DECLSPEC_IMPORT VOID NTAPI XuiVec2TransformCoord();

DECLSPEC_IMPORT VOID NTAPI Xuivec2TransformCoord();

DECLSPEC_IMPORT VOID NTAPI XuiMatrixMultiply();

DECLSPEC_IMPORT VOID NTAPI XuiElementGetXForm();

DECLSPEC_IMPORT VOID NTAPI XuiElementSetPosition();

DECLSPEC_IMPORT VOID NTAPI XuiSelectBrush();

DECLSPEC_IMPORT VOID NTAPI XuiElementRenderChildren();

DECLSPEC_IMPORT VOID NTAPI XuiFreeUnusedTextures();

DECLSPEC_IMPORT VOID NTAPI XuiListEnableItemOverride();

DECLSPEC_IMPORT VOID NTAPI XuiListGetDefaultItemSize();

DECLSPEC_IMPORT VOID NTAPI XuiResourceSeek();

DECLSPEC_IMPORT VOID NTAPI XuiElementDiscardResources();

DECLSPEC_IMPORT VOID NTAPI XuiTabSceneGoto();

DECLSPEC_IMPORT VOID NTAPI XuiTabSceneGetCurrentTab();

DECLSPEC_IMPORT VOID NTAPI XamShowWhatsOnUI();

DECLSPEC_IMPORT
ULONG
NTAPI
XamShowEditProfileUI(
    ULONG user_index
    );

DECLSPEC_IMPORT VOID NTAPI XamShowStorePickerUI();

DECLSPEC_IMPORT VOID NTAPI XamShowTermsOfUseUI();

DECLSPEC_IMPORT VOID NTAPI XamShowJoinPartyUI();

DECLSPEC_IMPORT VOID NTAPI XamShowWordRegisterUI();

DECLSPEC_IMPORT VOID NTAPI XamOverrideHudOpenType();

DECLSPEC_IMPORT VOID NTAPI XamShowAchievementsUIEx();

DECLSPEC_IMPORT
ULONG
NTAPI
XamUserGetUserTenure(
    ULONG user_index,
    ULONG *tenure_level_ptr,
    ULONG *milestone_ptr,
    ULONGLONG *milestone_date_ptr,
    ULONG overlap_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamUserGetSubscriptionType(
    ULONG user_index,
    ULONG *subscription_ptr,
    ULONG *r5,
    ULONG overlapped_ptr
    );

DECLSPEC_IMPORT VOID NTAPI XamShowGameVoiceChannelUI();

DECLSPEC_IMPORT VOID NTAPI XamShowAvatarAwardsUI();

DECLSPEC_IMPORT VOID NTAPI XamShowAvatarAwardGamesUI();

DECLSPEC_IMPORT VOID NTAPI XamShowVideoRichPresenceUI();

DECLSPEC_IMPORT VOID NTAPI XamHudGetUserIndex();

DECLSPEC_IMPORT ULONG NTAPI XGetAudioFlags(VOID);

DECLSPEC_IMPORT ULONG NTAPI XGetAVPack(VOID);

DECLSPEC_IMPORT ULONG NTAPI XGetGameRegion(VOID);

DECLSPEC_IMPORT ULONG NTAPI XGetLanguage(VOID);

DECLSPEC_IMPORT VOID NTAPI XapipGetLocale();

DECLSPEC_IMPORT VOID NTAPI XGetVideoFlags();

DECLSPEC_IMPORT VOID NTAPI XGetVideoStandard();

DECLSPEC_IMPORT
VOID
NTAPI
XGetVideoMode(
    X_VIDEO_MODE *video_mode
    );

DECLSPEC_IMPORT ULONG NTAPI XamGetLanguage(VOID);

DECLSPEC_IMPORT VOID NTAPI XUITimeline_Run();

DECLSPEC_IMPORT VOID NTAPI XamSetAutomation();

DECLSPEC_IMPORT VOID NTAPI XAutomationpBindController();

DECLSPEC_IMPORT
ULONG
NTAPI
XAutomationpUnbindController(
    ULONG user_index
    );

DECLSPEC_IMPORT VOID NTAPI XAutomationpInputXenonButton();

DECLSPEC_IMPORT VOID NTAPI XAutomationpInputPress();

DECLSPEC_IMPORT VOID NTAPI XAutomationpInputSetState();

DECLSPEC_IMPORT VOID NTAPI XamEnableOverdraw();

EXTERN_C DECLSPEC_IMPORT struct _NXEDK_OPAQUE_EXPORT g_XuiAutomation;

DECLSPEC_IMPORT VOID NTAPI XamVoiceGetMicArrayAudio();

DECLSPEC_IMPORT VOID NTAPI XampSystemInput();

DECLSPEC_IMPORT VOID NTAPI XamInputControl();

DECLSPEC_IMPORT VOID NTAPI XuiElementGetPosition();

DECLSPEC_IMPORT VOID NTAPI XamIsMessageBoxActive();

DECLSPEC_IMPORT VOID NTAPI XamIsBackgroundSceneInTransition();

DECLSPEC_IMPORT VOID NTAPI XuiElementTreeHasFocus();

DECLSPEC_IMPORT VOID NTAPI XuiFigureClose();

DECLSPEC_IMPORT VOID NTAPI GamerCardStartup();

DECLSPEC_IMPORT VOID NTAPI GamerCardCleanup();

DECLSPEC_IMPORT VOID NTAPI GamerCardRegisterControls();

DECLSPEC_IMPORT VOID NTAPI GamerCardUnregisterControls();

DECLSPEC_IMPORT VOID NTAPI RtlFindFirstFile();

DECLSPEC_IMPORT VOID NTAPI RtlFindNextFile();

DECLSPEC_IMPORT VOID NTAPI RtlGetModuleFileName();

DECLSPEC_IMPORT VOID NTAPI RtlOutputDebugString();

DECLSPEC_IMPORT VOID NTAPI RtlRemoveDirectory();

DECLSPEC_IMPORT
ULONG
NTAPI
RtlSleep(
    ULONG dwMilliseconds,
    ULONG bAlertable
    );

DECLSPEC_IMPORT ULONG NTAPI RtlGetLastError(VOID);

DECLSPEC_IMPORT VOID NTAPI RtlSetLastError();

DECLSPEC_IMPORT
ULONG
NTAPI
RtlSetLastNTError(
    ULONG error_code
    );

DECLSPEC_IMPORT VOID NTAPI RtlDebugPrint();

DECLSPEC_IMPORT VOID NTAPI RtlDebugError();

DECLSPEC_IMPORT VOID NTAPI XDebugWarning();

DECLSPEC_IMPORT VOID NTAPI RtlDebugTrace();

DECLSPEC_IMPORT VOID NTAPI RtlDebugEntry();

DECLSPEC_IMPORT VOID NTAPI RtlDebugExit();

DECLSPEC_IMPORT VOID NTAPI RtlGetAttributesOnHeapAlloc();

DECLSPEC_IMPORT VOID NTAPI RtlSetAttributesOnHeapAlloc();

DECLSPEC_IMPORT VOID NTAPI XuiFigureSetShape();

DECLSPEC_IMPORT VOID NTAPI RtlCreateHeap();

DECLSPEC_IMPORT VOID NTAPI RtlDestroyHeap();

DECLSPEC_IMPORT VOID NTAPI RtlAllocateHeap();

DECLSPEC_IMPORT VOID NTAPI RtlAllocateHeapSlowly();

DECLSPEC_IMPORT VOID NTAPI RtlReAllocateHeap();

DECLSPEC_IMPORT VOID NTAPI RtlFreeHeap();

DECLSPEC_IMPORT VOID NTAPI RtlFreeHeapSlowly();

DECLSPEC_IMPORT VOID NTAPI RtlSizeHeap();

DECLSPEC_IMPORT VOID NTAPI RtlZeroHeap();

DECLSPEC_IMPORT VOID NTAPI RtlDebugWalkHeap();

DECLSPEC_IMPORT VOID NTAPI RtlWalkHeap();

DECLSPEC_IMPORT VOID NTAPI RtlLockHeap();

DECLSPEC_IMPORT VOID NTAPI RtlUnlockHeap();

DECLSPEC_IMPORT VOID NTAPI RtlValidateHeap();

DECLSPEC_IMPORT VOID NTAPI RtlDebugCompactHeap();

DECLSPEC_IMPORT VOID NTAPI RtlCompactHeap();

DECLSPEC_IMPORT VOID NTAPI XamAppSetTestOption();

DECLSPEC_IMPORT VOID NTAPI XamAppReportError();

DECLSPEC_IMPORT ULONG NTAPI XamIsNuiUIActive(VOID);

DECLSPEC_IMPORT VOID NTAPI XamVerifyPasscode();

DECLSPEC_IMPORT VOID NTAPI OutputDebugStringA();

DECLSPEC_IMPORT VOID NTAPI DebugBreak();

DECLSPEC_IMPORT ULONG NTAPI GetCurrentThreadId(VOID);

DECLSPEC_IMPORT VOID NTAPI XDebugError();

DECLSPEC_IMPORT VOID NTAPI XDebugWarning_();

DECLSPEC_IMPORT VOID NTAPI RtlDebugSetLevel();

DECLSPEC_IMPORT
ULONG
NTAPI
CloseHandle(
    ULONG hObject
    );

DECLSPEC_IMPORT ULONG NTAPI GetTickCount(VOID);

DECLSPEC_IMPORT ULONG NTAPI GetLastError(VOID);

DECLSPEC_IMPORT
ULONG
NTAPI
SetFilePointer(
    HANDLE file,
    LONG distance_to_move,
    LONG *distance_to_move_high,
    ULONG move_method
    );

DECLSPEC_IMPORT VOID NTAPI SetFilePointerEx();

DECLSPEC_IMPORT VOID NTAPI SetLastError();

DECLSPEC_IMPORT VOID NTAPI MultiByteToWideChar();

DECLSPEC_IMPORT VOID NTAPI WideCharToMultiByte();

DECLSPEC_IMPORT
BOOLEAN
NTAPI
ReadFile(
    HANDLE file,
    VOID *buffer,
    ULONG bytes_to_read,
    ULONG *bytes_read,
    XOVERLAPPED *overlapped
    );

DECLSPEC_IMPORT VOID NTAPI FlushFileBuffers();

DECLSPEC_IMPORT
BOOLEAN
NTAPI
WriteFile(
    HANDLE file,
    VOID *buffer,
    ULONG bytes_to_write,
    ULONG *bytes_written,
    XOVERLAPPED *overlapped
    );

DECLSPEC_IMPORT VOID NTAPI OutputDebugStringW();

DECLSPEC_IMPORT VOID NTAPI SetEvent();

DECLSPEC_IMPORT
ULONGLONG
NTAPI
XapiFormatTimeOut(
    ULONGLONG *result,
    ULONG dwMilliseconds
    );

DECLSPEC_IMPORT VOID NTAPI CreateMutexA();

DECLSPEC_IMPORT VOID NTAPI OpenMutexA();

DECLSPEC_IMPORT VOID NTAPI ReleaseMutex();

DECLSPEC_IMPORT
ULONG
NTAPI
WaitForSingleObject(
    ULONG hHandle,
    ULONG dwMilliseconds
    );

DECLSPEC_IMPORT
ULONG
NTAPI
WaitForSingleObjectEx(
    ULONG hHandle,
    ULONG dwMilliseconds,
    ULONG bAlertable
    );

DECLSPEC_IMPORT VOID NTAPI GetFileSize();

DECLSPEC_IMPORT VOID NTAPI GetFileSizeEx();

DECLSPEC_IMPORT VOID NTAPI XapiDirectoryInformationToFindData();

DECLSPEC_IMPORT VOID NTAPI XapiFormatObjectAttributes();

DECLSPEC_IMPORT VOID NTAPI ResetEvent();

DECLSPEC_IMPORT VOID NTAPI wsprintfA();

DECLSPEC_IMPORT VOID NTAPI wsprintfW();

DECLSPEC_IMPORT VOID NTAPI GetOverlappedResult();

DECLSPEC_IMPORT VOID NTAPI QueryPerformanceCounter();

DECLSPEC_IMPORT
ULONG
NTAPI
QueryPerformanceFrequency(
    ULONGLONG *query
    );

DECLSPEC_IMPORT VOID NTAPI LocalAlloc();

DECLSPEC_IMPORT VOID NTAPI LocalFree();

DECLSPEC_IMPORT VOID NTAPI RaiseException();

DECLSPEC_IMPORT VOID NTAPI RtlUniform();

DECLSPEC_IMPORT
ULONG
NTAPI
RtlRandom(
    ULONG *seed_out
    );

DECLSPEC_IMPORT
VOID
NTAPI
Sleep(
    ULONG dwMilliseconds
    );

DECLSPEC_IMPORT
ULONG
NTAPI
SleepEx(
    ULONG dwMilliseconds,
    ULONG bAlertable
    );

DECLSPEC_IMPORT VOID NTAPI XMemSet();

DECLSPEC_IMPORT VOID NTAPI XRegisterThreadNotifyRoutine();

DECLSPEC_IMPORT VOID NTAPI XGetOverlappedExtendedError();

DECLSPEC_IMPORT VOID NTAPI XGetOverlappedResult();

DECLSPEC_IMPORT
ULONG
NTAPI
CreateThread(
    ULONG *lpThreadAttributes,
    ULONG dwStackSize,
    VOID *lpStartAddress,
    VOID *lpParameter,
    ULONG dwCreationFlags,
    ULONG *lpThreadId
    );

DECLSPEC_IMPORT
ULONG
NTAPI
ResumeThread(
    ULONG hThread
    );

DECLSPEC_IMPORT
VOID
NTAPI
ExitThread(
    ULONG exit_code
    );

DECLSPEC_IMPORT VOID NTAPI GetTimeZoneInformation();

DECLSPEC_IMPORT VOID NTAPI GetSystemTimeAsFileTime();

DECLSPEC_IMPORT VOID NTAPI SystemTimeToFileTime();

DECLSPEC_IMPORT VOID NTAPI FileTimeToSystemTime();

DECLSPEC_IMPORT VOID NTAPI GetSystemTime();

DECLSPEC_IMPORT VOID NTAPI GetLocalTime();

DECLSPEC_IMPORT VOID NTAPI CreateDirectoryA();

DECLSPEC_IMPORT VOID NTAPI CreateEventA();

DECLSPEC_IMPORT
HANDLE
NTAPI
CreateFileA(
    CHAR *filename,
    ULONG desired_access,
    ULONG share_mode,
    SECURITY_ATTRIBUTES *security_attributes,
    ULONG creation_disposition,
    ULONG flags_and_attributes,
    HANDLE template_file
    );

DECLSPEC_IMPORT
BOOLEAN
NTAPI
DeleteFileA(
    CHAR *filename
    );

DECLSPEC_IMPORT VOID NTAPI FindFirstFileA();

DECLSPEC_IMPORT VOID NTAPI FindNextFileA();

DECLSPEC_IMPORT VOID NTAPI GetFileAttributesA();

DECLSPEC_IMPORT VOID NTAPI XamLoaderGetCurrentTitleD3DVersion();

DECLSPEC_IMPORT VOID NTAPI GetFileAttributesExA();

DECLSPEC_IMPORT
ULONG
NTAPI
GetModuleHandleA(
    CONST CHAR *module_name
    );

DECLSPEC_IMPORT VOID NTAPI GetDiskFreeSpaceExA();

DECLSPEC_IMPORT VOID NTAPI CopyFileA();

DECLSPEC_IMPORT VOID NTAPI SetEndOfFile();

DECLSPEC_IMPORT VOID NTAPI XamFamilyAddParentalExemptionToList();

DECLSPEC_IMPORT VOID NTAPI XamFamilyIsParentalValidationRequired();

DECLSPEC_IMPORT VOID NTAPI PIXBeginCapture();

DECLSPEC_IMPORT VOID NTAPI PIXEndCapture();

DECLSPEC_IMPORT VOID NTAPI PIXAddCounter();

DECLSPEC_IMPORT VOID NTAPI PIXGetGPUSlot();

DECLSPEC_IMPORT VOID NTAPI SetWaitableTimer();

DECLSPEC_IMPORT VOID NTAPI CancelWaitableTimer();

DECLSPEC_IMPORT VOID NTAPI CreateWaitableTimerA();

DECLSPEC_IMPORT VOID NTAPI DuplicateHandle();

DECLSPEC_IMPORT
ULONG
NTAPI
XapipCreateThread(
    ULONG *thread_attributes,
    ULONG stack_size,
    VOID *start_address,
    VOID *parameter,
    ULONG creation_flags,
    ULONG thread_processor,
    ULONG *thread_id
    );

DECLSPEC_IMPORT VOID NTAPI lstrcpyA();

DECLSPEC_IMPORT VOID NTAPI lstrcpyW();

DECLSPEC_IMPORT VOID NTAPI lstrcpynA();

DECLSPEC_IMPORT VOID NTAPI lstrcpynW();

DECLSPEC_IMPORT VOID NTAPI lstrcatA();

DECLSPEC_IMPORT VOID NTAPI lstrcatW();

DECLSPEC_IMPORT VOID NTAPI lstrlenA();

DECLSPEC_IMPORT
ULONG
NTAPI
lstrlenW(
    CONST USHORT *string
    );

DECLSPEC_IMPORT VOID NTAPI IsBadReadPtr();

DECLSPEC_IMPORT VOID NTAPI IsBadWritePtr();

DECLSPEC_IMPORT VOID NTAPI FileTimeToLocalFileTime();

DECLSPEC_IMPORT VOID NTAPI XMemCpy();

DECLSPEC_IMPORT VOID NTAPI XMemCpyStreaming();

DECLSPEC_IMPORT VOID NTAPI XamHudSetUserIndex();

DECLSPEC_IMPORT
ULONG
NTAPI
XamShowNuiTroubleshooterUI(
    ULONG user_index,
    ULONG tracking_id,
    ULONG flags
    );

DECLSPEC_IMPORT VOID NTAPI XamTestShowNuiTroubleshooterUI();

DECLSPEC_IMPORT VOID NTAPI XamShowPasscodeVerifyUIEx();

DECLSPEC_IMPORT VOID NTAPI XamShowNuiAchievementsUI();

DECLSPEC_IMPORT VOID NTAPI XamShowNuiCommunitySessionsUI();

DECLSPEC_IMPORT VOID NTAPI XamShowNuiDeviceSelectorUI();

DECLSPEC_IMPORT VOID NTAPI XamShowNuiDirtyDiscErrorUI();

DECLSPEC_IMPORT VOID NTAPI XamShowNuiFriendsUI();

DECLSPEC_IMPORT VOID NTAPI XamShowNuiGameInviteUI();

DECLSPEC_IMPORT VOID NTAPI XamShowNuiGamerCardUIForXUID();

DECLSPEC_IMPORT VOID NTAPI XamShowNuiMarketplaceDownloadItemsUI();

DECLSPEC_IMPORT VOID NTAPI XamShowNuiMarketplaceUI();

DECLSPEC_IMPORT VOID NTAPI XamShowNuiMessageBoxUI();

DECLSPEC_IMPORT VOID NTAPI XamShowNuiPartyUI();

DECLSPEC_IMPORT VOID NTAPI XamShowNuiFriendRequestUI();

DECLSPEC_IMPORT
ULONG
NTAPI
XamShowNuiSigninUI(
    ULONG unk,
    ULONG user_index,
    ULONG flags
    );

DECLSPEC_IMPORT VOID NTAPI XamShowNuiControllerRequiredUI();

DECLSPEC_IMPORT VOID NTAPI XamShowNuiGamesUI();

DECLSPEC_IMPORT VOID NTAPI XamShowNuiHardwareRequiredUI();

DECLSPEC_IMPORT VOID NTAPI XamCacheStoreFileByString();

DECLSPEC_IMPORT VOID NTAPI XamCacheFetchFileByString();

DECLSPEC_IMPORT VOID NTAPI XamCacheDeleteFileByString();

DECLSPEC_IMPORT VOID NTAPI XamGetCachedTitleNameEx();

DECLSPEC_IMPORT VOID NTAPI XamXlfsInitializeUploadQueue();

DECLSPEC_IMPORT VOID NTAPI XamXlfsUninitializeUploadQueue();

DECLSPEC_IMPORT VOID NTAPI XamXlfsMountUploadQueueInstance();

DECLSPEC_IMPORT VOID NTAPI XamXlfsUnmountUploadQueueInstance();

DECLSPEC_IMPORT VOID NTAPI XamVoiceRecordUserPrivileges();

DECLSPEC_IMPORT VOID NTAPI XamXlfsInitializeUploadQueueWithTestHooks();

DECLSPEC_IMPORT VOID NTAPI XamXlfsNotifyContentDeletion();

DECLSPEC_IMPORT VOID NTAPI XMemAlloc();

DECLSPEC_IMPORT VOID NTAPI XMemFree();

DECLSPEC_IMPORT VOID NTAPI XMemSize();

DECLSPEC_IMPORT VOID NTAPI XamVoiceSetMicArrayIdleUsers();

DECLSPEC_IMPORT VOID NTAPI XamVoiceMuteMicArray();

DECLSPEC_IMPORT VOID NTAPI XamVoiceGetMicArrayUnderrunStatus();

DECLSPEC_IMPORT VOID NTAPI XuiSceneEnableTransitionDependency();

DECLSPEC_IMPORT VOID NTAPI XamVoiceGetMicArrayAudioEx();

DECLSPEC_IMPORT VOID NTAPI XamVoiceDisableMicArray();

DECLSPEC_IMPORT VOID NTAPI XamShowLeaveFamilyUI();

DECLSPEC_IMPORT VOID NTAPI XamUserGetDeviceId();

DECLSPEC_IMPORT VOID NTAPI XamUpdateEtxLogUpdateTaskStart();

DECLSPEC_IMPORT VOID NTAPI XamUpdateEtxLogUpdateTaskSuccess();

DECLSPEC_IMPORT VOID NTAPI XamUpdateEtxLogUpdateTaskFailure();

DECLSPEC_IMPORT VOID NTAPI XamEtxFlushLogs();

DECLSPEC_IMPORT ULONG NTAPI XamVoiceIsActiveProcess(VOID);

DECLSPEC_IMPORT VOID NTAPI XamInactivityGetInactivityInterruptTime();

DECLSPEC_IMPORT VOID NTAPI XamInactivitySetInactivityInterruptTime();

DECLSPEC_IMPORT VOID NTAPI XamInactivityGetLastActivityTime();

DECLSPEC_IMPORT VOID NTAPI XamInactivitySetDetectionTaskPeriod();

DECLSPEC_IMPORT VOID NTAPI XamInactivityEnablePowerDown();

DECLSPEC_IMPORT VOID NTAPI XamUpdateGetChainMarker();

DECLSPEC_IMPORT ULONG NTAPI XGetVideoCapabilities(VOID);

DECLSPEC_IMPORT VOID NTAPI XMsgProcessRequest();

DECLSPEC_IMPORT VOID NTAPI XGetDisplaySize();

DECLSPEC_IMPORT
LONG
NTAPI
XamInputNonControllerGetRaw(
    USHORT *state_ptr,
    ULONG *buffer_length_ptr,
    ULONG *buffer_ptr
    );

DECLSPEC_IMPORT
LONG
NTAPI
XamInputNonControllerSetRaw(
    ULONG buffer_length,
    ULONG *buffer_ptr
    );

DECLSPEC_IMPORT VOID NTAPI XamVoiceSetMicArrayBeamAngle();

DECLSPEC_IMPORT VOID NTAPI XamUserGetAge();

DECLSPEC_IMPORT VOID NTAPI XamUserGetAgeGroup();

DECLSPEC_IMPORT VOID NTAPI XamVoiceGetMicArrayFilenameDesc();

DECLSPEC_IMPORT VOID NTAPI XamLoaderGetState();

DECLSPEC_IMPORT VOID NTAPI XamTaskQueryProperty();

DECLSPEC_IMPORT ULONG NTAPI XamGetLocale(VOID);

DECLSPEC_IMPORT VOID NTAPI XamQueryTimeZoneInformation();

DECLSPEC_IMPORT VOID NTAPI XamSetTimeZoneInformation();

DECLSPEC_IMPORT VOID NTAPI XamLaunchURI();

DECLSPEC_IMPORT VOID NTAPI XamShowNuiMessagesUI();

DECLSPEC_IMPORT VOID NTAPI XMPRegisterCodec();

DECLSPEC_IMPORT VOID NTAPI XamNavigateBack();

DECLSPEC_IMPORT VOID NTAPI XamPushBackURI();

DECLSPEC_IMPORT VOID NTAPI XamUserOverrideDeviceBindings();

DECLSPEC_IMPORT VOID NTAPI XamUserOverrideBindingCallbacks();

DECLSPEC_IMPORT VOID NTAPI XamUserOverrideUserInfo();

DECLSPEC_IMPORT
ULONG
NTAPI
XamUserContentRestrictionGetFlags(
    ULONG user_index,
    ULONG *out_flags
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamUserContentRestrictionGetRating(
    ULONG user_index,
    ULONG unk1,
    ULONG *out_unk2,
    ULONG *out_unk3
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamUserContentRestrictionCheckAccess(
    ULONG user_index,
    ULONG unk1,
    ULONG unk2,
    ULONG unk3,
    ULONG unk4,
    ULONG *out_unk5,
    ULONG overlapped_ptr
    );

DECLSPEC_IMPORT VOID NTAPI XamShowFitnessBodyProfileUI();

DECLSPEC_IMPORT VOID NTAPI XamFitnessAddBodyProfileRecord();

DECLSPEC_IMPORT VOID NTAPI XamFamilyGetMembers();

DECLSPEC_IMPORT VOID NTAPI XampXAuthStartup();

DECLSPEC_IMPORT VOID NTAPI XampXAuthShutdown();

DECLSPEC_IMPORT VOID NTAPI XamGetToken();

DECLSPEC_IMPORT VOID NTAPI XamFreeToken();

DECLSPEC_IMPORT VOID NTAPI XamGetAppliesTo();

DECLSPEC_IMPORT VOID NTAPI XamFitnessClearBodyProfileRecords();

DECLSPEC_IMPORT VOID NTAPI XampKioskGetInfo();

DECLSPEC_IMPORT VOID NTAPI XamFitnessGetCurrentBodyProfileRecord();

DECLSPEC_IMPORT VOID NTAPI XamFitnessGetAllBodyProfileRecords();

DECLSPEC_IMPORT VOID NTAPI XamFitnessGetAllTitleSummaries();

DECLSPEC_IMPORT VOID NTAPI XamFitnessGetOverallSummary();

DECLSPEC_IMPORT VOID NTAPI XamFitnessAddFitnessEvent();

DECLSPEC_IMPORT VOID NTAPI XamLrcGetInput();

DECLSPEC_IMPORT VOID NTAPI XamLrcGetInputWithSeek();

DECLSPEC_IMPORT VOID NTAPI XamLrcSetMediaState();

DECLSPEC_IMPORT VOID NTAPI XamPixSetDirtyCounters();

DECLSPEC_IMPORT VOID NTAPI XamFitnessCreateFitnessEventEnumerator();

DECLSPEC_IMPORT VOID NTAPI XamFitnessInitialize();

DECLSPEC_IMPORT VOID NTAPI XamRequestToken();

DECLSPEC_IMPORT VOID NTAPI XamResolveURI();

DECLSPEC_IMPORT VOID NTAPI XamContentGetOnlineCreator();

DECLSPEC_IMPORT VOID NTAPI XamShowBrandedKeyboardUI();

DECLSPEC_IMPORT VOID NTAPI XamBackgroundDownloadNetworkStorageEnable();

DECLSPEC_IMPORT VOID NTAPI XamBackgroundDownloadNetworkStorageIsEnabled();

DECLSPEC_IMPORT VOID NTAPI XamShowNuiJoinSessionInProgressUI();

DECLSPEC_IMPORT VOID NTAPI XamBase64Decode();

DECLSPEC_IMPORT VOID NTAPI XamCertDecode();

DECLSPEC_IMPORT VOID NTAPI XamCertDecodeRsaPublicKey();

DECLSPEC_IMPORT VOID NTAPI XamCertValidateStruct();

DECLSPEC_IMPORT VOID NTAPI XamFitnessConvertByteMetToFloatMet();

DECLSPEC_IMPORT VOID NTAPI XamXgiBlobTrackerSetMockInfo();

DECLSPEC_IMPORT VOID NTAPI XamFitnessMsgTimeToSystemTime();

DECLSPEC_IMPORT VOID NTAPI XamFitnessSystemTimeToMsgTime();

DECLSPEC_IMPORT VOID NTAPI XamShowFitnessWarnAboutPrivacyUI();

DECLSPEC_IMPORT VOID NTAPI XamShowFitnessWarnAboutTimeUI();

DECLSPEC_IMPORT VOID NTAPI XamFitnessUnInitialize();

DECLSPEC_IMPORT VOID NTAPI XamBackgroundDownloadNetworkStorageOnContentChange();

DECLSPEC_IMPORT VOID NTAPI XamLiveBaseConfigureInMemoryMockResponse();

DECLSPEC_IMPORT VOID NTAPI InjectConnectionServerNotification();

DECLSPEC_IMPORT VOID NTAPI XamFitnessConvertFloatMetToByteMet();

DECLSPEC_IMPORT VOID NTAPI XamGetGamerTileKeyFromGamertag();

DECLSPEC_IMPORT VOID NTAPI XamBackgroundDownloadNetworkStorageRegisterChangeCallback();

DECLSPEC_IMPORT VOID NTAPI XamFindOrCreateInternalPassportAccount();

DECLSPEC_IMPORT VOID NTAPI XOnlinepFriendsRequest();

DECLSPEC_IMPORT VOID NTAPI XOnlinepFriendsAcceptRequest();

DECLSPEC_IMPORT VOID NTAPI XOnlinepFriendsRejectRequest();

DECLSPEC_IMPORT VOID NTAPI XOnlinepFriendsRemove();

DECLSPEC_IMPORT VOID NTAPI XFriendsCreateEnumerator();

DECLSPEC_IMPORT VOID NTAPI XamBackgroundDownloadNetworkStorageIsRunning();

DECLSPEC_IMPORT VOID NTAPI XamCertGetSerialNumber();

DECLSPEC_IMPORT VOID NTAPI XamShowOptionsUI();

DECLSPEC_IMPORT VOID NTAPI XampXAuthGetTitleBuffer();

DECLSPEC_IMPORT VOID NTAPI XamGetSTSTokenCache();

DECLSPEC_IMPORT VOID NTAPI XamTaskReschedulePeriodicWork();

DECLSPEC_IMPORT VOID NTAPI XamUserGetOnlineXUIDFromOfflineXUID();

DECLSPEC_IMPORT VOID NTAPI XamIsUserUsingMetricSystem();

DECLSPEC_IMPORT VOID NTAPI XamShowNuiVideoRichPresenceUI();

DECLSPEC_IMPORT VOID NTAPI XamAppAllocateInterappWorkspaceEx();

DECLSPEC_IMPORT VOID NTAPI XampKioskSetTestMock();

DECLSPEC_IMPORT VOID NTAPI XamNetworkStatusGetInformation();

DECLSPEC_IMPORT VOID NTAPI XamNetworkStatusAddAddress();

DECLSPEC_IMPORT VOID NTAPI XamUserReadUserPreference();

DECLSPEC_IMPORT VOID NTAPI XamUserWriteUserPreference();

DECLSPEC_IMPORT VOID NTAPI XamShowFitnessClearUI();

DECLSPEC_IMPORT VOID NTAPI XamFitnessClearAll();

DECLSPEC_IMPORT VOID NTAPI XamFitnessGetPrivacySettings();

DECLSPEC_IMPORT VOID NTAPI XamWaitForNSAL();

DECLSPEC_IMPORT VOID NTAPI XamMarkInternalAccountTrustedOnConsole();

DECLSPEC_IMPORT VOID NTAPI XamBackgroundDownloadNetworkStorageGetProgress();

DECLSPEC_IMPORT VOID NTAPI XamCopyFile();

DECLSPEC_IMPORT VOID NTAPI XamMoveFile();

DECLSPEC_IMPORT VOID NTAPI XamDeleteFile();

DECLSPEC_IMPORT VOID NTAPI XamUserOverrideGlobalState();

DECLSPEC_IMPORT VOID NTAPI XamGetAdaptersCollection();

DECLSPEC_IMPORT VOID NTAPI XampKioskIsSimulationMode();

DECLSPEC_IMPORT VOID NTAPI XamIsUIThread();

DECLSPEC_IMPORT VOID NTAPI XamInputSendXenonButtonPress();

DECLSPEC_IMPORT VOID NTAPI XamDebugGetURISchemeCount();

DECLSPEC_IMPORT VOID NTAPI XamDebugGetURISchemeInfo();

DECLSPEC_IMPORT
ULONG
NTAPI
XamGetOnlineCountryFromLocale(
    ULONG id
    );

DECLSPEC_IMPORT VOID NTAPI XTestOnlineIsConnectedToLive();

DECLSPEC_IMPORT VOID NTAPI XamGetConsoleFriendlyName();

DECLSPEC_IMPORT VOID NTAPI XamSetConsoleFriendlyName();

DECLSPEC_IMPORT ULONG NTAPI XamGetCountry(VOID);

DECLSPEC_IMPORT VOID NTAPI XamPackageManagerGetFilePathW();

DECLSPEC_IMPORT VOID NTAPI XamGetCurrentDemand();

DECLSPEC_IMPORT VOID NTAPI XamCompleteDemand();

DECLSPEC_IMPORT VOID NTAPI XamDemand();

DECLSPEC_IMPORT VOID NTAPI XamFormatSystemDateString();

DECLSPEC_IMPORT VOID NTAPI XamDebugGetBackURI();

DECLSPEC_IMPORT VOID NTAPI XamIsCurrentTitleIptv();

DECLSPEC_IMPORT ULONG NTAPI XamIsIptvEnabled(VOID);

DECLSPEC_IMPORT VOID NTAPI XamIsDvrRecording();

DECLSPEC_IMPORT VOID NTAPI XamIptvUninstall();

DECLSPEC_IMPORT
ULONG
NTAPI
XamGetDvrStorage(
    ULONG *dvr_storage,
    ULONG *used_dvr_storage,
    ULONG *hdd_unused_space
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamSetDvrStorage(
    ULONG dvr_storage_size,
    XAM_OVERLAPPED *overlapped_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamIptvGetServiceName(
    ULONG *service_name_ptr
    );

DECLSPEC_IMPORT VOID NTAPI XamNuiHudGetEngagedEnrollmentIndex();

DECLSPEC_IMPORT VOID NTAPI XamProfileSetCachedWindowsLiveEmail();

DECLSPEC_IMPORT VOID NTAPI XamProfileGetCachedWindowsLiveEmail();

DECLSPEC_IMPORT VOID NTAPI XamUserResetSubscriptionType();

DECLSPEC_IMPORT VOID NTAPI XamLrcSetTitlePort();

DECLSPEC_IMPORT VOID NTAPI XamLrcVerifyClientId();

DECLSPEC_IMPORT VOID NTAPI XamLrcEncryptDecryptTitleMessage();

DECLSPEC_IMPORT VOID NTAPI XamFitnessGetSyncStatus();

DECLSPEC_IMPORT VOID NTAPI XamFitnessInitializeForOneUser();

DECLSPEC_IMPORT VOID NTAPI XamFitnessGetSuggestedPrivacySettings();

DECLSPEC_IMPORT VOID NTAPI XampFitnessLetFireAndForgetsCatchUpInternal();

DECLSPEC_IMPORT VOID NTAPI XamInputGetFailedConnectionOrBind();

DECLSPEC_IMPORT VOID NTAPI XuiSceneIsInTransition();

DECLSPEC_IMPORT VOID NTAPI XamIsOnPrivateNetwork();

DECLSPEC_IMPORT VOID NTAPI XamInputSetMinMaxAuthDelay();

DECLSPEC_IMPORT
LONG
NTAPI
XamInputNonControllerGetRawEx(
    ULONG device_id,
    ULONG *buffer_ptr,
    ULONG *buffer_length_ptr,
    USHORT *state_ptr
    );

DECLSPEC_IMPORT
LONG
NTAPI
XamInputNonControllerSetRawEx(
    ULONG device_id,
    ULONG *buffer_ptr,
    ULONG buffer_length
    );

DECLSPEC_IMPORT VOID NTAPI XamMarketplaceAcquireFreeContent();

DECLSPEC_IMPORT VOID NTAPI XMarketplaceAcquireFreeContent();

DECLSPEC_IMPORT VOID NTAPI XamGetClosedCaptioningState();

DECLSPEC_IMPORT VOID NTAPI XamGetClosedCaptioningSettings();

DECLSPEC_IMPORT VOID NTAPI XamSetClosedCaptioningState();

DECLSPEC_IMPORT VOID NTAPI XamLoaderGetLogonTitle();

DECLSPEC_IMPORT VOID NTAPI XamBeginDemand();

DECLSPEC_IMPORT VOID NTAPI XamGetErrorStringFromWebService();

DECLSPEC_IMPORT VOID NTAPI XamGetModernPresenceWorkspaceSize();

DECLSPEC_IMPORT VOID NTAPI XamGetModernPresence();

DECLSPEC_IMPORT VOID NTAPI XamGetSingleModernPresence();

DECLSPEC_IMPORT VOID NTAPI XamGetModernPresenceImageUrl();

DECLSPEC_IMPORT VOID NTAPI XGetSSLCertBypassEnabled();

DECLSPEC_IMPORT VOID NTAPI XamIsNetworkCaptivePortal();

DECLSPEC_IMPORT VOID NTAPI XamShowAndWaitForMessageBoxEx();

DECLSPEC_IMPORT VOID NTAPI XamGetCurrencyFormat();

DECLSPEC_IMPORT VOID NTAPI XamFormatCurrency();

DECLSPEC_IMPORT VOID NTAPI XamReportTLSConnect();

DECLSPEC_IMPORT VOID NTAPI XamGetXSTSTokenExpiryPeriodMS();

DECLSPEC_IMPORT VOID NTAPI XamGetUserBalance();

DECLSPEC_IMPORT VOID NTAPI XamIsGuideDisabled();

DECLSPEC_IMPORT VOID NTAPI XampCallXAccountTransitionStoredValuePointsToCurrency();

DECLSPEC_IMPORT VOID NTAPI XampSetMockCallXAccountTransitionStoredValuePointsToCurrency();

DECLSPEC_IMPORT VOID NTAPI XamShowCsvTransitionUI();

DECLSPEC_IMPORT VOID NTAPI XamAskUserForCSVDrainagePermission();

DECLSPEC_IMPORT VOID NTAPI XamIsCSVDrainageSupported();

DECLSPEC_IMPORT VOID NTAPI XamGetTLSConfig();

DECLSPEC_IMPORT VOID NTAPI XamGetServiceEndpoint();

DECLSPEC_IMPORT VOID NTAPI XamReminderGetItems();

DECLSPEC_IMPORT VOID NTAPI XamReminderClearItems();

DECLSPEC_IMPORT VOID NTAPI XamReminderItemAdd();

DECLSPEC_IMPORT VOID NTAPI XamReminderItemRemove();

DECLSPEC_IMPORT VOID NTAPI XamReminderGetNextItem();

DECLSPEC_IMPORT VOID NTAPI XamSetMockAdapterState();

DECLSPEC_IMPORT VOID NTAPI XamReminderGetModifiedTime();

DECLSPEC_IMPORT VOID NTAPI XamSetMockAdapterResponse();

DECLSPEC_IMPORT VOID NTAPI XamReminderClearCache();

DECLSPEC_IMPORT VOID NTAPI XamClearMockAdapters();

DECLSPEC_IMPORT VOID NTAPI XamLrcKeyboardGetInput();

DECLSPEC_IMPORT VOID NTAPI XamLrcKeyboardGetRequiredBufferSize();

DECLSPEC_IMPORT VOID NTAPI XamLrcKeyboardRegister();

DECLSPEC_IMPORT VOID NTAPI XamLrcKeyboardUnregister();

DECLSPEC_IMPORT VOID NTAPI XamLrcKeyboardUpdateText();

DECLSPEC_IMPORT VOID NTAPI XamValidateCountry();

DECLSPEC_IMPORT
ULONG
NTAPI
XamGetOnlineCountryString(
    ULONG id,
    ULONG buffer_length,
    CONST USHORT *buffer
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamGetCountryString(
    ULONG id,
    ULONG buffer_length,
    CONST USHORT *buffer
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamGetLanguageString(
    ULONG id,
    ULONG buffer_length,
    CONST USHORT *buffer
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamGetLanguageLocaleString(
    ULONG language_id,
    ULONG locale_id,
    ULONG buffer_length,
    CONST USHORT *buffer
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamGetOnlineLanguageAndCountryString(
    ULONG language_id,
    ULONG country_id,
    ULONG buffer_length,
    CONST USHORT *buffer
    );

DECLSPEC_IMPORT
VOID *
NTAPI
XamGetLanguageLocaleFallbackString(
    ULONG language
    );

DECLSPEC_IMPORT
VOID
NTAPI
XamGetOnlineLanguageAndCountry(
    ULONGLONG xuid,
    ULONG language_result_buffer,
    ULONG country_result_buffer
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamGetLanguageTypeface(
    ULONG language,
    ULONG buffer_size,
    ULONG buffer
    );

DECLSPEC_IMPORT
VOID *
NTAPI
XamGetLanguageTypefacePatch(
    ULONG language
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamGetLocaleString(
    ULONG id,
    ULONG buffer_length,
    CONST USHORT *buffer
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamGetLocaleFromOnlineCountry(
    ULONG id
    );

DECLSPEC_IMPORT VOID NTAPI XamOfflineTimerSetData();

DECLSPEC_IMPORT VOID NTAPI XamOfflineTimerResume();

DECLSPEC_IMPORT VOID NTAPI XamOfflineTimerSuspend();

DECLSPEC_IMPORT VOID NTAPI XamOfflineTimerIsRunning();

DECLSPEC_IMPORT VOID NTAPI XamOfflineTimerIsEnabled();

DECLSPEC_IMPORT VOID NTAPI XamOfflineTimerGetTimeRemaining();

DECLSPEC_IMPORT VOID NTAPI XamOfflineTimerGetContractData();

DECLSPEC_IMPORT VOID NTAPI XamOfflineTimerInitialize();

DECLSPEC_IMPORT VOID NTAPI XamOfflineTimerGetData();

DECLSPEC_IMPORT VOID NTAPI XamPlayToRegister();

DECLSPEC_IMPORT VOID NTAPI XamPlayToReportPlaybackState();

DECLSPEC_IMPORT VOID NTAPI XamPlayToUnregister();

DECLSPEC_IMPORT VOID NTAPI XamShowTFAUI();

DECLSPEC_IMPORT VOID NTAPI OnReconnect();

/* Linker spelling at ordinal 1437: OnReconnect@CsInProcNotificationHandler; C spelling: OnReconnect. */

DECLSPEC_IMPORT VOID NTAPI XamGetOnlineCountryFeatures();

DECLSPEC_IMPORT VOID NTAPI XamLogLocalizationEtx();

DECLSPEC_IMPORT VOID NTAPI XampXAuthIsLocalSocketAllowed();

DECLSPEC_IMPORT VOID NTAPI XamPlayToGetRequest();

DECLSPEC_IMPORT VOID NTAPI XamPlayToCancelGetRequest();

DECLSPEC_IMPORT VOID NTAPI XamPlayToCompleteRequest();

DECLSPEC_IMPORT VOID NTAPI XamFitnessGetTitleSummaries();

DECLSPEC_IMPORT VOID NTAPI XamFitnessGetTitleSummary();

DECLSPEC_IMPORT VOID NTAPI XamOfflineTimerShutdown();

DECLSPEC_IMPORT VOID NTAPI XamFitnessContainsFitnessData();

DECLSPEC_IMPORT
ULONG
NTAPI
XamGetLanguageFromOnlineLanguage(
    ULONG id
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamGetOnlineLanguageString(
    ULONG id,
    ULONG buffer_length,
    CONST USHORT *buffer
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamGetCountryFromOnlineCountry(
    ULONG id
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamGetLocaleEx(
    ULONG max_country_id,
    ULONG max_locale_id
    );

DECLSPEC_IMPORT VOID NTAPI XamOfflineTimerForceQuery();

DECLSPEC_IMPORT
ULONG
NTAPI
XamShowCreateProfileUIEx(
    ULONG user_index,
    ULONG flag,
    CONST CHAR *unkn2_ptr
    );

DECLSPEC_IMPORT VOID NTAPI XTLGetLanguageV2();

DECLSPEC_IMPORT VOID NTAPI XTLGetLocaleV1();

DECLSPEC_IMPORT
ULONG
NTAPI
XamAvatarInitialize(
    ULONG coordinate_system,
    ULONG unk2,
    ULONG processor_number,
    ULONG *function_ptrs,
    ULONG *unk5,
    ULONG unk6
    );

DECLSPEC_IMPORT VOID NTAPI XamAvatarShutdown(VOID);

DECLSPEC_IMPORT
ULONG
NTAPI
XamAvatarGetManifestLocalUser(
    ULONG user_index,
    X_AVATAR_METADATA *avatar_metadata_ptr,
    XAM_OVERLAPPED *overlapped_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamAvatarGetMetadataLocalUser(
    ULONG user_index,
    X_AVATAR_METADATA *avatar_metadata_ptr,
    XAM_OVERLAPPED *overlapped_ptr
    );

DECLSPEC_IMPORT VOID NTAPI XamAvatarGetManifestsByXuid();

DECLSPEC_IMPORT VOID NTAPI XamAvatarGetMetadataByXuid();

DECLSPEC_IMPORT
ULONG
NTAPI
XamAvatarGetAssetsResultSize(
    ULONG avatar_component_mask,
    ULONG *result_buffer_size_ptr,
    ULONG *gpu_resource_buffer_size_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamAvatarGetAssets(
    X_AVATAR_METADATA *avatar_metadata_ptr,
    ULONG avatar_component_mask,
    ULONG flags,
    ULONG *result_buffer_ptr,
    ULONG *gpu_resource_buffer_ptr,
    XAM_OVERLAPPED *overlapped_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamAvatarGenerateMipMaps(
    ULONG *avatar_assets_ptr,
    ULONG flags,
    ULONG buffer_size,
    ULONG *mip_map_buffer_ptr,
    XAM_OVERLAPPED *overlapped_ptr
    );

DECLSPEC_IMPORT VOID NTAPI XamAvatarSetCustomAsset();

DECLSPEC_IMPORT
ULONG
NTAPI
XamAvatarSetManifest(
    ULONG user_index,
    ULONG avatar_info_ptr,
    XAM_OVERLAPPED *overlapped_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamAvatarSetMetadata(
    ULONG user_index,
    ULONG avatar_info_ptr,
    XAM_OVERLAPPED *overlapped_ptr
    );

DECLSPEC_IMPORT ULONG NTAPI EnumerateMediaObjects(VOID);

/* Linker spelling at ordinal 1509: EnumerateMediaObjects@CFsMediaSource; C spelling: EnumerateMediaObjects. */

DECLSPEC_IMPORT ULONG NTAPI EnumerateMediaObjects_(VOID);

DECLSPEC_IMPORT
ULONG
NTAPI
XamAvatarLoadAnimation(
    ULONGLONG *asset_id_ptr,
    ULONG flags,
    VOID *output,
    XAM_OVERLAPPED *overlapped_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamAvatarBeginEnumAssets(
    ULONG unk1,
    ULONG unk2,
    ULONG unk3,
    USHORT unk4,
    ULONG unk5,
    XAM_OVERLAPPED *overlapped_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamAvatarEndEnumAssets(
    XAM_OVERLAPPED *overlapped_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamAvatarEnumAssets(
    VOID *unk1,
    ULONGLONG *unk2,
    XAM_OVERLAPPED *overlapped_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamAvatarGetMetadataRandom(
    ULONG body_type,
    ULONG avatars_count,
    X_AVATAR_METADATA *avatar_metadata_ptr,
    XAM_OVERLAPPED *overlapped_ptr
    );

DECLSPEC_IMPORT ULONG NTAPI EnumerateMediaObjects_0(VOID);

DECLSPEC_IMPORT ULONG NTAPI EnumerateMediaObjects_1(VOID);

DECLSPEC_IMPORT
ULONG
NTAPI
XamAvatarGetMetadataSignedOutProfileCount(
    ULONG *profile_count_ptr,
    XAM_OVERLAPPED *overlapped_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamAvatarGetMetadataSignedOutProfile(
    ULONG profile_index,
    X_AVATAR_METADATA *avatar_metadata_ptr,
    XAM_OVERLAPPED *overlapped_ptr
    );

DECLSPEC_IMPORT VOID NTAPI EnumerateMediaObjects_2();

DECLSPEC_IMPORT
ULONG
NTAPI
XamAvatarManifestGetBodyType(
    X_AVATAR_METADATA *avatar_metadata_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamAvatarMetadataGetBodyType(
    X_AVATAR_METADATA *avatar_metadata_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamAvatarGetInstrumentation(
    ULONGLONG unk1,
    ULONG *unk2
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamAvatarGetAssetIcon(
    ULONGLONG *unk1,
    ULONG unk2,
    ULONGLONG *unk3,
    ULONGLONG *unk4,
    XAM_OVERLAPPED *overlapped_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamAvatarWearNow(
    ULONGLONG unk1,
    ULONG *unk2,
    XAM_OVERLAPPED *overlapped_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamAvatarGetAssetBinary(
    VOID *asset_metadata,
    ULONG unk2,
    ULONG unk3,
    ULONG unk4,
    XAM_OVERLAPPED *overlapped_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamAvatarReinstallAwardedAsset(
    CONST CHAR *string_out_ptr,
    ULONG string_size,
    ULONG *unk_ptr
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamLoaderGetSuspendedTitleInfo(
    CONST CHAR *string_out_ptr,
    ULONG string_size,
    ULONG *unk_ptr
    );

DECLSPEC_IMPORT
VOID
NTAPI
XamAvatarGetInstalledAssetPackageDescription(
    X_ASSET_ID *asset_id_ptr,
    XCONTENT_AGGREGATE_DATA *content_data_ptr
    );

DECLSPEC_IMPORT VOID NTAPI XamAvatarSetMocks(VOID);

DECLSPEC_IMPORT VOID NTAPI XamAvatarSetAdapters(VOID);

DECLSPEC_IMPORT VOID NTAPI XamLrcKeyboardValidateTextChange();

DECLSPEC_IMPORT VOID NTAPI XamLrcKeyboardApplyTextChange();

DECLSPEC_IMPORT VOID NTAPI XamLrcLogSessionSummary();

DECLSPEC_IMPORT VOID NTAPI XamLrcLogError();

DECLSPEC_IMPORT VOID NTAPI XamContentMountInstalledGame();

DECLSPEC_IMPORT VOID NTAPI XamContentIsGameInstalledToHDD();

DECLSPEC_IMPORT VOID NTAPI XamContentQueryLicenseInternal();

DECLSPEC_IMPORT
ULONG
NTAPI
XamContentGetDeviceVolumePath(
    ULONG device_id,
    VOID *path_ptr,
    ULONG path_size,
    ULONG append_backslash
    );

DECLSPEC_IMPORT VOID NTAPI XamContentDeviceCheckUpdates();

DECLSPEC_IMPORT VOID NTAPI XamContentGetHeaderInternal();

DECLSPEC_IMPORT VOID NTAPI XamNetworkStorageGetNetworkDevice();

DECLSPEC_IMPORT VOID NTAPI XamNetworkStorageDeviceHasCacheFile();

DECLSPEC_IMPORT VOID NTAPI XamNetworkStorageCreateCacheOnDevice();

DECLSPEC_IMPORT VOID NTAPI XamNetworkStorageDeleteCacheOnDevice();

DECLSPEC_IMPORT VOID NTAPI XamNetworkStorageGetStatus();

DECLSPEC_IMPORT VOID NTAPI XamNetworkStorageIsSupportedContentType();

DECLSPEC_IMPORT VOID NTAPI XamNetworkStorageSetTestMock();

DECLSPEC_IMPORT VOID NTAPI XamNetworkStorageGetLastSyncTime();

DECLSPEC_IMPORT VOID NTAPI XamShowNetworkStorageSyncUI();

DECLSPEC_IMPORT VOID NTAPI XamUserIsLogonPreviewModeEnabled();

DECLSPEC_IMPORT VOID NTAPI XamUserLockLogonPreviewMode();

DECLSPEC_IMPORT VOID NTAPI XamUserUnlockLogonPreviewMode();

DECLSPEC_IMPORT VOID NTAPI XamNetworkStorageIsUserInSync();

DECLSPEC_IMPORT VOID NTAPI XamNetworkStorageSetUserInSync();

DECLSPEC_IMPORT VOID NTAPI XamNetworkStorageOnSigninChanged();

DECLSPEC_IMPORT VOID NTAPI XamNetworkStorageSignInTestMock();

DECLSPEC_IMPORT VOID NTAPI XamShowFofUI();

DECLSPEC_IMPORT VOID NTAPI CompareFileTime();

DECLSPEC_IMPORT VOID NTAPI SetFileTime();

DECLSPEC_IMPORT VOID NTAPI XamNetworkStorageGetTitleProperties();

DECLSPEC_IMPORT VOID NTAPI XamNetworkStorageLockFile();

DECLSPEC_IMPORT VOID NTAPI XamNetworkStorageUserHasPrivilege();

DECLSPEC_IMPORT VOID NTAPI XamNetworkStorageIsTitleExempt();

DECLSPEC_IMPORT VOID NTAPI XamContentExistsOnDeviceInternal();

DECLSPEC_IMPORT VOID NTAPI XamNetworkStorageGetBackingDevice();

DECLSPEC_IMPORT VOID NTAPI XamNetworkStorageIsEnabledInLiveHive();

DECLSPEC_IMPORT VOID NTAPI XamNetworkStorageIsCheckingSyncStates();

DECLSPEC_IMPORT VOID NTAPI XamNetworkStorageUserNeedsToSync();

DECLSPEC_IMPORT VOID NTAPI XamNetworkStorageGetUserNetworkSyncTime();

DECLSPEC_IMPORT VOID NTAPI XamNetworkStorageGetUserProperties();

DECLSPEC_IMPORT VOID NTAPI XamNetworkStorageAppLauncherLaunchIfRunning();

DECLSPEC_IMPORT VOID NTAPI XamNetworkStorageSetTitleProperties();

DECLSPEC_IMPORT VOID NTAPI XamNetworkStorageGetUserLastError();

DECLSPEC_IMPORT VOID NTAPI XamNetworkStorageCheckOutTitle();

DECLSPEC_IMPORT VOID NTAPI XamNetworkStorageShouldHideFromTitle();

DECLSPEC_IMPORT VOID NTAPI XamNetworkStorageOnUserSyncChange();

DECLSPEC_IMPORT VOID NTAPI XamNetworkStorageHasUserEnabledStorage();

DECLSPEC_IMPORT VOID NTAPI XamContentGetLocalizedDeviceData();

DECLSPEC_IMPORT VOID NTAPI XamPackageManagerFindPackageContainingIndexedXEX();

DECLSPEC_IMPORT VOID NTAPI XamPackageManagerReinitialize();

DECLSPEC_IMPORT VOID NTAPI XamPackageManagerGetAuthoritativeManifestVersion();

DECLSPEC_IMPORT VOID NTAPI XamPackageManagerGetAuthoritativeManifestRevision();

DECLSPEC_IMPORT VOID NTAPI XamGetCurrentSystemOnlineManifestRevision();

DECLSPEC_IMPORT VOID NTAPI XamPackageManagerDeleteExtendedPartition();

DECLSPEC_IMPORT VOID NTAPI XamPackageManagerHasExtendedPartition();

DECLSPEC_IMPORT VOID NTAPI XamPackageManagerGetExperienceMode();

DECLSPEC_IMPORT VOID NTAPI XamPackageManagerGetFeatureRequiresUpdateStrings();

DECLSPEC_IMPORT VOID NTAPI XamPackageManagerGetFileSize();

DECLSPEC_IMPORT VOID NTAPI XampDemandUpdateGetAttributes();

DECLSPEC_IMPORT VOID NTAPI XampDemandUpdateGetExtendedAttributes();

DECLSPEC_IMPORT VOID NTAPI XampDemandUpdateGetInstance();

DECLSPEC_IMPORT VOID NTAPI XampDemandUpdateSetRefreshTestFlags();

DECLSPEC_IMPORT VOID NTAPI XampDemandUpdateIsRefreshTestFlagSet();

DECLSPEC_IMPORT VOID NTAPI XampDemandUpdateGetManifestLocalPath();

DECLSPEC_IMPORT VOID NTAPI XampDemandUpdateRefreshManifest();

DECLSPEC_IMPORT VOID NTAPI XdfInitialize();

DECLSPEC_IMPORT VOID NTAPI XdfShutdown();

DECLSPEC_IMPORT VOID NTAPI XdfGetExpectedDownloadSize();

DECLSPEC_IMPORT VOID NTAPI XdfGetItem();

DECLSPEC_IMPORT VOID NTAPI XdfCacheItem();

DECLSPEC_IMPORT VOID NTAPI XdfLoadXexFromCache();

DECLSPEC_IMPORT VOID NTAPI XdfLoadXex();

DECLSPEC_IMPORT VOID NTAPI XdfCancelRequest();

DECLSPEC_IMPORT VOID NTAPI XdfResumeDelayedItem();

DECLSPEC_IMPORT VOID NTAPI XdfLaunchNewImageFromCache();

DECLSPEC_IMPORT VOID NTAPI XampDemandUpdateRefreshManifestDuringLogon();

DECLSPEC_IMPORT VOID NTAPI XampDemandUpdateCheckOnlineManifestChanged();

DECLSPEC_IMPORT VOID NTAPI XampDemandUpdateRunCacheCleaner();

DECLSPEC_IMPORT VOID NTAPI XamUpdateGetTitleUpdateSizeThreshold();

DECLSPEC_IMPORT VOID NTAPI XamXStudioRequest();

DECLSPEC_IMPORT VOID NTAPI XamNotifyDelayUIInternal();

DECLSPEC_IMPORT VOID NTAPI XamShowAvatarMiniCreatorUI();

DECLSPEC_IMPORT VOID NTAPI XamShowGoldUpgradeUI();

DECLSPEC_IMPORT VOID NTAPI XamResumeUpdaterUI();

DECLSPEC_IMPORT VOID NTAPI XamShowDirectAcquireUI();

DECLSPEC_IMPORT VOID NTAPI XamShowPaymentOptionsUI();

DECLSPEC_IMPORT VOID NTAPI XamShowMultiplayerUpgradeUI();

DECLSPEC_IMPORT VOID NTAPI XamGetLiveHiveValueA();

DECLSPEC_IMPORT VOID NTAPI XamGetLiveHiveValueW();

DECLSPEC_IMPORT VOID NTAPI XamGetLiveHiveValueDuringLogonAttemptA();

DECLSPEC_IMPORT VOID NTAPI XamSetUserPresetWindowsLiveCreds();

DECLSPEC_IMPORT VOID NTAPI XamQueryLiveHiveA();

DECLSPEC_IMPORT
ULONG
NTAPI
XamQueryLiveHiveW(
    CONST USHORT *name,
    VOID *out_buf,
    ULONG out_size,
    ULONG type
    );

DECLSPEC_IMPORT VOID NTAPI XamGetLiveHiveValueDuringLogonAttemptExA();

DECLSPEC_IMPORT VOID NTAPI XamGetUserPresetWindowsLiveCreds();

DECLSPEC_IMPORT VOID NTAPI XamGetUserNeedTFA();

DECLSPEC_IMPORT VOID NTAPI XamSetUserNeedTFA();

DECLSPEC_IMPORT VOID NTAPI XamGetUserInMemoryWindowsLiveCreds();

DECLSPEC_IMPORT VOID NTAPI XamDownloadMarketplaceStoresList();

DECLSPEC_IMPORT VOID NTAPI XamGetStoreFront();

DECLSPEC_IMPORT VOID NTAPI XamSetStagingMode();

DECLSPEC_IMPORT ULONG NTAPI XamGetStagingMode(VOID);

DECLSPEC_IMPORT VOID NTAPI XamAppGetSessionId();

DECLSPEC_IMPORT VOID NTAPI XamAccountRecoveryRecoverAllProfileData();

DECLSPEC_IMPORT VOID NTAPI XamAccountRecoveryGetProgress();

DECLSPEC_IMPORT ULONG NTAPI XamDoesOmniNeedConfiguration(VOID);

DECLSPEC_IMPORT ULONG NTAPI XamFirstRunExperienceShouldRun(VOID);

DECLSPEC_IMPORT VOID NTAPI GetProcessHeap();

DECLSPEC_IMPORT VOID NTAPI UnhandledExceptionFilter();

DECLSPEC_IMPORT VOID NTAPI SetUnhandledExceptionFilter();

DECLSPEC_IMPORT VOID NTAPI XamIsOptionalMediaUpdateInstalled();

DECLSPEC_IMPORT VOID NTAPI XamShowOptionalMediaUpdateRequiredUI();

DECLSPEC_IMPORT VOID NTAPI XamShowOptionalMediaUpdateRequiredUIEx();

DECLSPEC_IMPORT VOID NTAPI XamShowFirstRunWelcomeUI();

DECLSPEC_IMPORT VOID NTAPI XamTaskCreateQueueEx();

DECLSPEC_IMPORT VOID NTAPI XamSetDashBackstackData();

DECLSPEC_IMPORT VOID NTAPI XamSetTextureLoaderHook();

DECLSPEC_IMPORT VOID NTAPI XamLaunchAvatarEditor();

DECLSPEC_IMPORT
ULONG
NTAPI
XamGetDashBackstackData(
    X_DASH_BACKSTACK_DATA *backstack_data,
    ULONG *count
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamLoadExtraAVCodecs(
    X_DASH_BACKSTACK_DATA *backstack_data,
    ULONG *count
    );

DECLSPEC_IMPORT VOID NTAPI XamGetDashBackstackNodesCount();

DECLSPEC_IMPORT VOID NTAPI XamUnloadExtraAVCodecs();

DECLSPEC_IMPORT VOID NTAPI XamSetLastActiveUserData();

DECLSPEC_IMPORT VOID NTAPI XamGetLastActiveUserData();

DECLSPEC_IMPORT
VOID
NTAPI
XamSetActiveDashAppInfo(
    X_DASH_APP_INFO *dash_app
    );

DECLSPEC_IMPORT
VOID
NTAPI
XamGetActiveDashAppInfo(
    X_DASH_APP_INFO *dash_app
    );

DECLSPEC_IMPORT VOID NTAPI XamLoaderRegisterLaunchRequestCallback();

DECLSPEC_IMPORT VOID NTAPI XamLoadExtraAVCodecs2();

DECLSPEC_IMPORT VOID NTAPI XamUnloadExtraAVCodecs2();

DECLSPEC_IMPORT VOID NTAPI XamUserCreateAvatarAssetEnumerator();

DECLSPEC_IMPORT VOID NTAPI XamInitializeGameTileCache();

DECLSPEC_IMPORT VOID NTAPI XamDestroyGameTileCache();

DECLSPEC_IMPORT VOID NTAPI XamReadGameTileImage();

DECLSPEC_IMPORT VOID NTAPI XamShouldThrottleAccountInfoCall();

DECLSPEC_IMPORT VOID NTAPI XuiClassDerivesFrom();

DECLSPEC_IMPORT VOID NTAPI XuiFreeVisuals();

DECLSPEC_IMPORT VOID NTAPI XuiGetBaseClass();

DECLSPEC_IMPORT VOID NTAPI XuiLoadVisualFromBinary();

DECLSPEC_IMPORT VOID NTAPI XuiResourceGetBuffer();

DECLSPEC_IMPORT VOID NTAPI XuiResourceGetTotalSize();

DECLSPEC_IMPORT VOID NTAPI XuiElementGetUserData();

DECLSPEC_IMPORT VOID NTAPI XuiElementSetUserData();

DECLSPEC_IMPORT VOID NTAPI XuiTabSceneGetCount();

DECLSPEC_IMPORT VOID NTAPI XuiSliderGetStep();

DECLSPEC_IMPORT VOID NTAPI XuiSliderSetStep();

DECLSPEC_IMPORT VOID NTAPI XuiProgressBarGetRange();

DECLSPEC_IMPORT VOID NTAPI XuiElementSetHittable();

DECLSPEC_IMPORT VOID NTAPI XuiElementPlayNamedFrames();

DECLSPEC_IMPORT VOID NTAPI XuiElementGetPivot();

DECLSPEC_IMPORT VOID NTAPI XuiElementGetPrev();

DECLSPEC_IMPORT VOID NTAPI XuiElementGetScale();

DECLSPEC_IMPORT VOID NTAPI XuiElementSetPivot();

DECLSPEC_IMPORT VOID NTAPI XuiElementSetRotation();

DECLSPEC_IMPORT VOID NTAPI XuiElementSetScale();

DECLSPEC_IMPORT VOID NTAPI XuiControlWantsUnfocusedInput();

DECLSPEC_IMPORT VOID NTAPI XuiResourceOpenNoLoc();

DECLSPEC_IMPORT VOID NTAPI XuiResourceReleasePackage();

DECLSPEC_IMPORT VOID NTAPI XuiResourceGetPackageEntryInfo();

DECLSPEC_IMPORT VOID NTAPI XuiResourceGetPackageEntryCount();

DECLSPEC_IMPORT VOID NTAPI XuiResourceOpenPackage();

DECLSPEC_IMPORT VOID NTAPI XamCodeCoverageFileOpen();

DECLSPEC_IMPORT VOID NTAPI XamCodeCoverageFileClose();

DECLSPEC_IMPORT VOID NTAPI XamCodeCoverageFileLseek();

DECLSPEC_IMPORT VOID NTAPI XamCodeCoverageFileRead();

DECLSPEC_IMPORT VOID NTAPI XamCodeCoverageFileWrite();

DECLSPEC_IMPORT VOID NTAPI Refresh_1();

DECLSPEC_IMPORT VOID NTAPI XampHeapGetInfo();

DECLSPEC_IMPORT VOID NTAPI XampHeapGetCount();

DECLSPEC_IMPORT VOID NTAPI XamShowPamUI();

DECLSPEC_IMPORT VOID NTAPI XampKioskSetTestMockValues();

DECLSPEC_IMPORT VOID NTAPI XuiElementLayoutTree();

DECLSPEC_IMPORT VOID NTAPI XamRegisterScreenSaverCallback();

DECLSPEC_IMPORT VOID NTAPI XamInactivityResetAllState();

DECLSPEC_IMPORT VOID NTAPI XUIElementPropVal_SetInt();

DECLSPEC_IMPORT VOID NTAPI XUIElementPropVal_SetFloat();

DECLSPEC_IMPORT VOID NTAPI XuiObjectGetPropertyDef();

DECLSPEC_IMPORT VOID NTAPI XuiRenderGetDevice();

DECLSPEC_IMPORT VOID NTAPI XuiRenderRestoreState();

DECLSPEC_IMPORT VOID NTAPI XuiElementGetFullXForm();

DECLSPEC_IMPORT VOID NTAPI XuiRenderGetViewTransform();

DECLSPEC_IMPORT VOID NTAPI XuiRenderGetColorSpace();

DECLSPEC_IMPORT VOID NTAPI XamPngEncode();

DECLSPEC_IMPORT VOID NTAPI XamPngDecode();

DECLSPEC_IMPORT VOID NTAPI XamPngEncodeEx();

DECLSPEC_IMPORT VOID NTAPI XuiTextElementMeasureText();

DECLSPEC_IMPORT VOID NTAPI XamLoaderShouldConfirmReboot();

DECLSPEC_IMPORT VOID NTAPI XamLoaderRebootToDash();

DECLSPEC_IMPORT ULONGLONG NTAPI XamNuiHudGetEngagedTrackingID(VOID);

DECLSPEC_IMPORT VOID NTAPI XamLoaderLaunchTitleForReason();

DECLSPEC_IMPORT
ULONG
NTAPI
XamNuiHudSetEngagedTrackingID(
    ULONG id
    );

DECLSPEC_IMPORT VOID NTAPI XuiBrushGetTexture();

DECLSPEC_IMPORT VOID NTAPI XamSetupTexture();

DECLSPEC_IMPORT VOID NTAPI XuiBrushGetDims();

DECLSPEC_IMPORT VOID NTAPI XuiElementGetDescendantById();

DECLSPEC_IMPORT VOID NTAPI XamLoaderIsKinectUIPreferredForLogonTitle();

DECLSPEC_IMPORT VOID NTAPI XamSetupCameraPreviewStuff();

DECLSPEC_IMPORT VOID NTAPI XamReleaseCameraPreviewStuff();

DECLSPEC_IMPORT VOID NTAPI XamRenderCameraPreviewStuff();

DECLSPEC_IMPORT VOID NTAPI XamAccountRecoveryGetSetTitleSyncTime();

DECLSPEC_IMPORT VOID NTAPI XamReadBiometricData();

DECLSPEC_IMPORT VOID NTAPI XamWriteBiometricData();

DECLSPEC_IMPORT VOID NTAPI XamD3DResourceDescriptorCreate();

DECLSPEC_IMPORT VOID NTAPI XamD3DResourceDescriptorAddRef();

DECLSPEC_IMPORT VOID NTAPI XamD3DResourceDescriptorRelease();

DECLSPEC_IMPORT VOID NTAPI XamD3DResourceAddRef();

DECLSPEC_IMPORT VOID NTAPI XamD3DResourceSet();

DECLSPEC_IMPORT VOID NTAPI XamD3DResourceIsBusy();

DECLSPEC_IMPORT VOID NTAPI XamD3DResourceRelease();

DECLSPEC_IMPORT VOID NTAPI ControlPackGetCursorPosition();

DECLSPEC_IMPORT VOID NTAPI ControlPackShouldShowCursor();

DECLSPEC_IMPORT VOID NTAPI XamFlushAgraTemperatureReport();

DECLSPEC_IMPORT VOID NTAPI XamNatalDeviceAudioCalibrate();

DECLSPEC_IMPORT VOID NTAPI XamNuiIdentityGetEnrollmentInfo();

DECLSPEC_IMPORT VOID NTAPI XamNuiIdentityUnenroll();

DECLSPEC_IMPORT VOID NTAPI XamNuiIdentityGetColorTexture();

DECLSPEC_IMPORT VOID NTAPI XamReportKinectSettingsChangedEvent();

DECLSPEC_IMPORT VOID NTAPI XamNuiEnableChatMic();

DECLSPEC_IMPORT ULONG NTAPI XamNuiIsChatMicEnabled(VOID);

DECLSPEC_IMPORT
ULONG
NTAPI
XamNuiGetDepthCalibration(
    ULONG *unk1
    );

DECLSPEC_IMPORT VOID NTAPI XamNuiStoreDepthCalibration();

DECLSPEC_IMPORT VOID NTAPI XamUserNuiIsBiometricEnabled();

DECLSPEC_IMPORT
ULONG
NTAPI
XamUserNuiEnableBiometric(
    ULONG user_index,
    LONG enable
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamNuiCameraSetFlags(
    ULONGLONG unk1,
    ULONG unk2
    );

DECLSPEC_IMPORT VOID NTAPI XamNuiCameraRememberFloor();

DECLSPEC_IMPORT
ULONG
NTAPI
XamUserNuiGetUserIndexForBind(
    ULONG *index
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamUserNuiGetUserIndexForSignin(
    ULONG *index
    );

DECLSPEC_IMPORT VOID NTAPI XamUserNuiBind();

DECLSPEC_IMPORT VOID NTAPI XamUserNuiGetUserIndex();

DECLSPEC_IMPORT VOID NTAPI XamUserNuiGetEnrollmentIndex();

DECLSPEC_IMPORT VOID NTAPI XamUserNuiUnbind();

DECLSPEC_IMPORT VOID NTAPI XamNuiIdentityGetQualityFlagsMessage();

DECLSPEC_IMPORT VOID NTAPI XamNuiUseTemporaryDepthCalibration();

DECLSPEC_IMPORT VOID NTAPI XamNuiCameraTiltSetCallback();

DECLSPEC_IMPORT ULONG NTAPI XamNuiHudIsEnabled(VOID);

DECLSPEC_IMPORT ULONG NTAPI XamNuiCameraGetTiltControllerType(VOID);

DECLSPEC_IMPORT
ULONG
NTAPI
XamNuiCameraTiltGetStatus(
    VOID *unk
    );

DECLSPEC_IMPORT VOID NTAPI XamNuiIdentityGetQualityFlags();

DECLSPEC_IMPORT
ULONG
NTAPI
XamNuiIdentityEnrollForSignIn(
    ULONG unk1,
    ULONGLONG unk2,
    ULONGLONG unk3,
    ULONG unk4
    );

DECLSPEC_IMPORT ULONGLONG NTAPI XamNuiIdentityGetSessionId(VOID);

DECLSPEC_IMPORT VOID NTAPI XamNuiIdentityIdentifyWithBiometric();

DECLSPEC_IMPORT VOID NTAPI ControlPackGetHandleManager();

DECLSPEC_IMPORT VOID NTAPI XamEnableNuiAutomation();

DECLSPEC_IMPORT VOID NTAPI XamNuiGetSystemGestureControl();

DECLSPEC_IMPORT VOID NTAPI XamGetPasscodeKeyFromVirtualKey();

DECLSPEC_IMPORT VOID NTAPI XamEnableNatalPlayback();

DECLSPEC_IMPORT VOID NTAPI XamIsNuiAutomationEnabled();

DECLSPEC_IMPORT VOID NTAPI XamIsNatalPlaybackEnabled();

DECLSPEC_IMPORT VOID NTAPI XamNuiHudInterpretFrame();

DECLSPEC_IMPORT VOID NTAPI XamNuiHudEnableInputFilter();

DECLSPEC_IMPORT VOID NTAPI ControlpackNuiCursorSetTrackingId();

DECLSPEC_IMPORT VOID NTAPI XamUserNuiIsBiometricAugmentRecommended();

DECLSPEC_IMPORT ULONG NTAPI XamNuiHudGetInitializeFlags(VOID);

DECLSPEC_IMPORT VOID NTAPI XamNuiCameraElevationSetAngle();

DECLSPEC_IMPORT
ULONG
NTAPI
XamNuiCameraElevationGetAngle(
    ULONGLONG *unk1,
    ULONG *unk2
    );

DECLSPEC_IMPORT VOID NTAPI XamNuiCameraElevationAutoTilt();

DECLSPEC_IMPORT VOID NTAPI XamNuiCameraElevationStopMovement();

DECLSPEC_IMPORT VOID NTAPI XamNuiCameraElevationSetCallback();

DECLSPEC_IMPORT
ULONG
NTAPI
XamNuiGetDeviceStatus(
    X_NUI_DEVICE_STATUS *status_ptr
    );

DECLSPEC_IMPORT VOID NTAPI XamNuiNatalCameraUpdateStarting();

DECLSPEC_IMPORT VOID NTAPI XamNuiNatalCameraUpdateComplete();

DECLSPEC_IMPORT
VOID
NTAPI
XamNuiHudGetVersions(
    ULONGLONG *unk1,
    ULONGLONG *unk2
    );

DECLSPEC_IMPORT VOID NTAPI XamGetHUDElementByPath();

DECLSPEC_IMPORT VOID NTAPI XamGetHUDElementByAutoId();

DECLSPEC_IMPORT VOID NTAPI XuiElementGetScreenPositionCenter();

DECLSPEC_IMPORT VOID NTAPI XamNuiCameraElevationReverseAutoTilt();

DECLSPEC_IMPORT VOID NTAPI ControlPackSimpleCursorGetRayFromScreenPosition();

DECLSPEC_IMPORT VOID NTAPI ControlPackSideNavControlGetNuiHandle();

DECLSPEC_IMPORT VOID NTAPI XamFindHUDElementByXuiId();

DECLSPEC_IMPORT ULONG NTAPI XamNuiIsDeviceReady(VOID);

DECLSPEC_IMPORT VOID NTAPI XamNuiSetForceDeviceOff();

DECLSPEC_IMPORT VOID NTAPI XamNuiPlayerEngagementUpdate();

DECLSPEC_IMPORT
ULONGLONG
NTAPI
XamNuiSkeletonGetBestSkeletonIndex(
    LONG unk
    );

DECLSPEC_IMPORT VOID NTAPI XamNuiSkeletonScoreUpdate();

DECLSPEC_IMPORT VOID NTAPI XamNuiCameraTiltReportStatus();

DECLSPEC_IMPORT VOID NTAPI XamNuiCameraAdjustTilt();

DECLSPEC_IMPORT
ULONG
NTAPI
XamNuiIdentityAbort(
    ULONG unk
    );

DECLSPEC_IMPORT VOID NTAPI D3DDevice_CreateVertexShader();

DECLSPEC_IMPORT VOID NTAPI D3DDevice_CreatePixelShader();

DECLSPEC_IMPORT VOID NTAPI D3DDevice_CreateTexture();

DECLSPEC_IMPORT VOID NTAPI D3DDevice_CreateVertexBuffer();

DECLSPEC_IMPORT VOID NTAPI D3DDevice_CreateIndexBuffer();

DECLSPEC_IMPORT VOID NTAPI D3DDevice_CreateVertexDeclaration();

DECLSPEC_IMPORT VOID NTAPI D3DVertexBuffer_Unlock();

DECLSPEC_IMPORT VOID NTAPI D3DVertexBuffer_Lock();

DECLSPEC_IMPORT VOID NTAPI D3DIndexBuffer_Unlock();

DECLSPEC_IMPORT VOID NTAPI D3DIndexBuffer_Lock();

DECLSPEC_IMPORT VOID NTAPI D3DTexture_UnlockRect();

DECLSPEC_IMPORT VOID NTAPI D3DTexture_LockRect();

DECLSPEC_IMPORT VOID NTAPI D3DDevice_Clear();

DECLSPEC_IMPORT VOID NTAPI D3DDevice_SetViewport();

DECLSPEC_IMPORT VOID NTAPI D3DDevice_GetViewport();

DECLSPEC_IMPORT VOID NTAPI D3DVertexShader_Release();

DECLSPEC_IMPORT VOID NTAPI D3DDevice_SetRenderState_SrcBlend();

DECLSPEC_IMPORT VOID NTAPI D3DPixelShader_Release();

DECLSPEC_IMPORT VOID NTAPI D3DDevice_SetRenderState_DestBlend();

DECLSPEC_IMPORT VOID NTAPI D3DVertexDeclaration_Release();

DECLSPEC_IMPORT VOID NTAPI D3DResource_Release();

DECLSPEC_IMPORT VOID NTAPI D3DDevice_Release();

DECLSPEC_IMPORT VOID NTAPI D3DDevice_SetVertexShader();

DECLSPEC_IMPORT VOID NTAPI D3DDevice_SetPixelShader();

DECLSPEC_IMPORT VOID NTAPI D3DDevice_SetTexture();

DECLSPEC_IMPORT VOID NTAPI D3DDevice_SetVertexDeclaration();

DECLSPEC_IMPORT VOID NTAPI D3DDevice_SetIndices();

DECLSPEC_IMPORT VOID NTAPI D3DDevice_SetStreamSource();

DECLSPEC_IMPORT VOID NTAPI D3DDevice_DrawVertices();

DECLSPEC_IMPORT VOID NTAPI D3DDevice_DrawVerticesUP();

DECLSPEC_IMPORT VOID NTAPI D3DDevice_DrawIndexedVertices();

DECLSPEC_IMPORT VOID NTAPI D3DDevice_DrawIndexedVerticesUP();

DECLSPEC_IMPORT VOID NTAPI D3DDevice_SetVertexShaderConstantF_ParameterCheck();

DECLSPEC_IMPORT VOID NTAPI D3DDevice_SetPixelShaderConstantF_ParameterCheck();

DECLSPEC_IMPORT VOID NTAPI D3DDevice_SetSamplerState_ParameterCheck();

DECLSPEC_IMPORT VOID NTAPI D3DDevice_SetRenderState_ParameterCheck();

DECLSPEC_IMPORT VOID NTAPI D3DDevice_GetRenderState_ParameterCheck();

DECLSPEC_IMPORT VOID NTAPI D3DDevice_SetVertexShaderConstantFN();

DECLSPEC_IMPORT VOID NTAPI D3DDevice_SetPixelShaderConstantFN();

DECLSPEC_IMPORT VOID NTAPI D3DDevice_GetRenderState_ZEnable();

DECLSPEC_IMPORT VOID NTAPI D3DDevice_GetRenderState_CullMode();

DECLSPEC_IMPORT VOID NTAPI D3DDevice_GetRenderState_AlphaBlendEnable();

DECLSPEC_IMPORT VOID NTAPI D3DDevice_GetRenderState_SrcBlendAlpha();

DECLSPEC_IMPORT VOID NTAPI D3DDevice_GetRenderState_DestBlendAlpha();

DECLSPEC_IMPORT VOID NTAPI D3DDevice_GetRenderState_BlendOp();

DECLSPEC_IMPORT VOID NTAPI D3DDevice_GetRenderState_ViewportEnable();

DECLSPEC_IMPORT VOID NTAPI D3DDevice_SetRenderState_ZEnable();

DECLSPEC_IMPORT VOID NTAPI D3DDevice_SetRenderState_CullMode();

DECLSPEC_IMPORT VOID NTAPI D3DDevice_SetRenderState_AlphaBlendEnable();

DECLSPEC_IMPORT VOID NTAPI D3DDevice_SetRenderState_SrcBlendAlpha();

DECLSPEC_IMPORT VOID NTAPI D3DDevice_SetRenderState_DestBlendAlpha();

DECLSPEC_IMPORT VOID NTAPI D3DDevice_SetRenderState_BlendOp();

DECLSPEC_IMPORT VOID NTAPI D3DDevice_SetRenderState_ViewportEnable();

DECLSPEC_IMPORT VOID NTAPI D3DDevice_SetSamplerState_MagFilter();

DECLSPEC_IMPORT VOID NTAPI D3DDevice_SetSamplerState_MinFilter();

DECLSPEC_IMPORT VOID NTAPI D3DDevice_SetSamplerState_AddressU();

DECLSPEC_IMPORT VOID NTAPI D3DDevice_SetSamplerState_AddressV();

DECLSPEC_IMPORT VOID NTAPI XGSetTextureHeader();

DECLSPEC_IMPORT VOID NTAPI XGGetTextureDesc();

DECLSPEC_IMPORT VOID NTAPI XGOffsetResourceAddress();

DECLSPEC_IMPORT VOID NTAPI D3DResource_AddRef();

DECLSPEC_IMPORT VOID NTAPI D3DVertexShader_AddRef();

DECLSPEC_IMPORT VOID NTAPI D3DPixelShader_AddRef();

DECLSPEC_IMPORT VOID NTAPI D3DVertexDeclaration_AddRef();

DECLSPEC_IMPORT VOID NTAPI XGSetTextureHeaderEx();

DECLSPEC_IMPORT VOID NTAPI D3DDevice_GetRenderTarget();

DECLSPEC_IMPORT VOID NTAPI D3DDevice_SetRenderTarget();

DECLSPEC_IMPORT VOID NTAPI D3DDevice_GetDepthStencilSurface();

DECLSPEC_IMPORT VOID NTAPI D3DDevice_SetDepthStencilSurface();

DECLSPEC_IMPORT VOID NTAPI D3DDevice_Resolve();

DECLSPEC_IMPORT VOID NTAPI D3DDevice_SetPixelShaderConstantB();

DECLSPEC_IMPORT VOID NTAPI XamNuiGetDeviceSerialNumber();

DECLSPEC_IMPORT VOID NTAPI XamNuiGetLoadedDepthCalibration();

DECLSPEC_IMPORT VOID NTAPI XamNuiGetTrueColorInfo();

DECLSPEC_IMPORT VOID NTAPI XamNuiGetCameraIntrinsics();

DECLSPEC_IMPORT VOID NTAPI XamNuiGetFanRate();

DECLSPEC_IMPORT VOID NTAPI XamNuiGetSupportString();

DECLSPEC_IMPORT VOID NTAPI XamKinectGetHardwareType();

DECLSPEC_IMPORT VOID NTAPI XamXtwManagerGetVariableCount();

DECLSPEC_IMPORT VOID NTAPI XamXtwManagerGetId();

DECLSPEC_IMPORT VOID NTAPI XamXtwManagerGetValue();

DECLSPEC_IMPORT VOID NTAPI XamXtwManagerSetValue();

DECLSPEC_IMPORT VOID NTAPI XamXtwManagerIncrement();

DECLSPEC_IMPORT VOID NTAPI XamXtwManagerDecrement();

DECLSPEC_IMPORT VOID NTAPI XamXtwManagerResetValue();

DECLSPEC_IMPORT VOID NTAPI XamXtwManagerResetAll();

DECLSPEC_IMPORT VOID NTAPI XamXtwManagerGetDataFilePath();

DECLSPEC_IMPORT VOID NTAPI XamXtwManagerDeleteDataFile();

DECLSPEC_IMPORT VOID NTAPI XamXtwManagerSave();

DECLSPEC_IMPORT VOID NTAPI XamXtwManagerLoad();

DECLSPEC_IMPORT VOID NTAPI XamGetXTweakManager();

DECLSPEC_IMPORT
ULONG
NTAPI
XamMediaVerificationCreate(
    ULONG creation_flags
    );

DECLSPEC_IMPORT ULONG NTAPI XamMediaVerificationClose(VOID);

DECLSPEC_IMPORT
ULONG
NTAPI
XamMediaVerificationVerify(
    ULONG r3,
    XAM_OVERLAPPED *overlapped,
    VOID *callback
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamMediaVerificationFailedBlocks(
    X_SECURITY_FAILURE_INFORMATION *failure_information
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamMediaVerificationInject(
    ULONG r3,
    ULONG r4
    );

DECLSPEC_IMPORT VOID NTAPI XamShowBadDiscErrorUI();

DECLSPEC_IMPORT VOID NTAPI XamBackgroundDownloadSetMode();

DECLSPEC_IMPORT VOID NTAPI XamBackgroundDownloadIsEnabled();

DECLSPEC_IMPORT VOID NTAPI XamBackgroundDownloadGetActiveItem();

DECLSPEC_IMPORT VOID NTAPI XamBackgroundDownloadGetItems();

DECLSPEC_IMPORT VOID NTAPI XamBackgroundDownloadClearItems();

DECLSPEC_IMPORT VOID NTAPI XamBackgroundDownloadItemAdd();

DECLSPEC_IMPORT VOID NTAPI XamBackgroundDownloadItemRemove();

DECLSPEC_IMPORT VOID NTAPI XamBackgroundDownloadItemMakeFirst();

DECLSPEC_IMPORT VOID NTAPI XamBackgroundDownloadSetForegroundPriority();

DECLSPEC_IMPORT VOID NTAPI XamBackgroundDownloadGetForegroundPriority();

DECLSPEC_IMPORT VOID NTAPI XamBackgroundDownloadItemToContentData();

DECLSPEC_IMPORT VOID NTAPI XamBackgroundDownloadItemGetStatus();

DECLSPEC_IMPORT VOID NTAPI XamBackgroundDownloadHistoryGetItem();

DECLSPEC_IMPORT VOID NTAPI XamBackgroundDownloadItemGetHistoryStatus();

DECLSPEC_IMPORT VOID NTAPI XamBackgroundDownloadItemSetHistoryStatus();

DECLSPEC_IMPORT VOID NTAPI XamBackgroundDownloadItemGetStatusAsync();

DECLSPEC_IMPORT VOID NTAPI XamBackgroundDownloadItemGetStatusEx();

DECLSPEC_IMPORT VOID NTAPI XamBackgroundDownloadItemGetHistoryStatusEx();

DECLSPEC_IMPORT VOID NTAPI XamBackgroundDownloadBindItems();

DECLSPEC_IMPORT VOID NTAPI XamBackgroundDownloadSetPollingActive();

DECLSPEC_IMPORT VOID NTAPI XamBackgroundDownloadGetPollingActive();

DECLSPEC_IMPORT VOID NTAPI XamBackgroundDownloadGetMode();

DECLSPEC_IMPORT VOID NTAPI XamBackgroundDownloadGetUnexpectedChangeCount();

DECLSPEC_IMPORT VOID NTAPI XamBackgroundDownloadIsItemForThisConsole();

DECLSPEC_IMPORT VOID NTAPI XamBackgroundDownloadSelectDevice();

DECLSPEC_IMPORT VOID NTAPI XamBackgroundDownloadItemModify();

DECLSPEC_IMPORT VOID NTAPI XamBackgroundDownloadCacheLegacyMappingInfo();

DECLSPEC_IMPORT VOID NTAPI XamBackgroundDownloadGetLegacyMappingInfo();

DECLSPEC_IMPORT VOID NTAPI XamBackgroundDownloadGetLegacyId();

DECLSPEC_IMPORT VOID NTAPI XamBackgroundDownloadDoFail();

DECLSPEC_IMPORT VOID NTAPI XamDownloadSingleItem();

DECLSPEC_IMPORT VOID NTAPI XamDownloadInSingleItemMode();

DECLSPEC_IMPORT
ULONG
NTAPI
XamSwapDisc(
    ULONG disc_number,
    X_KEVENT *completion_handle,
    X_SWAPDISC_ERROR_MESSAGE *error_message
    );

EXTERN_C DECLSPEC_IMPORT struct _NXEDK_OPAQUE_EXPORT XamSwapDiscPatchAddress;

DECLSPEC_IMPORT VOID NTAPI XamSwapCancel();

DECLSPEC_IMPORT VOID NTAPI XamContentSetAttributes();

DECLSPEC_IMPORT VOID NTAPI XamRamDriveCreate();

DECLSPEC_IMPORT VOID NTAPI XamRamDriveDestroy();

DECLSPEC_IMPORT VOID NTAPI XamPlayTimerGetData();

DECLSPEC_IMPORT VOID NTAPI XamPlayTimerSetData();

DECLSPEC_IMPORT VOID NTAPI XamPlayTimerResume();

DECLSPEC_IMPORT VOID NTAPI XamPlayTimerSuspend();

DECLSPEC_IMPORT VOID NTAPI XamPlayTimerIsRunning();

DECLSPEC_IMPORT VOID NTAPI XamPlayTimerIsEnabled();

DECLSPEC_IMPORT VOID NTAPI XamPlayTimerGetNextResetDate();

DECLSPEC_IMPORT VOID NTAPI XamPlayTimerFormatDurationString();

DECLSPEC_IMPORT VOID NTAPI XamPlayTimerGetTimeRemaining();

DECLSPEC_IMPORT VOID NTAPI XamPlayTimerUpdateTimeRemaining();

DECLSPEC_IMPORT VOID NTAPI XamPlayTimerForceNotification();

DECLSPEC_IMPORT VOID NTAPI XamPlayTimerRefreshResetDate();

DECLSPEC_IMPORT VOID NTAPI XuiResourceOpenAndVerifyNoLoc();

DECLSPEC_IMPORT VOID NTAPI UpnpAVServerSearchInitialize();

DECLSPEC_IMPORT VOID NTAPI UpnpAVServerSearchDestroy();

DECLSPEC_IMPORT VOID NTAPI UpnpAVServerSearchStart();

DECLSPEC_IMPORT VOID NTAPI Destroy();

/* Linker spelling at ordinal 2673: Destroy@CUpnpAVServerSearch; C spelling: Destroy. */

DECLSPEC_IMPORT VOID NTAPI UpnpAVServerSearchDoWork();

DECLSPEC_IMPORT VOID NTAPI UpnpAVServerSearchGetNextServer();

DECLSPEC_IMPORT VOID NTAPI XCustomBroadcastGamercardEvent();

DECLSPEC_IMPORT VOID NTAPI XamCustomGetCurrentActions();

DECLSPEC_IMPORT VOID NTAPI XamInstrumentationLogEvent();

DECLSPEC_IMPORT VOID NTAPI XamRegisterSMCNotification();

DECLSPEC_IMPORT VOID NTAPI XamIsScreenSaverActive();

DECLSPEC_IMPORT VOID NTAPI XamInstrumentationLogEventEx();

DECLSPEC_IMPORT VOID NTAPI XamInstrumentationGetSourceConfig();

DECLSPEC_IMPORT VOID NTAPI XamInstrumentationDebugConfig();

DECLSPEC_IMPORT VOID NTAPI CurlCreateCacheEntry();

DECLSPEC_IMPORT VOID NTAPI CurlOpenCacheEntry();

DECLSPEC_IMPORT VOID NTAPI CurlSetCacheEntryExpireTime();

DECLSPEC_IMPORT VOID NTAPI CurlReadCacheEntryHeaders();

DECLSPEC_IMPORT VOID NTAPI CurlReadCacheEntryContent();

DECLSPEC_IMPORT VOID NTAPI CurlWriteCacheEntryContent();

DECLSPEC_IMPORT VOID NTAPI CurlCloseCacheEntry();

DECLSPEC_IMPORT VOID NTAPI CurlEnumerateCacheEntry();

DECLSPEC_IMPORT VOID NTAPI CurlWipeBackingFiles();

DECLSPEC_IMPORT VOID NTAPI CurlBindFunctionTable();

DECLSPEC_IMPORT VOID NTAPI CurlOpenTitleBackingFile();

DECLSPEC_IMPORT VOID NTAPI XamUserIsPartialProfile();

DECLSPEC_IMPORT VOID NTAPI XamLocateTitle();

DECLSPEC_IMPORT VOID NTAPI XamProfileGetLocalTitleCount();

DECLSPEC_IMPORT VOID NTAPI XamContentRemoveCacheDevice();

DECLSPEC_IMPORT VOID NTAPI XamContentAddCacheDevice();

DECLSPEC_IMPORT VOID NTAPI XamSetSecurityViolationDetected();

DECLSPEC_IMPORT VOID NTAPI XamIsSecurityViolationDetected();

DECLSPEC_IMPORT VOID NTAPI XamIsAnySecurityViolationDetected();

DECLSPEC_IMPORT VOID NTAPI XamGetSecurityViolationsDetected();

DECLSPEC_IMPORT VOID NTAPI XamActivateCounterMeasure();

DECLSPEC_IMPORT VOID NTAPI XamDeactivateCounterMeasure();

DECLSPEC_IMPORT VOID NTAPI XamIsCounterMeasureActivated();

DECLSPEC_IMPORT VOID NTAPI XamGetActiveCounterMeasures();

DECLSPEC_IMPORT VOID NTAPI XamPmdIdentify();

DECLSPEC_IMPORT VOID NTAPI XamPmdSendCommand();

DECLSPEC_IMPORT VOID NTAPI XamPmdReadReport();

DECLSPEC_IMPORT VOID NTAPI XamPartyCreate();

DECLSPEC_IMPORT VOID NTAPI XamPartyLeave();

DECLSPEC_IMPORT VOID NTAPI XamPartySendInviteDeprecated();

DECLSPEC_IMPORT
ULONG
NTAPI
XamPartyGetUserList(
    ULONG player_count,
    ULONG *party_list
    );

DECLSPEC_IMPORT
ULONG
NTAPI
XamPartySendGameInvites(
    ULONG r3,
    ULONG r4,
    ULONG r5
    );

DECLSPEC_IMPORT VOID NTAPI XamPartyJoin();

DECLSPEC_IMPORT VOID NTAPI XamPartyKickUser();

DECLSPEC_IMPORT VOID NTAPI XamPartyAddLocalUsers();

DECLSPEC_IMPORT VOID NTAPI XamConvertEmoticons();

DECLSPEC_IMPORT VOID NTAPI XamGetLocaleTimeFormat();

DECLSPEC_IMPORT VOID NTAPI XamPartyRemoveLocalUsers();

DECLSPEC_IMPORT VOID NTAPI XamPartyGetUserListInternal();

DECLSPEC_IMPORT VOID NTAPI XamPartySetJoinable();

DECLSPEC_IMPORT VOID NTAPI XamPartyGetJoinable();

DECLSPEC_IMPORT VOID NTAPI XamPartyGetInfo();

DECLSPEC_IMPORT
ULONG
NTAPI
XamPartySetCustomData(
    ULONG r3,
    ULONG r4,
    ULONG r5
    );

DECLSPEC_IMPORT VOID NTAPI XamPartySetConnectivityGraph();

DECLSPEC_IMPORT VOID NTAPI XamPartyGetRoutingTable();

DECLSPEC_IMPORT VOID NTAPI XamPartyAutomationInprocCall();

DECLSPEC_IMPORT VOID NTAPI XamPartyGetState();

DECLSPEC_IMPORT
ULONG
NTAPI
XamPartyGetBandwidth(
    ULONG r3,
    ULONG r4
    );

DECLSPEC_IMPORT VOID NTAPI XamPartyGetNetworkCounters();

DECLSPEC_IMPORT VOID NTAPI XamShowQuickLaunchUI();

DECLSPEC_IMPORT VOID NTAPI XamPartyIsCoordinator();

DECLSPEC_IMPORT VOID NTAPI XamPartyGetFormation();

DECLSPEC_IMPORT VOID NTAPI XamPartySendInvite();

DECLSPEC_IMPORT VOID NTAPI XamPartySetTestDelay();

DECLSPEC_IMPORT VOID NTAPI XamPartyOverrideNatType();

DECLSPEC_IMPORT VOID NTAPI XamPartyGetAccessLevel();

DECLSPEC_IMPORT VOID NTAPI XamPartySetTestFlags();

DECLSPEC_IMPORT
ULONG
NTAPI
XamIsSystemExperienceTitleId(
    ULONG title_id
    );

DECLSPEC_IMPORT VOID NTAPI XamPartyJoinEx();

DECLSPEC_IMPORT VOID NTAPI XamPartyGetInfoEx();

DECLSPEC_IMPORT VOID NTAPI XamIsCurrentTitleDatacenterClient();

DECLSPEC_IMPORT VOID NTAPI XamTaskSetCancelSubTasks();

DECLSPEC_IMPORT VOID NTAPI XamTaskGetCompletionStatus();

DECLSPEC_IMPORT VOID NTAPI XamTaskCancelWaitAndCloseWaitTask();

DECLSPEC_IMPORT VOID NTAPI XamDataCenterLog();

DECLSPEC_IMPORT VOID NTAPI XamDataCenterGetDhcpOptionResponseHostnameAndPort();

DECLSPEC_IMPORT VOID NTAPI XamDataCenterLogEvent();

DECLSPEC_IMPORT VOID NTAPI XamDataCenterShowForceSignInMessage();

DECLSPEC_IMPORT VOID NTAPI XamWebInstrumentationCreateReport();

DECLSPEC_IMPORT VOID NTAPI XamWebInstrumentationSetUserVar();

DECLSPEC_IMPORT VOID NTAPI XamWebInstrumentationSetUserVarNoEscape();

DECLSPEC_IMPORT VOID NTAPI XamWebInstrumentationGetURL();

DECLSPEC_IMPORT VOID NTAPI XamWebInstrumentationSendReport();

DECLSPEC_IMPORT VOID NTAPI XamWebInstrumentationDestroyReport();

DECLSPEC_IMPORT VOID NTAPI XamWebInstrumentationCreateSampledReport();

DECLSPEC_IMPORT VOID NTAPI XampSetSamplingRandomValue();

DECLSPEC_IMPORT
VOID
NTAPI
XampWebInstrumentationSetProfileCounts(
    ULONG live_profiles,
    ULONG local_profiles,
    ULONG adult_profiles,
    ULONG child_profiles
    );

DECLSPEC_IMPORT VOID NTAPI XamWebInstrumentationGetURLEx();

DECLSPEC_IMPORT VOID NTAPI XampSetOmnitureCallbackFunction();

DECLSPEC_IMPORT VOID NTAPI XamShowQuickChatUIp();

DECLSPEC_IMPORT VOID NTAPI XamShowSocialPostUI();

DECLSPEC_IMPORT VOID NTAPI XamShowBeaconsUI();

DECLSPEC_IMPORT VOID NTAPI XamShowMarketplacePurchaseOrderUI();

DECLSPEC_IMPORT VOID NTAPI XamShowMarketplaceGetOrderReceipts();

DECLSPEC_IMPORT VOID NTAPI XamShowGenericOnlineAppUI();

DECLSPEC_IMPORT VOID NTAPI XamUserAllowedToPostToSocialNetwork();

DECLSPEC_IMPORT VOID NTAPI XamShowMarketplacePurchaseOrderUIEx();

DECLSPEC_IMPORT VOID NTAPI DebugXamShowMessageBoxUI_Wait();

DECLSPEC_IMPORT
ULONG
NTAPI
XamSetCountry(
    ULONG country
    );

DECLSPEC_IMPORT VOID NTAPI XamIsCurrentTitleDatacenterDash();

DECLSPEC_IMPORT VOID NTAPI XamLoaderRebootToServerDash();

DECLSPEC_IMPORT VOID NTAPI XamIsDataCenterMode();

DECLSPEC_IMPORT VOID NTAPI XamUserGetXUIDForTFA();

DECLSPEC_IMPORT VOID NTAPI XamVerifyXSignerSignature();

#ifdef __cplusplus
}
#endif

#endif /* _NXEDK_XAM_H_ */
