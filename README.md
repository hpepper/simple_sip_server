# A simple SIP server for the cloud

## Introduction

### Purpose

### References

* <https://www.boost.org/doc/libs/1_62_0/more/getting_started/index.html>
* <https://tools.ietf.org/html/rfc3261>

### Overview

The sip server is a single thread looping server, meant to scale out under load.

# Deployment

## Build

### Building the server

cd src/server

# RFC3161

## 7

#### 7.3.1 Header Field Format

it is RECOMMENDED that header fields which are
   needed for proxy processing (Via, Route, Record-Route, Proxy-Require,
   Max-Forwards, and Proxy-Authorization, for example) appear towards
   the top of the message to facilitate rapid parsing.  The relative
   order of header field rows with the same field name is important.
   Multiple header field rows with the same field-name MAY be present in
   a message if and only if the entire field-value for that header field
   is defined as a comma-separated list (that is, if follows the grammar
   defined in Section 7.3).  It MUST be possible to combine the multiple
   header field rows into one "field-name: field-value" pair, without
   changing the semantics of the message, by appending each subsequent
   field-value to the first, each separated by a comma.  The exceptions
   to this rule are the WWW-Authenticate, Authorization, Proxy-
   Authenticate, and Proxy-Authorization header fields.

field-name: field-value *(;parameter-name=parameter-value)

When comparing header fields, field names are always case insensitive. 
  Unless otherwise stated in the definition of a particular header field, field values, parameter names, and parameter values are case-insensitive.
  Tokens are always case-insensitive.
  Unless specified otherwise, values expressed as quoted strings are case-sensitive.

#### 7.3.2 Header Field Classification

Some header fields only make sense in requests or responses. 
 These are called request header fields and response header fields, respectively.
 If a header field appears in a message not matching its category (such as a request header field in a response), it MUST be ignored.
 Section 20 defines the classification of each header field.

#### 7.3.3 Compact Form
 A compact
   form MAY be substituted for the longer form of a header field name at
   any time without changing the semantics of the message.


## 10

### 10.2 Constructing the REGISTER Request

 Except as noted, the construction of the REGISTER request and the
   behavior of clients sending a REGISTER request is identical to the
   general UAC behavior described in Section 8.1 and Section 17.1.

The following header fields, except Contact, MUST be included in a
   REGISTER request.
*  A Contact header field MAY be included:

See these in section 8.1.1.1. to 8.1.1.8

* Request-URI: The Request-URI names the domain of the location service for which the registration is meant
  * (for example, "sip:chicago.com").
  * The "userinfo" and "@" components of the SIP URI MUST NOT be present.
* To: The To header field contains the address of record whose registration is to be created, queried, or modified.
  * The To header field and the Request-URI field typically differ, as the former contains a user name. 
  * This address-of-record MUST be a SIP URI or SIPS URI.
  * (for example, "sip:carol@cube2214a.chicago.com")
* From: The value is the same as the To header field unless the request is a third-  party registration.
* Call-ID: All registrations from a UAC SHOULD use the same Call-ID header field value for registrations sent to a particular registrar.
* CSeq: The CSeq value guarantees proper ordering of REGISTER requests.
  * A UA MUST increment the CSeq value by one for each REGISTER request with the same Call-ID.
  * See: 
    * 8.1.1.5 CSeq
    * 12.2.1.1 Generating the Request
* Contact: REGISTER requests MAY contain a Contact header field with zero or more values containing address bindings.
* expires: The "expires" parameter indicates how long the UA would like the binding to be valid.
  * The value is a number indicating seconds.
  * If this parameter is not provided, the value of the Expires header field is used instead.
    * Implementations MAY treat values larger than 2**32-1 (4294967295 seconds or 136 years) as equivalent to 2**32-1.
  * Malformed values SHOULD be treated as equivalent to 3600.
  * There are two ways in which a client can suggest an expiration
   interval for a binding: through an Expires header field or an
   "expires" Contact header parameter.

UAs MUST NOT send a new registration (that is, containing new Contact
   header field values, as opposed to a retransmission) until they have
   received a final response from the registrar for the previous one or
   the previous REGISTER request has timed out.

The 2xx response to the REGISTER
   request will contain, in a Contact header field, a complete list of
   bindings that have been registered for this address-of-record at this
   registrar.
If the address-of-record in the To header field of a REGISTER request
   is a SIPS URI, then any Contact header field values in the request
   SHOULD also be SIPS URIs

#### 10.2.2 Removing Bindings

   Registrations are soft state and expire unless refreshed, but can
   also be explicitly removed.  A client can attempt to influence the
   expiration interval selected by the registrar as described in Section
   10.2.1.  A UA requests the immediate removal of a binding by
   specifying an expiration interval of "0" for that contact address in
   a REGISTER request.

#### 10.2.3 Fetching Bindings

A success response to any REGISTER request contains the complete list
   of existing bindings, regardless of whether the request contained a
   Contact header field.  If no Contact header field is present in a
   REGISTER request, the list of bindings is left unchanged.

#### 10.2.4 Refreshing Bindings

   Each UA is responsible for refreshing the bindings that it has
   previously established.

#### 10.2.6 Discovering a Registrar

   UAs can use three ways to determine the address to which to send
   registrations:  by configuration, using the address-of-record, and
   multicast.


### 10.3

 * Registrars MUST ignore the Record-Route header field if it is included in a REGISTER request.
* Registrars MUST NOT include a Record-Route header field in any response to a REGISTER request.
* REGISTER requests MUST be processed by a registrar in the order that they are received.
* REGISTER requests MUST also be processed atomically, meaning that a particular REGISTER request is either processed completely or not at all.
* Each REGISTER message MUST be processed independently of any other registration or binding changes.


#### 19.1.1 SIP and SIPS URI Components

 sip:user:password@host:port;uri-parameters?headers

 See RFC 2396  3. URI Syntactic Components - for base syntactic components

 ## 25  Augmented BNF for the SIP Protocol
 