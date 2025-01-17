// Copyright (c) Microsoft Corporation
// SPDX-License-Identifier: MIT

#pragma once

#include "net_ebpf_ext.h"

// Callout and sublayer GUIDs

// 98849e0b-b07d-11ec-9a30-18602489beee
DEFINE_GUID(
    EBPF_HOOK_ALE_AUTH_CONNECT_V4_CALLOUT, 0x98849e0b, 0xb07d, 0x11ec, 0x9a, 0x30, 0x18, 0x60, 0x24, 0x89, 0xbe, 0xee);

// 98849e0c-b07d-11ec-9a30-18602489beee
DEFINE_GUID(
    EBPF_HOOK_ALE_AUTH_RECV_ACCEPT_V4_CALLOUT,
    0x98849e0c,
    0xb07d,
    0x11ec,
    0x9a,
    0x30,
    0x18,
    0x60,
    0x24,
    0x89,
    0xbe,
    0xee);

// 98849e0d-b07d-11ec-9a30-18602489beee
DEFINE_GUID(
    EBPF_HOOK_ALE_AUTH_CONNECT_V6_CALLOUT, 0x98849e0d, 0xb07d, 0x11ec, 0x9a, 0x30, 0x18, 0x60, 0x24, 0x89, 0xbe, 0xee);

// 98849e0e-b07d-11ec-9a30-18602489beee
DEFINE_GUID(
    EBPF_HOOK_ALE_AUTH_RECV_ACCEPT_V6_CALLOUT,
    0x98849e0e,
    0xb07d,
    0x11ec,
    0x9a,
    0x30,
    0x18,
    0x60,
    0x24,
    0x89,
    0xbe,
    0xee);

// 98849e0f-b07d-11ec-9a30-18602489beee
DEFINE_GUID(
    EBPF_HOOK_ALE_CONNECT_REDIRECT_V4_CALLOUT,
    0x98849e0f,
    0xb07d,
    0x11ec,
    0x9a,
    0x30,
    0x18,
    0x60,
    0x24,
    0x89,
    0xbe,
    0xee);

// 98849e10-b07d-11ec-9a30-18602489beee
DEFINE_GUID(
    EBPF_HOOK_ALE_CONNECT_REDIRECT_V6_CALLOUT,
    0x98849e10,
    0xb07d,
    0x11ec,
    0x9a,
    0x30,
    0x18,
    0x60,
    0x24,
    0x89,
    0xbe,
    0xee);

// 98849e11-b07d-11ec-9a30-18602489beee
DEFINE_GUID(
    EBPF_HOOK_ALE_CONNECT_REDIRECT_PROVIDER,
    0x98849e11,
    0xb07d,
    0x11ec,
    0x9a,
    0x30,
    0x18,
    0x60,
    0x24,
    0x89,
    0xbe,
    0xee);

// 98849e12-b07d-11ec-9a30-18602489beee
DEFINE_GUID(
    EBPF_HOOK_CGROUP_CONNECT_V4_SUBLAYER, 0x98849e12, 0xb07d, 0x11ec, 0x9a, 0x30, 0x18, 0x60, 0x24, 0x89, 0xbe, 0xee);

// 98849e13-b07d-11ec-9a30-18602489beee
DEFINE_GUID(
    EBPF_HOOK_CGROUP_CONNECT_V6_SUBLAYER, 0x98849e13, 0xb07d, 0x11ec, 0x9a, 0x30, 0x18, 0x60, 0x24, 0x89, 0xbe, 0xee);

/**
 * @brief WFP classifyFn callback for EBPF_HOOK_ALE_AUTH_RECV_ACCEPT_V4/6_CALLOUT.
 */
void
net_ebpf_extension_sock_addr_authorize_recv_accept_classify(
    _In_ const FWPS_INCOMING_VALUES* incoming_fixed_values,
    _In_ const FWPS_INCOMING_METADATA_VALUES* incoming_metadata_values,
    _Inout_opt_ void* layer_data,
    _In_opt_ const void* classify_context,
    _In_ const FWPS_FILTER* filter,
    uint64_t flow_context,
    _Inout_ FWPS_CLASSIFY_OUT* classify_output);

/**
 * @brief WFP classifyFn callback for EBPF_HOOK_ALE_AUTH_CONNECT_V4/6_CALLOUT
 */
void
net_ebpf_extension_sock_addr_authorize_connection_classify(
    _In_ const FWPS_INCOMING_VALUES* incoming_fixed_values,
    _In_ const FWPS_INCOMING_METADATA_VALUES* incoming_metadata_values,
    _Inout_opt_ void* layer_data,
    _In_opt_ const void* classify_context,
    _In_ const FWPS_FILTER* filter,
    uint64_t flow_context,
    _Inout_ FWPS_CLASSIFY_OUT* classify_output);

/**
 * @brief WFP classifyFn callback for EBPF_HOOK_ALE_CONNECT_REDIRECT_V4/6_CALLOUT
 */
void
net_ebpf_extension_sock_addr_redirect_connection_classify(
    _In_ const FWPS_INCOMING_VALUES* incoming_fixed_values,
    _In_ const FWPS_INCOMING_METADATA_VALUES* incoming_metadata_values,
    _Inout_opt_ void* layer_data,
    _In_opt_ const void* classify_context,
    _In_ const FWPS_FILTER* filter,
    uint64_t flow_context,
    _Inout_ FWPS_CLASSIFY_OUT* classify_output);

/**
 * @brief Unregister CGROUP_SOCK_ADDR NPI providers.
 *
 */
void
net_ebpf_ext_sock_addr_unregister_providers();

/**
 * @brief Register CGROUP_SOCK_ADDR NPI providers.
 *
 * @retval STATUS_SUCCESS Operation succeeded.
 * @retval STATUS_UNSUCCESSFUL Operation failed.
 */
NTSTATUS
net_ebpf_ext_sock_addr_register_providers();

NTSTATUS
net_ebpf_ext_connect_redirect_filter_change_notify(
    FWPS_CALLOUT_NOTIFY_TYPE callout_notification_type, _In_ const GUID* filter_key, _Inout_ FWPS_FILTER* filter);