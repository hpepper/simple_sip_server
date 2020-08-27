## 8.2 UAS Behavior

### 8.2.2 Header Inspection

*  If a UAS does not understand a header field in a request (that is, the header field is not defined in this specification or in any  supported extension), the server MUST ignore that header field and continue processing the message.
* A UAS SHOULD ignore any malformed header fields that are not necessary for processing requests.

#### 8.2.2.1 To and Request-URI

* if they do not recognize the (to) URI scheme: If, on the other hand, the UAS decides to reject the request, it SHOULD generate a response with a 403 (Forbidden)
* If the Request-URI uses a scheme not supported by the UAS, it SHOULD reject the request with a 416 (Unsupported URI Scheme) response.
*  If the Request-URI does not identify an address that the UAS is willing to accept requests for, it SHOULD reject the request with a 404 (Not Found) response.

#### 8.2.2.2 Merged Requests

* If the request has no tag in the To header field, the UAS core MUST check the request against ongoing transactions.
* If the From tag, Call-ID, and CSeq exactly match those associated with an ongoing transaction, but the request does not match that transaction (based on the matching rules in Section 17.2.3), the UAS core SHOULD generate a 482 (Loop Detected) response


#### 8.2.6.2 Headers and Tags

If a request contained a To tag in the request, the To header field
   in the response MUST equal that of the request.  However, if the To
   header field in the request did not contain a tag, the URI in the To
   header field in the response MUST equal the URI in the To header
   field; additionally, the UAS MUST add a tag to the To header field in
   the response , in
   which a tag MAY be present).  This serves to identify the UAS that is
   responding, possibly resulting in a component of a dialog ID.  The
   same tag MUST be used for all responses to that request, both final
   and provisional (again excepting the 100 (Trying)).  Procedures for
   the generation of tags are defined in Section 19.3.

### 8.2.7 Stateless UAS Behavior

The stateless UAS role is needed primarily to handle unauthenticated
   requests for which a challenge response is issued.  If
   unauthenticated requests were handled statefully, then malicious
   floods of unauthenticated requests could create massive amounts of transaction state that might slow or completely halt call processing
   in a UAS, effectively creating a denial of service condition; for
   more information see Section 26.1.5.

## 17.2 Server Transaction

### 17.2.2 Non-INVITE Server Transaction



# 12 Dialogs
(This should contain information on how to if the message is part of a dialog or not)
