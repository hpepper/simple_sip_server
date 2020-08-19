## 5 Structure of the Protocol
The layer above the transaction layer is called the transaction user
   (TU).  Each of the SIP entities, except the stateless proxy, is a
   transaction user.  When a TU wishes to send a request, it creates a
   client transaction instance and passes it the request along with the
   destination IP address, port, and transport to which to send the
   request.  A TU that creates a client transaction can also cancel it.
   When a client cancels a transaction, it requests that the server stop
   further processing, revert to the state that existed before the
   transaction was initiated, and generate a specific error response to
   that transaction.  This is done with a CANCEL request, which
   constitutes its own transaction, but references the transaction to be
   cancelled (Section 9).

#### Registrar

Since registrations play an important role in
   SIP, a UAS that handles a REGISTER is given the special name
   registrar.  Section 10 describes UAC and UAS core behavior for the
   REGISTER method.

#### dialog
A dialog is a
   peer-to-peer SIP relationship between two user agents that persists
   for some time.  The dialog facilitates sequencing of messages and
   proper routing of requests between the user agents.  The INVITE
   method is the only way defined in this specification to establish a
   dialog.  


## 6 Definitions

* Message: Data sent between SIP elements as part of the protocol.
  * SIP messages are either requests or responses.
* SIP Transaction: A SIP transaction occurs between a client and a server and comprises all messages from the first request sent from the client to the server up to a final (non-1xx) response sent from the server to the client.
* Transaction User (TU): The layer of protocol processing that resides above the transaction layer.  Transaction users include the UAC core, UAS core, and proxy core.

## 7 SIP Messages

* SIP is a text-based protocol and uses the UTF-8 charset (RFC 2279 [7]).
*  A SIP message is either a request from a client to a server, or a response from a server to a client.
* Both Request and Response messages use the basic format of RFC 2822 [3], even though the syntax differs in character set and syntax specifics.i  
  * see section 2.1 of RFC2822.
*  (SIP allows header fields that  would not be valid RFC 2822 header fields, for example.)
  * Both types of messages consist of
    * a start-line,
    * one or more header fields,
    * an empty line indicating the end of the header fields,
    * and an optional message-body.
    * generic-message  =  start-line
      * *message-header
      * CRLF
      * [ message-body ]
    * start-line       =  Request-Line / Status-Line
    * The start-line, each message-header line, and the empty line MUST be terminated by a carriage-return line-feed sequence (CRLF).
      *  Note that the empty line MUST be present even if the message-body is not.
    * Except for the above difference in character sets, much of SIP's message and header field syntax is identical to HTTP/1.1.
      * RFC 2616

For now, I'll use CR LF CR LF to indicatethe endofthe message,since it is the end of the header, and I don't think any OPS have a body.

# Tracking stuff

### grafana
* message size
* time in queue
* time in queue ready for process
* turn around time
* number of unfinished flows
* number of finished flows
* number of registered units

### jaeger
* ?