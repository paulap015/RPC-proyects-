/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "gestionUsuarios.h"

bool_t
xdr_nodo_usuario (XDR *xdrs, nodo_usuario *objp)
{
	register int32_t *buf;

	int i;

	if (xdrs->x_op == XDR_ENCODE) {
		 if (!xdr_vector (xdrs, (char *)objp->first_name, MAXNOM,
			sizeof (char), (xdrproc_t) xdr_char))
			 return FALSE;
		 if (!xdr_vector (xdrs, (char *)objp->second_name, MAXNOM,
			sizeof (char), (xdrproc_t) xdr_char))
			 return FALSE;
		 if (!xdr_vector (xdrs, (char *)objp->first_last_name, MAXNOM,
			sizeof (char), (xdrproc_t) xdr_char))
			 return FALSE;
		 if (!xdr_vector (xdrs, (char *)objp->second_last_name, MAXNOM,
			sizeof (char), (xdrproc_t) xdr_char))
			 return FALSE;
		buf = XDR_INLINE (xdrs, 4 * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->dia_nacimiento))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->mes_nacimiento))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->anio_nacimiento))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->cedula))
				 return FALSE;

		} else {
		IXDR_PUT_LONG(buf, objp->dia_nacimiento);
		IXDR_PUT_LONG(buf, objp->mes_nacimiento);
		IXDR_PUT_LONG(buf, objp->anio_nacimiento);
		IXDR_PUT_LONG(buf, objp->cedula);
		}
		 if (!xdr_vector (xdrs, (char *)objp->username, MAXNOM,
			sizeof (char), (xdrproc_t) xdr_char))
			 return FALSE;
		 if (!xdr_vector (xdrs, (char *)objp->password, MAXNOM,
			sizeof (char), (xdrproc_t) xdr_char))
			 return FALSE;
		 if (!xdr_vector (xdrs, (char *)objp->rfc, MAXNOM,
			sizeof (char), (xdrproc_t) xdr_char))
			 return FALSE;
		return TRUE;
	} else if (xdrs->x_op == XDR_DECODE) {
		 if (!xdr_vector (xdrs, (char *)objp->first_name, MAXNOM,
			sizeof (char), (xdrproc_t) xdr_char))
			 return FALSE;
		 if (!xdr_vector (xdrs, (char *)objp->second_name, MAXNOM,
			sizeof (char), (xdrproc_t) xdr_char))
			 return FALSE;
		 if (!xdr_vector (xdrs, (char *)objp->first_last_name, MAXNOM,
			sizeof (char), (xdrproc_t) xdr_char))
			 return FALSE;
		 if (!xdr_vector (xdrs, (char *)objp->second_last_name, MAXNOM,
			sizeof (char), (xdrproc_t) xdr_char))
			 return FALSE;
		buf = XDR_INLINE (xdrs, 4 * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->dia_nacimiento))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->mes_nacimiento))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->anio_nacimiento))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->cedula))
				 return FALSE;

		} else {
		objp->dia_nacimiento = IXDR_GET_LONG(buf);
		objp->mes_nacimiento = IXDR_GET_LONG(buf);
		objp->anio_nacimiento = IXDR_GET_LONG(buf);
		objp->cedula = IXDR_GET_LONG(buf);
		}
		 if (!xdr_vector (xdrs, (char *)objp->username, MAXNOM,
			sizeof (char), (xdrproc_t) xdr_char))
			 return FALSE;
		 if (!xdr_vector (xdrs, (char *)objp->password, MAXNOM,
			sizeof (char), (xdrproc_t) xdr_char))
			 return FALSE;
		 if (!xdr_vector (xdrs, (char *)objp->rfc, MAXNOM,
			sizeof (char), (xdrproc_t) xdr_char))
			 return FALSE;
	 return TRUE;
	}

	 if (!xdr_vector (xdrs, (char *)objp->first_name, MAXNOM,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->second_name, MAXNOM,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->first_last_name, MAXNOM,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->second_last_name, MAXNOM,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->dia_nacimiento))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->mes_nacimiento))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->anio_nacimiento))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->cedula))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->username, MAXNOM,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->password, MAXNOM,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->rfc, MAXNOM,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	return TRUE;
}