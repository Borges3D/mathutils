
#include "mathutils.h"
#include <float.h>
#include <string.h>

#ifndef MU_EPSILON
#define MU_EPSILON DBL_MIN
#endif

#define MU_DEBUG 0

#if MU_DEBUG
#	define EMIT_WARNING( file, line, message ) std::cerr << "warning: " << file << ":" << line << " - " << message << std::endl; 
#else
#	define EMIT_WARNING( file, line, message )
#endif

	namespace mu {
	///-----------------------------global utility functions--------------

	double	smallest( double a, double b ){
		return( a < b ? a : b );
	}

	double	largest( double a, double b ){
		return( a > b ? a : b );
	}

	double clamp( double v, double min, double max ){
		if( v < min ){
			v = min;
		}
		else if( v > max ){
			v = max;
		}
		return( v );
	}

	double clampMin( double x, double min ){
		return( ( x < min ) ? min : x );
	}

	double clampMax( double x, double max ){
		return( ( x > max ) ? max : x );
	}

	Vec2	clamp( const Vec2 & v, double min, double max ){
		Vec2 vc = v;
		if( vc[ 0 ] < min ){
			vc[ 0 ] = min;
		}
		if( vc[ 1 ] < min ){
			vc[ 1 ] = min;
		}
		if( vc[ 0 ] > max ){
			vc[ 0 ] = max;
		}
		if( vc[ 1 ] > max ){
			vc[ 1 ] = max;
		}
		return( vc );
	}

	Vec2	clampMax( const Vec2 & v, double max ){
		Vec2 vc = v;
		if( vc[ 0 ] > max ){
			vc[ 0 ] = max;
		}
		if( vc[ 1 ] > max ){
			vc[ 1 ] = max;
		}
		return( vc );
	}

	Vec2	clampMin( const Vec2 & v, double min ){
		Vec2 vc = v;
		if( vc[ 0 ] < min ){
			vc[ 0 ] = min;
		}
		if( vc[ 1 ] < min ){
			vc[ 1 ] = min;
		}
		return( vc );
	}

	Vec3	clamp( const Vec3 & v, double min, double max ){
		Vec3 vc = v;
		if( vc[ 0 ] < min ){
			vc[ 0 ] = min;
		}
		if( vc[ 1 ] < min ){
			vc[ 1 ] = min;
		}
		if( vc[ 2 ] < min ){
			vc[ 2 ] = min;
		}
		if( vc[ 0 ] > max ){
			vc[ 0 ] = max;
		}
		if( vc[ 1 ] > max ){
			vc[ 1 ] = max;
		}
		if( vc[ 2 ] > max ){
			vc[ 2 ] = max;
		}
		return( vc );
	}

	Vec3	clampMax( const Vec3 & v, double max ){
		Vec3 vc = v;
		if( vc[ 0 ] > max ){
			vc[ 0 ] = max;
		}
		if( vc[ 1 ] > max ){
			vc[ 1 ] = max;
		}
		if( vc[ 2 ] > max ){
			vc[ 2 ] = max;
		}
		return( vc );
	}

	Vec3	clampMin( const Vec3 & v, double min ){
		Vec3 vc = v;
		if( vc[ 0 ] < min ){
			vc[ 0 ] = min;
		}
		if( vc[ 1 ] < min ){
			vc[ 1 ] = min;
		}
		if( vc[ 2 ] < min ){
			vc[ 2 ] = min;
		}
		return( vc );
	}

	Vec4	clamp( const Vec4 & v, double min, double max ){
		Vec4 vc = v;
		if( vc[ 0 ] < min ){
			vc[ 0 ] = min;
		}
		if( vc[ 1 ] < min ){
			vc[ 1 ] = min;
		}
		if( vc[ 2 ] < min ){
			vc[ 2 ] = min;
		}
		if( vc[ 3 ] < min ){
			vc[ 3 ] = min;
		}
		if( vc[ 0 ] > max ){
			vc[ 0 ] = max;
		}
		if( vc[ 1 ] > max ){
			vc[ 1 ] = max;
		}
		if( vc[ 2 ] > max ){
			vc[ 2 ] = max;
		}
		if( vc[ 3 ] > max ){
			vc[ 3 ] = max;
		}
		return( vc );
	}

	Vec4	clampMax( const Vec4 & v, double max ){
		Vec4 vc = v;
		if( vc[ 0 ] > max ){
			vc[ 0 ] = max;
		}
		if( vc[ 1 ] > max ){
			vc[ 1 ] = max;
		}
		if( vc[ 2 ] > max ){
			vc[ 2 ] = max;
		}
		if( vc[ 3 ] > max ){
			vc[ 3 ] = max;
		}
		return( vc );
	}

	Vec4	clampMin( const Vec4 & v, double min ){
		Vec4 vc = v;
		if( vc[ 0 ] < min ){
			vc[ 0 ] = min;
		}
		if( vc[ 1 ] < min ){
			vc[ 1 ] = min;
		}
		if( vc[ 2 ] < min ){
			vc[ 2 ] = min;
		}
		if( vc[ 3 ] < min ){
			vc[ 3 ] = min;
		}
		return( vc );
	}

	bool equals( double a, double b, double epsilon ){
	  return( fabs( a - b ) < epsilon );
	}

	bool equals( const Vec2 & a, const Vec2 & b, double epsilon ){
		return( a.equals( b, epsilon ) );
	}
		
	bool equals( const Vec3 & a, const Vec3 & b, double epsilon ){
		return( a.equals( b, epsilon ) );
	}
		
	bool equals( const Vec4 & a, const Vec4 & b, double epsilon ){
		return( a.equals( b, epsilon ) );
	}


	double sgn( double v ){
		return( v < 0.0 ? -1.0 : 1.0 );
	}

	Vec2 sgn( const Vec2 & v ){
		Vec2 vs = v.sgn();
		return( vs );
	}
		
	Vec3 sgn( const Vec3 & v ){
		Vec3 vs = v.sgn();
		return( vs );
	}
		
	Vec4 sgn( const Vec4 & v ){
		Vec4 vs = v.sgn();
		return( vs );
	}
		
	double toRadians( double degrees ){
		return( ( degrees / 180.0 ) * M_PI );
	}
		
	double toDegrees( double radians ){
		return( 180.0 * ( radians / M_PI ) );
	}

	Vec2 toRadians( const Vec2 & degrees ){
		Vec2 v;
		v[ 0 ] = toRadians( degrees[ 0 ] );
		v[ 1 ] = toRadians( degrees[ 1 ] );
		return( v );
	}
		
	Vec2 toDegrees( const Vec2 & radians ){
		Vec2 v;
		v[ 0 ] = toDegrees( radians[ 0 ] );
		v[ 1 ] = toDegrees( radians[ 1 ] );
		return( v );
	}

	Vec3 toRadians( const Vec3 & degrees ){
		Vec3 v;
		v[ 0 ] = toRadians( degrees[ 0 ] );
		v[ 1 ] = toRadians( degrees[ 1 ] );
		v[ 2 ] = toRadians( degrees[ 2 ] );
		return( v );
	}
		
	Vec3 toDegrees( const Vec3 & radians ){
		Vec3 v;
		v[ 0 ] = toDegrees( radians[ 0 ] );
		v[ 1 ] = toDegrees( radians[ 1 ] );
		v[ 2 ] = toDegrees( radians[ 2 ] );
		return( v );
	}

	Vec4 toRadians( const Vec4 & degrees ){
		Vec4 v;
		v[ 0 ] = toRadians( degrees[ 0 ] );
		v[ 1 ] = toRadians( degrees[ 1 ] );
		v[ 2 ] = toRadians( degrees[ 2 ] );
		v[ 3 ] = toRadians( degrees[ 3 ] );
		return( v );
	}
		
	Vec4 toDegrees( const Vec4 & radians ){
		Vec4 v;
		v[ 0 ] = toDegrees( radians[ 0 ] );
		v[ 1 ] = toDegrees( radians[ 1 ] );
		v[ 2 ] = toDegrees( radians[ 2 ] );
		v[ 3 ] = toDegrees( radians[ 3 ] );
		return( v );
	}
	  
	double distance( const Vec2 & v1, const Vec2 & v2 ){
		return( length( v2 - v1 ) );
	}

	double distance( const Vec3 & v1, const Vec3 & v2 ){
		return( length( v2 - v1 ) );
	}

	double distance( const Vec4 & v1, const Vec4 & v2 ){
		return( length( v2 - v1 ) );
	}
		
	double distance2( const Vec2 & v1, const Vec2 & v2 ){
		return( length2( v2 - v1 ) );
	}

	double distance2( const Vec3 & v1, const Vec3 & v2 ){
		return( length2( v2 - v1 ) );
	}

	double distance2( const Vec4 & v1, const Vec4 & v2 ){
		return( length2( v2 - v1 ) );
	}
		
	double length( const Vec2 & v ){
		return( v.len() );
	}
		
	double length( const Vec3 & v ){
		return( v.len() );
	}
		
	double length( const Vec4 & v ){
		return( v.len() );
	}
		
	double length2( const Vec2 & v ){
		return( v.hyp() );
	}
		
	double length2( const Vec3 & v ){
		return( v.hyp() );
	}
		
	double length2( const Vec4 & v ){
		return( v.hyp() );
	}
		
	Vec2 normalize( const Vec2 & v ){
		return( v.normalized() );
	}
		
	Vec3 normalize( const Vec3 & v ){
		return( v.normalized() );
	}
		
	Vec4 normalize( const Vec4 & v ){
		return( v.normalized() );
	}
		
	Quat normalize( const Quat & v ){
		return( v.normalized() );
	}
		
	double dot( const Vec2 & v1, const Vec2 & v2 ){
		return( v1.dot( v2 ) );
	}
		
	double dot( const Vec3 & v1, const Vec3 & v2 ){
		return( v1.dot( v2 ) );
	}
		
	double dot( const Vec4 & v1, const Vec4 & v2 ){
		return( v1.dot( v2 ) );
	}
		
	double cross( const Vec2 & v1, const Vec2 & v2 ){
		return( dot( v1.cross(), v2 ) );
	}

	Vec3 cross( const Vec3 & v1, const Vec3 & v2 ){
		return( v1.cross( v2 ) );
	}
		
	double mix( double f1, double f2, double f ){
		return( f2 * f + f1 * ( 1.0 - f ) );
	}
		
	Vec2 mix( const Vec2 & v1, const Vec2 & v2, double f ){
		return( v2 * f + v1 * ( 1.0 - f ) );
	}
		
	Vec3 mix( const Vec3 & v1, const Vec3 & v2, double f ){
		return( v2 * f + v1 * ( 1.0 - f ) );
	}
		
	Vec4 mix( const Vec4 & v1, const Vec4 & v2, double f ){
		return( v2 * f + v1 * ( 1.0 - f ) );
	}
				
	Quat mix( const Quat & q1, const Quat & q2, double f ){
		return( Quat::mix( q1, q2, f ) );
	}
				
	Mat2 mix( const Mat2 & m1, const Mat2 & m2, double f ){
		Mat2 m;
		int i = 0;
		for( i = 0; i < 4; i++ ){
			m[i] = f * m2[i] + ( 1.0 - f ) * m1[i];
		}
		return( m );
	}
		
	Mat3 mix( const Mat3 & m1, const Mat3 & m2, double f ){
		Mat3 m;
		int i = 0;
		for( i = 0; i < 9; i++ ){
			m[i] = f * m2[i] + ( 1.0 - f ) * m1[i];
		}
		return( m );
	}
		
	Mat4 mix( const Mat4 & m1, const Mat4 & m2, double f ){
		Mat4 m;
		int i = 0;
		for( i = 0; i < 16; i++ ){
			m[i] = f * m2[i] + ( 1.0 - f ) * m1[i];
		}
		return( m );
	}

	Vec2 operator * ( double s, const Vec2 & v ){
		return( v * s );
	}
		
	Vec3 operator * ( double s, const Vec3 & v ){
		return( v * s );
	}
		
	Vec4 operator * ( double s, const Vec4 & v ){
		return( v * s );
	}

	std::istream & operator >> ( std::istream & s, Vec2 & v ){
		s >> v[ 0 ] >> v[ 1 ];
		return s;
	}

	std::istream & operator >> ( std::istream & s, Vec3 & v ){
		s >> v[ 0 ] >> v[ 1 ] >> v[ 2 ];
		return s;
	}

	std::istream & operator >> ( std::istream & s, Vec4 & v ){
		s >> v[ 0 ] >> v[ 1 ] >> v[ 2 ] >> v[ 3 ];
		return s;
	}

	std::istream & operator >> ( std::istream & s, Quat & v ){
		s >> v[ 0 ] >> v[ 1 ] >> v[ 2 ] >> v[ 3 ];
		return s;
	}

	std::istream & operator >> ( std::istream & s, Mat2 & v ){
		s >> v[ 0 ] >> v[ 1 ] >> v[ 2 ] >> v[ 3 ] >> v[ 4 ];
		return s;
	}

	std::istream & operator >> ( std::istream & s, Mat3 & v ){
		s >> v[ 0 ] >> v[ 1 ] >> v[ 2 ];
		s >> v[ 3 ] >> v[ 4 ] >> v[ 5 ];
		s >> v[ 6 ] >> v[ 7 ] >> v[ 8 ];
		return s;
	}

	std::istream & operator >> ( std::istream & s, Mat4 & v ){
		s >> v[ 0 ] >> v[ 1 ] >> v[ 2 ] >> v[ 3 ];
		s >> v[ 4 ] >> v[ 5 ] >> v[ 6 ] >> v[ 7 ];
		s >> v[ 8 ] >> v[ 9 ] >> v[ 10 ] >> v[ 11 ];
		s >> v[ 12 ] >> v[ 13 ] >> v[ 14 ] >> v[ 15 ];
		return s;
	}

	std::ostream & operator << ( std::ostream & s, const Vec2 & v ) { 
		static char txt[256];
		sprintf( txt, "%g %g", v[ 0 ], v[ 1 ] );
		s << txt;
		return s;
	}

	std::ostream & operator << ( std::ostream & s, const Vec3 & v ) { 
		static char txt[256];
		sprintf( txt, "%g %g %g", v[ 0 ], v[ 1 ], v[ 2 ] );
		s << txt;
		return s;
	}

	std::ostream & operator << ( std::ostream & s, const Vec4 & v ) { 
		static char txt[256];
		sprintf( txt, "%g %g %g %g", v[ 0 ], v[ 1 ], v[ 2 ], v[ 3 ] );
		s << txt;
		return s;
	}

	std::ostream & operator << ( std::ostream & s, const Quat & v ) { 
		static char txt[256];
		sprintf( txt, "%g %g %g %g", v[ 0 ], v[ 1 ], v[ 2 ], v[ 3 ] );
		s << txt;
		return s;
	}

	std::ostream & operator << ( std::ostream & s, const Mat2 & v ) { 
		static char txt[256];
		sprintf( txt, "%g %g\n%g %g", \
			v[ 0 ], v[ 1 ], \
			v[ 2 ], v[ 3 ] );
		s << txt;
		return s;
	}

	std::ostream & operator << ( std::ostream & s, const Mat3 & v ) { 
		static char txt[256];
		sprintf( txt, "%g %g %g\n%g %g %g\n%g %g %g", \
			v[ 0 ], v[ 1 ], v[ 2 ], \
			v[ 3 ], v[ 4 ], v[ 5 ], \
			v[ 6 ], v[ 7 ], v[ 8 ] );
		s << txt;
		return s;
	}

	std::ostream & operator << ( std::ostream & s, const Mat4 & v ) { 
		static char txt[256];
		sprintf( txt, "%g %g %g %g\n%g %g %g %g\n%g %g %g %g\n%g %g %g %g", \
			v[ 0 ], v[ 1 ], v[ 2 ], v[ 3 ], \
			v[ 4 ], v[ 5 ], v[ 6 ], v[ 7 ], \
			v[ 8 ], v[ 9 ], v[ 10 ], v[ 11 ], \
			v[ 12 ], v[ 13 ], v[ 14 ], v[ 15 ] );
		s << txt;
		return s;
	}

	///--------------------------------Vec2-------------------------------

	Vec2::Vec2( double v0, double v1 ){
		m_v[ 0 ] = v0;
		m_v[ 1 ] = v1;
	}

	Vec2::Vec2( double xy ){
		m_v[ 0 ] = xy;
		m_v[ 1 ] = xy;
	}

	Vec2::Vec2( const double * v ){
		memcpy( m_v, v, 2 * sizeof( double ) );
	}

	bool Vec2::operator < ( const double v ) const {
		return( hyp() < v * v);
	}

	bool Vec2::operator < ( const Vec2 & v ) const {
		return( hyp() < v.hyp() );
	}

	bool Vec2::operator < ( const Vec3 & v ) const {
		return( hyp() < v.hyp() );
	}

	bool Vec2::operator < ( const Vec4 & v ) const {
		return( hyp() < v.hyp() );
	}

	Vec2 Vec2::operator - () const {
		return( Vec2( -m_v[ 0 ], -m_v[ 1 ] ) );
	}

	Vec2 Vec2::operator + ( const Vec2 & b ) const {
		Vec2 a;
		a[ 0 ] = m_v[ 0 ] + b[ 0 ];
		a[ 1 ] = m_v[ 1 ] + b[ 1 ];
		return( a );
	}

	Vec2 Vec2::operator - ( const Vec2 & b ) const {
		Vec2 a;
		a[ 0 ] = m_v[ 0 ] - b[ 0 ];
		a[ 1 ] = m_v[ 1 ] - b[ 1 ];
		return( a );
	}

	Vec2 Vec2::operator * ( double b ) const {
		Vec2 a;
		a[ 0 ] = m_v[ 0 ] * b;
		a[ 1 ] = m_v[ 1 ] * b;
		return( a );
	}

	Vec2 Vec2::operator * ( const Vec2 & b ) const {
		Vec2 a;
		a[ 0 ] = m_v[ 0 ] * b[ 0 ];
		a[ 1 ] = m_v[ 1 ] * b[ 1 ];
		return( a );
	}

	Vec2 Vec2::operator / ( const Vec2 & b ) const {
		Vec2 a;
		a[ 0 ] = m_v[ 0 ] / b[ 0 ];
		a[ 1 ] = m_v[ 1 ] / b[ 1 ];
		return( a );
	}

	Vec2 Vec2::operator / ( double b ) const {
		Vec2 a;
		a[ 0 ] = m_v[ 0 ] / b;
		a[ 1 ] = m_v[ 1 ] / b;
		return( a );
	}

	Vec2 & Vec2::operator += ( const Vec2 & b ){
		return( * this = * this + b );
	}

	Vec2 & Vec2::operator -= ( const Vec2 & b ){
		return( * this = * this - b );
	}

	Vec2 & Vec2::operator *= ( double b ){
		return( * this = * this * b );
	}

	Vec2 & Vec2::operator *= ( const Vec2 & b ){
		return( * this = * this * b );
	}

	Vec2 & Vec2::operator /= ( double b ){
		return( * this = * this / b );
	}

	Vec2 & Vec2::operator /= ( const Vec2 & b ){
		return( * this = * this / b );
	}

	double &	Vec2::x( void ){
		return( m_v[ 0 ] );
	}

	const double & Vec2::x( void ) const {
		return( m_v[ 0 ] );
	}

	double &	Vec2::y( void ){
		return( m_v[ 1 ] );
	}

	const double & Vec2::y( void ) const {
		return( m_v[ 1 ] );
	}

	double & Vec2::operator [] ( int index ) {
		return( m_v[ index ] );
	}

	const double & Vec2::operator [] ( const int index ) const {
		return( m_v[ index ] );
	}

	bool Vec2::operator == ( const Vec2 & b ) const {
		return( equals( b ) );
	}

	bool Vec2::operator != ( const Vec2 & b ) const {
		return( ! equals( b ) );
	}

	Vec2::operator 	const double * ( void ) const{
		return( m_v );
	}

	Vec2::operator 	double * ( void ){
		return( m_v );
	}

	double Vec2::hyp( void ) const {
		return( m_v[ 0 ] * m_v[ 0 ] + m_v[ 1 ] * m_v[ 1 ] );
	}

	Vec2 Vec2::perp( void ) const {
		return( Vec2( -m_v[ 1 ], m_v[ 0 ] ) );
	}

	double Vec2::len( void ) const {
		double h = hyp();
		if( h < MU_EPSILON ){
			return( 0.0 );
		}
		return( sqrt( h ) );
	}

	void Vec2::rotate( double radians ){
		double x = m_v[ 0 ];
		double y = m_v[ 1 ];
		double cr = cosf( radians );
		double sr = sinf( radians );
		m_v[ 0 ] = x * cr - y * sr;
		m_v[ 1 ] = x * sr + y * cr;
	}

	void Vec2::normalize( void ){
		double l = len();
		m_v[ 0 ] /= l;
		m_v[ 1 ] /= l;
	}

	Vec2 Vec2::normalized( void ) const {
		double l = len();
		return( Vec2( m_v[ 0 ] / l, m_v[ 1 ] / l ) );
	}

	double Vec2::dot( const Vec2 & b ) const {
		return( m_v[ 0 ] * b[ 0 ] + m_v[ 1 ] * b[ 1 ] );
	}

	Vec2 Vec2::abs( void ) const {
		return( Vec2( fabs( m_v[ 0 ] ), fabs( m_v[ 1 ] ) ) );
	}

	Vec2 Vec2::sgn( void ) const {
		return( Vec2( m_v[ 0 ] < 0.0 ? -1.0 : 1.0, m_v[ 1 ] < 0.0 ? -1.0 : 1.0 ) );
	}

	Vec2 Vec2::clamp( double min, double max ) const {
		Vec2 v( * this );
		for( int i = 0; i < 2; i++ ){
			if( v[i] < min ){
				v[i] = min;
			}
			else if( v[i] > max ){
				v[i] = max;
			}
		}
		return( v );
	}

	Vec2 Vec2::cross( void ) const {
		Vec2 a;
		a[ 0 ] = -m_v[ 1 ];
		a[ 1 ] =  m_v[ 0 ];
		return( a );
	}

	double Vec2::cross( const Vec2 & v ) const {
		return( v.dot( cross() ) );
	}

	Vec2 Vec2::fromAngle( double rad ) {
		return( Vec2( cos( rad ), sin( rad ) ) );
	}

	double Vec2::toAngle( void ) const {
		// assumes vector is normalized
		double a = acos( m_v[ 0 ] );
		if( m_v[ 1 ] < 0.0 ){
			a = 2.0 * M_PI - a;
		}
		return( a );
	}

	bool Vec2::equals( const Vec2 & compare, double epsilon ) const {
		return( equals( ( const double * )compare, epsilon ) );
	}

	bool Vec2::equals( const double * compare, double epsilon ) const {
		for( int i = 0; i < 2; i++ ){
			if( fabs( compare[i] - m_v[i] ) > epsilon ){
				return( false );
			}
		}
		return( true );
	}

	///--------------------------------Mat2-------------------------------

	Mat2::Mat2( double v00, double v01, double v10, double v11 ){
		m_v[ 0 ] = v00;
		m_v[ 1 ] = v01;
		m_v[ 2 ] = v10;
		m_v[ 3 ] = v11;
	}

	Mat2::Mat2( const double * v ){
		memcpy( m_v, v, 4 * sizeof( double ) );
	}

	Vec2 Mat2::operator * ( const Vec2 & b ) const {
		Vec2 a;
		a[ 0 ] = m_v[ 0 ] * b[ 0 ] + m_v[ 2 ] * b[ 1 ];
		a[ 1 ] = m_v[ 1 ] * b[ 0 ] + m_v[ 3 ] * b[ 1 ];
		return( a );
	}

	Mat2 Mat2::operator * ( const Mat2 & b ) const {
		Mat2 a;
		a[ 0 ] = m_v[ 0 ] * b[ 0 ] + m_v[ 2 ] * b[ 1 ];
		a[ 2 ] = m_v[ 0 ] * b[ 2 ] + m_v[ 2 ] * b[ 3 ];
		a[ 1 ] = m_v[ 1 ] * b[ 0 ] + m_v[ 3 ] * b[ 1 ];
		a[ 3 ] = m_v[ 1 ] * b[ 2 ] + m_v[ 3 ] * b[ 3 ];
		return( a );
	}

	Mat2 & Mat2::operator *= ( const Mat2 & b ){
		return( * this = * this * b );
	}

	Mat2 & Mat2::operator /= ( double b ){
		return( * this = * this / b );
	}

	Mat2 Mat2::operator * ( double b ) const {
		Mat2 a;
		a[ 0 ] = m_v[ 0 ] * b;
		a[ 1 ] = m_v[ 1 ] * b;
		a[ 2 ] = m_v[ 2 ] * b;
		a[ 3 ] = m_v[ 3 ] * b;
		return( a );
	}

	Mat2 Mat2::operator / ( double b ) const {
		Mat2 a;
		a[ 0 ] = m_v[ 0 ] / b;
		a[ 1 ] = m_v[ 1 ] / b;
		a[ 2 ] = m_v[ 2 ] / b;
		a[ 3 ] = m_v[ 3 ] / b;
		return( a );
	}

	double & Mat2::operator [] ( int index ) {
		return( m_v[ index ] );
	}

	const double & Mat2::operator [] ( const int index ) const {
		return( m_v[ index ] );
	}

	Mat2::operator 	const double * ( void ) const{
		return( m_v );
	}

	Mat2::operator 	double * ( void ){
		return( m_v );
	}

	const double & Mat2::getElement( int column, int row ) const {
		return( m_v[ column * 2 + row ] );
	}
		
	double & Mat2::getElement( int column, int row ){
		return( m_v[ column * 2 + row ] );
	}
		
	void Mat2::setElement( int col, int row, double v ){
		m_v[ col * 2 + row ] = v;
	}

	bool Mat2::operator == ( const Mat2 & b ) const{
		return( equals( b ) );
	}

	bool Mat2::operator != ( const Mat2 & b ) const{
		return( ! equals( b ) );
	}

	Vec2 Mat2::getRow( int index ) const{
		return( Vec2( m_v[ index ], m_v[ 2 + index ] ) );
	}

	Vec2 Mat2::getCol( int index ) const{
		return( Vec2( m_v[ index * 2 + 0 ], m_v[ index * 2 + 1 ] ) );
	}

	void Mat2::setRow( int index, const Vec2 & row ){
		m_v[ index ] = row[ 0 ];
		m_v[ 2 + index ] = row[ 1 ];
	}

	void Mat2::setCol( int index, const Vec2 & col ){
		m_v[ index * 2 + 0 ] = col[ 0 ];
		m_v[ index * 2 + 1 ] = col[ 1 ];
	}

	bool Mat2::equals( const Mat2 & compare, double epsilon ) const {
		return( equals( ( const double * )compare, epsilon ) );
	}

	bool Mat2::equals( const double * compare, double epsilon ) const {
		for( int i = 0; i < 4; i++ ){
			if( fabs( compare[i] - m_v[i] ) > epsilon ){
				return( false );
			}
		}
		return( true );
	}


	void Mat2::scale( const Vec2 & s ){
		m_v[ 0 ] *= s[ 0 ];
		m_v[ 1 ] *= s[ 0 ];
		
		m_v[ 2 ] *= s[ 1 ];
		m_v[ 3 ] *= s[ 1 ];
	}

	void Mat2::setScaling( const Vec2 & s ){
		setCol( 0, normalize( getCol( 0 ) ) * s[ 0 ] );
		setCol( 1, normalize( getCol( 1 ) ) * s[ 1 ] );
	}

	Vec2 Mat2::getScaling( void ){
		Vec2 scaling;
		scaling[ 0 ] = length( getCol( 0 ) );
		scaling[ 1 ] = length( getCol( 1 ) );
		return( scaling );
	}

	Mat2 Mat2::transpose() const {
		return( Mat2( m_v[ 0 ], m_v[ 2 ], m_v[ 1 ], m_v[ 3 ] ) );
	}

	double Mat2::determinant() const {
		return( m_v[ 0 ] * m_v[ 3 ] - m_v[ 1 ] * m_v[ 2 ] );
	}

	Mat2 Mat2::inverse() const {
		double d = determinant();

		if( d == 0.0 ){
			EMIT_WARNING( __FILE__, __LINE__, "matrix is singular" );
			return( Mat2::fromIdentity() );
		}

		Mat2	r;
		r[ 0 ] =  m_v[ 3 ]; r[ 2 ] = -m_v[ 2 ];
		r[ 1 ] = -m_v[ 1 ]; r[ 3 ] =  m_v[ 0 ];
		r /= d;

		return( r );
	}

	void Mat2::setIdentity( void ){
		m_v[ 0 ] = 1.0;
		m_v[ 1 ] = 0.0;
		m_v[ 2 ] = 0.0;
		m_v[ 3 ] = 1.0;
	}

	Mat2 Mat2::fromIdentity( void ){
		Mat2 m;
		m.setIdentity();
		return( m );
	}

	///--------------------------------Vec3-------------------------------

	Vec3::Vec3( double x, double y, double z ){
		m_v[ 0 ] = x;
		m_v[ 1 ] = y;
		m_v[ 2 ] = z;
	}

	Vec3::Vec3( double xyz ){
		m_v[ 0 ] = xyz;
		m_v[ 1 ] = xyz;
		m_v[ 2 ] = xyz;
	}

	Vec3::Vec3( const double * v ){
		memcpy( m_v, v, 3 * sizeof( double ) );
	}

	Vec3::Vec3( const Vec2 & xy, double z ){
		m_v[ 0 ] = xy[ 0 ];
		m_v[ 1 ] = xy[ 1 ];
		m_v[ 2 ] = z;
	}

	bool Vec3::operator < ( const double v ) const {
		return( hyp() < v * v );
	}

	bool Vec3::operator < ( const Vec2 & v ) const {
		return( hyp() < v.hyp() );
	}

	bool Vec3::operator < ( const Vec3 & v ) const {
		return( hyp() < v.hyp() );
	}

	bool Vec3::operator < ( const Vec4 & v ) const {
		return( hyp() < v.hyp() );
	}

	Vec3 Vec3::operator - () const {
		return( Vec3( -m_v[ 0 ], -m_v[ 1 ], -m_v[ 2 ] ) );
	}

	Vec3 Vec3::operator + ( const Vec3 & b ) const {
		Vec3 a;
		a[ 0 ] = m_v[ 0 ] + b[ 0 ];
		a[ 1 ] = m_v[ 1 ] + b[ 1 ];
		a[ 2 ] = m_v[ 2 ] + b[ 2 ];
		return( a );
	}

	Vec3 Vec3::operator - ( const Vec3 & b ) const {
		Vec3 a;
		a[ 0 ] = m_v[ 0 ] - b[ 0 ];
		a[ 1 ] = m_v[ 1 ] - b[ 1 ];
		a[ 2 ] = m_v[ 2 ] - b[ 2 ];
		return( a );
	}

	Vec3 Vec3::operator * ( double b ) const {
		Vec3 a;
		a[ 0 ] = m_v[ 0 ] * b;
		a[ 1 ] = m_v[ 1 ] * b;
		a[ 2 ] = m_v[ 2 ] * b;
		return( a );
	}

	Vec3 Vec3::operator * ( const Vec3 & b ) const {
		Vec3 a;
		a[ 0 ] = m_v[ 0 ] * b[ 0 ];
		a[ 1 ] = m_v[ 1 ] * b[ 1 ];
		a[ 2 ] = m_v[ 2 ] * b[ 2 ];
		return( a );
	}

	Vec3 Vec3::operator / ( const Vec3 & b ) const {
		Vec3 a;
		a[ 0 ] = m_v[ 0 ] / b[ 0 ];
		a[ 1 ] = m_v[ 1 ] / b[ 1 ];
		a[ 2 ] = m_v[ 2 ] / b[ 2 ];
		return( a );
	}

	Vec3 Vec3::operator / ( double b ) const {
		if( b == 0.0 ){
			EMIT_WARNING( __FILE__, __LINE__, "" );
			return( Vec3() );
		}
		Vec3 a;
		a[ 0 ] = m_v[ 0 ] / b;
		a[ 1 ] = m_v[ 1 ] / b;
		a[ 2 ] = m_v[ 2 ] / b;
		return( a );
	}

	Vec3 & Vec3::operator += ( const Vec3 & b ){
		return( * this = * this + b );
	}

	Vec3 & Vec3::operator -= ( const Vec3 & b ){
		return( *( ( Vec3 * )this ) = * this - b );
	}

	Vec3 & Vec3::operator *= ( double b ){
		return( *( ( Vec3 * )this ) = * this * b );
	}

	Vec3 & Vec3::operator *= ( const Vec3 & b ){
		return( *( ( Vec3 * )this ) = * this * b );
	}

	Vec3 & Vec3::operator /= ( double b ){
		return( *( ( Vec3 * )this ) = * this / b );
	}

	Vec3 & Vec3::operator /= ( const Vec3 & b ){
		return( *( ( Vec3 * )this ) = * this / b );
	}

	double & Vec3::operator [] ( int index ) {
		return( m_v[ index ] );
	}

	const double & Vec3::operator [] ( const int index ) const {
		return( m_v[ index ] );
	}

	Vec3::operator 	const double * ( void ) const{
		return( m_v );
	}

	Vec3::operator 	double * ( void ){
		return( m_v );
	}

	bool Vec3::operator == ( const Vec3 & b ) const {
		return( equals( b ) );
	}

	bool Vec3::operator != ( const Vec3 & b ) const {
		return( ! equals( b ) );
	}

	double Vec3::hyp( void ) const {
		return( m_v[ 0 ] * m_v[ 0 ] + m_v[ 1 ] * m_v[ 1 ] + m_v[ 2 ] * m_v[ 2 ] );
	}

	double Vec3::len( void ) const {
		double h = hyp();
		if( h < MU_EPSILON ){
			return( 0.0 );
		}
		return( sqrt( hyp() ) );
	}

	void Vec3::normalize( void ){
		double l = len();
		if( l == 0.0 ){
			EMIT_WARNING( __FILE__, __LINE__, "" );
			return;
		}
		m_v[ 0 ] /= l;
		m_v[ 1 ] /= l;
		m_v[ 2 ] /= l;
	}

	Vec3 Vec3::normalized( void ) const {
		double l = len();
		if( l == 0.0 ){
			EMIT_WARNING( __FILE__, __LINE__, "" );
			return( Vec3() );
		}
		return( Vec3( m_v[ 0 ] / l, m_v[ 1 ] / l, m_v[ 2 ] / l ) );
	}

	Vec2 Vec3::toPolar( void ) const {
		Vec2 p;
		Vec3 normal = normalized();
		if( length2( normal.xy() ) <= 1e-6 ){
			p[ 0 ] = 0.0;
		}
		else{
			p[ 0 ] = atan2( normal[ 1 ], normal[ 0 ] );
		}
		p[ 1 ] = acos( normal[ 2 ] );
		return( p );
	}

	double Vec3::getAngle( const Vec3 & x, const Vec3 & y ) const {
	  double a = acos( mu::clamp( mu::dot( x, *this ), -1.0, 1.0 ) );
	  if( mu::dot( y, * this ) < 0.0 ) a = 2.0 * M_PI - a;
		return( a );
	}

	double Vec3::dot( const Vec3 & b ) const {
		return( m_v[ 0 ] * b[ 0 ] + m_v[ 1 ] * b[ 1 ] + m_v[ 2 ] * b[ 2 ] );
	}

	Vec3 Vec3::abs( void ) const {
		return( Vec3( fabs( m_v[ 0 ] ), fabs( m_v[ 1 ] ), fabs( m_v[ 2 ] ) ) );
	}

	Vec3 Vec3::sgn( void ) const {
		return( Vec3( m_v[ 0 ] < 0.0 ? -1.0 : 1.0, m_v[ 1 ] < 0.0 ? -1.0 : 1.0, m_v[ 2 ] < 0.0 ? -1.0 : 1.0 ) );
	}

	Vec3 Vec3::clamp( double min, double max ) const {
		Vec3 v( *this );
		for( int i = 0; i < 3; i++ ){
			if( v[i] < min ){
				v[i] = min;
			}
			else if( v[i] > max ){
				v[i] = max;
			}
		}
		return( v );
	}

	Vec3 Vec3::cross( const Vec3 & b ) const {
		Vec3 a;
		a[ 0 ] = m_v[ 1 ] * b[ 2 ] - m_v[ 2 ] * b[ 1 ];
		a[ 1 ] = m_v[ 2 ] * b[ 0 ] - m_v[ 0 ] * b[ 2 ];
		a[ 2 ] = m_v[ 0 ] * b[ 1 ] - m_v[ 1 ] * b[ 0 ];
		return( a );
	}

	bool Vec3::equals( const Vec3 & compare, double epsilon ) const {
		return( equals( ( const double * )compare, epsilon ) );
	}

	bool Vec3::equals( const double * compare, double epsilon ) const {
		for( int i = 0; i < 3; i++ ){
			if( fabs( compare[i] - m_v[i] ) > epsilon ){
				return( false );
			}
		}
		return( true );
	}

	double &	Vec3::x( void ){
		return( m_v[ 0 ] );
	}

	const double & Vec3::x( void ) const {
		return( m_v[ 0 ] );
	}

	double &	Vec3::y( void ){
		return( m_v[ 1 ] );
	}

	const double & Vec3::y( void ) const {
		return( m_v[ 1 ] );
	}

	double &	Vec3::z( void ){
		return( m_v[ 2 ] );
	}

	const double & Vec3::z( void ) const {
		return( m_v[ 2 ] );
	}

	Vec2 Vec3::xy() const {
		return( Vec2( m_v[ 0 ], m_v[ 1 ] ) );
	}

	Vec3 Vec3::fromPolar( const Vec2 & polar ){
		double sx = sin( polar[ 0 ] );
		double cx = cos( polar[ 0 ] );
		double sy = sin( polar[ 1 ] );
		double cy = cos( polar[ 1 ] );
		Vec3 p;
		p[ 0 ] = sy * cx;
		p[ 1 ] = sy * sx;
		p[ 2 ] = cy;
		return( p );
	}
	  
	  void Vec3::rotateX( double degrees ){
	      // Rotate point around the x-axis about degrees.
	      Vec3 result;
	      
		double r = toRadians( degrees );

		result[1] = (double) ( cos( r ) * m_v[ 0 ] + sin( r ) * m_v[ 2 ] );
		result[2] = (double) (-sin( r ) * m_v[ 0 ] + cos( r ) * m_v[ 2 ] ); 
	      
	      m_v[1] = result[1];
	      m_v[2] = result[2];
	  }
	      
	  void Vec3::rotateY( double degrees ){
	      // Rotate point around the y-axis about degrees.
	      Vec3 result;
	      
		double r = toRadians( degrees );
	      
	      result[0] = (double) ( cos( r ) * m_v[ 0 ] + sin( r ) * m_v[ 2 ] );
	      result[2] = (double) (-sin( r ) * m_v[ 0 ] + cos( r ) * m_v[ 2 ] ); 
	      
	      m_v[0] = result[0];
	      m_v[2] = result[2];
	  }
	  
	  void Vec3::rotateZ( double degrees ){
	      // Rotate point around the z-axis about p_Degrees.
	      Vec3 result;
	      
		double r = toRadians( degrees );

		result[0] = (double) ( cos( r ) * m_v[ 0 ] + sin( r ) * m_v[ 2 ] );
		result[1] = (double) (-sin( r ) * m_v[ 0 ] + cos( r ) * m_v[ 2 ] ); 
	      
	      m_v[0] = result[0];
	      m_v[1] = result[1];
	  }

	///--------------------------------Mat3-------------------------------

	Mat3::Mat3( double v00, double v01, double v02,
				double v10, double v11, double v12,
				double v20, double v21, double v22 ){
		m_v[ 0 ] = v00;
		m_v[ 1 ] = v01;
		m_v[ 2 ] = v02;
		m_v[ 3 ] = v10;
		m_v[ 4 ] = v11;
		m_v[ 5 ] = v12;
		m_v[ 6 ] = v20;
		m_v[ 7 ] = v21;
		m_v[ 8 ] = v22;
	}


	Mat3::Mat3( const double * v ){
		memcpy( m_v, v, 9 * sizeof( double ) );
	}

	Mat3::Mat3( const Vec3 & c0, const Vec3 & c1, const Vec3 & c2 ){
		m_v[ 0 ] = c0[ 0 ];
		m_v[ 1 ] = c0[ 1 ];
		m_v[ 2 ] = c0[ 2 ];
		m_v[ 3 ] = c1[ 0 ];
		m_v[ 4 ] = c1[ 1 ];
		m_v[ 5 ] = c1[ 2 ];
		m_v[ 6 ] = c2[ 0 ];
		m_v[ 7 ] = c2[ 1 ];
		m_v[ 8 ] = c2[ 2 ];
	}

	Vec3 Mat3::operator * ( const Vec3 & b ) const {
		Vec3 a;
		a[ 0 ] = m_v[ 0 ] * b[ 0 ] + m_v[ 3 ] * b[ 1 ] + m_v[ 6 ] * b[ 2 ];
		a[ 1 ] = m_v[ 1 ] * b[ 0 ] + m_v[ 4 ] * b[ 1 ] + m_v[ 7 ] * b[ 2 ];
		a[ 2 ] = m_v[ 2 ] * b[ 0 ] + m_v[ 5 ] * b[ 1 ] + m_v[ 8 ] * b[ 2 ];
		return( a );
	}

	Mat3 Mat3::operator * ( const Mat3 & b ) const {
		Mat3 a;

		a[ 0 ] = m_v[ 0 ] * b[ 0 ] + m_v[ 3 ] * b[ 1 ] + m_v[ 6 ] * b[ 2 ];
		a[ 3 ] = m_v[ 0 ] * b[ 3 ] + m_v[ 3 ] * b[ 4 ] + m_v[ 6 ] * b[ 5 ];
		a[ 6 ] = m_v[ 0 ] * b[ 6 ] + m_v[ 3 ] * b[ 7 ] + m_v[ 6 ] * b[ 8 ];

		a[ 1 ] = m_v[ 1 ] * b[ 0 ] + m_v[ 4 ] * b[ 1 ] + m_v[ 7 ] * b[ 2 ];
		a[ 4 ] = m_v[ 1 ] * b[ 3 ] + m_v[ 4 ] * b[ 4 ] + m_v[ 7 ] * b[ 5 ];
		a[ 7 ] = m_v[ 1 ] * b[ 6 ] + m_v[ 4 ] * b[ 7 ] + m_v[ 7 ] * b[ 8 ];

		a[ 2 ] = m_v[ 2 ] * b[ 0 ] + m_v[ 5 ] * b[ 1 ] + m_v[ 8 ] * b[ 2 ];
		a[ 5 ] = m_v[ 2 ] * b[ 3 ] + m_v[ 5 ] * b[ 4 ] + m_v[ 8 ] * b[ 5 ];
		a[ 8 ] = m_v[ 2 ] * b[ 6 ] + m_v[ 5 ] * b[ 7 ] + m_v[ 8 ] * b[ 8 ];

		return( a );
	}

	Mat3 Mat3::operator * ( double b ) const {
		Mat3 a;
		a[ 0 ] = m_v[ 0 ] * b;
		a[ 1 ] = m_v[ 1 ] * b;
		a[ 2 ] = m_v[ 2 ] * b;
		a[ 3 ] = m_v[ 3 ] * b;
		a[ 4 ] = m_v[ 4 ] * b;
		a[ 5 ] = m_v[ 5 ] * b;
		a[ 6 ] = m_v[ 6 ] * b;
		a[ 7 ] = m_v[ 7 ] * b;
		a[ 8 ] = m_v[ 8 ] * b;
		return( a );
	}

	Mat3 Mat3::operator / ( double b ) const {
		Mat3 a;
		a[ 0 ] = m_v[ 0 ] / b;
		a[ 1 ] = m_v[ 1 ] / b;
		a[ 2 ] = m_v[ 2 ] / b;
		a[ 3 ] = m_v[ 3 ] / b;
		a[ 4 ] = m_v[ 4 ] / b;
		a[ 5 ] = m_v[ 5 ] / b;
		a[ 6 ] = m_v[ 6 ] / b;
		a[ 7 ] = m_v[ 7 ] / b;
		a[ 8 ] = m_v[ 8 ] / b;
		return( a );
	}

	Mat3 & Mat3::operator *= ( const Mat3 & b ){
		return( * this = * this * b );
	}

	Mat3 & Mat3::operator *= ( double b ){
		return( * this = * this * b );
	}

	Mat3 & Mat3::operator /= ( double b ){
		return( * this = * this / b );
	}

	double & Mat3::operator [] ( int index ) {
		return( m_v[ index ] );
	}

	const double & Mat3::operator [] ( const int index ) const {
		return( m_v[ index ] );
	}

	Mat3::operator 	const double * ( void ) const{
		return( m_v );
	}

	Mat3::operator 	double * ( void ){
		return( m_v );
	}

	const double & Mat3::getElement( int column, int row ) const {
		return( m_v[ column * 3 + row ] );
	}

	double & Mat3::getElement( int column, int row ){
		return( m_v[ column * 3 + row ] );
	}

	void Mat3::setElement( int col, int row, double v ){
		m_v[ col * 3 + row ] = v;
	}

	void Mat3::rotate( double degrees, const Vec3 & axis ){
		Mat3 rot;
		rot.setAxisAngle( degrees, axis );
		( * this ) *= rot;
	}

	void Mat3::setRotationX( const double angle_deg ){
		// Fast, dedicated, x-axis rotation...
		double angle_rad = toRadians(angle_deg);
		double c = cos(angle_rad);
		double s = sin(angle_rad);

		m_v[ 0 ] = 1.0;
		m_v[ 1 ] = 0.0;
		m_v[ 2 ] = 0.0;

		m_v[ 3 ] = 0.0;
		m_v[ 4 ] = c;
		m_v[ 5 ] = s;

		m_v[ 6 ] = 0.0;
		m_v[ 7 ] = -s;
		m_v[ 8 ] = c;

	}

	void Mat3::setRotationY( const double angle_deg ){
		// Fast, dedicated, y-axis rotation...
		double angle_rad = toRadians(angle_deg);
		double c = cos(angle_rad);
		double s = sin(angle_rad);

		m_v[ 0 ] = c;
		m_v[ 1 ] = 0.0;
		m_v[ 2 ] = -s;

		m_v[ 3 ] = 0.0;
		m_v[ 4 ] = 1.0;
		m_v[ 5 ] = 0.0;

		m_v[ 6 ] = s;
		m_v[ 7 ] = 0.0;
		m_v[ 8 ] = c;

	}

	void Mat3::setRotationZ( const double angle_deg ){
		// Fast, dedicated, z-axis rotation...
		double angle_rad = toRadians(angle_deg);
		double c = cos(angle_rad);
		double s = sin(angle_rad);

		m_v[ 0 ] = c;
		m_v[ 1 ] = s;
		m_v[ 2 ] = 0.0;

		m_v[ 3 ] = -s;
		m_v[ 4 ] = c;
		m_v[ 5 ] = 0.0;

		m_v[ 6 ] = 0.0;
		m_v[ 7 ] = 0.0;
		m_v[ 8 ] = 1.0;
	}

	void Mat3::rotateX( const double angle_deg ){
		// Fast dedicated, x-axis rotate
		// 0 3 6       1       0       0
		// 1 4 7   .   0     cos(a) -sin(a)
		// 2 5 8       0     sin(a)  cos(a)

		Vec3 newCol1;
		Vec3 newCol2;
		double angle_rad = toRadians(angle_deg);
		double c = cos(angle_rad);
		double s = sin(angle_rad);

		newCol1[0] = m_v[3]*c	+ m_v[6]*s;
		newCol1[1] = m_v[4]*c	+ m_v[7]*s;
		newCol1[2] = m_v[5]*c	+ m_v[8]*s;

		newCol2[0] = m_v[3]*-s + m_v[6]*c;
		newCol2[1] = m_v[4]*-s + m_v[7]*c;
		newCol2[2] = m_v[5]*-s + m_v[8]*c;

		m_v[3] = newCol1[0];
		m_v[4] = newCol1[1];
		m_v[5] = newCol1[2];

		m_v[6] = newCol2[0];
		m_v[7] = newCol2[1];
		m_v[8] = newCol2[2];
	}

	void Mat3::rotateY( const double angle_deg ){
		// Fast dedicated, y-axis rotate
		// 0 3 6       cos(a)    0     sin(a)
		// 1 4 7   .     0       1       0
		// 2 5 8      -sin(a)    0     cos(a)

		Vec3 newCol0;
		Vec3 newCol2;
		double angle_rad = toRadians(angle_deg);
		double c = cos(angle_rad);
		double s = sin(angle_rad);

		newCol0[0] = m_v[0]*c + m_v[6]*-s;
		newCol0[1] = m_v[1]*c + m_v[7]*-s;
		newCol0[2] = m_v[2]*c + m_v[8]*-s;

		newCol2[0] = m_v[0]*s + m_v[6]*c;
		newCol2[1] = m_v[1]*s + m_v[7]*c;
		newCol2[2] = m_v[2]*s + m_v[8]*c;

		m_v[0] = newCol0[0];
		m_v[1] = newCol0[1];
		m_v[2] = newCol0[2];

		m_v[6] = newCol2[0];
		m_v[7] = newCol2[1];
		m_v[8] = newCol2[2];
	}

	void Mat3::rotateZ( const double angle_deg ){
		// Fast dedicated, z-axis rotate
		// 0 3 6       cos(a) -sin(a)    0
		// 1 4 7   .   sin(a)  cos(a)    0
		// 2 5 8         0       0       1

		Vec3 newCol0;
		Vec3 newCol1;
		double angle_rad = toRadians(angle_deg);
		double c = cos(angle_rad);
		double s = sin(angle_rad);

		newCol0[0] = m_v[0]*c + m_v[3]*s;
		newCol0[1] = m_v[1]*c + m_v[4]*s;
		newCol0[2] = m_v[2]*c + m_v[5]*s;

		newCol1[0] = m_v[0]*-s + m_v[3]*c;
		newCol1[1] = m_v[1]*-s + m_v[4]*c;
		newCol1[2] = m_v[2]*-s + m_v[5]*c;

		m_v[0] = newCol0[0];
		m_v[1] = newCol0[1];
		m_v[2] = newCol0[2];

		m_v[3] = newCol1[0];
		m_v[4] = newCol1[1];
		m_v[5] = newCol1[2];
	}

	void Mat3::setAxisAngle( double degrees, const Vec3 & axis ){
		double xx, yy, zz, xy, yz, zx, xs, ys, zs, s, c, c1, radians;
		
		radians = degrees * ( M_PI / 180.0 );
		
		s = sinf( radians );
		c = cosf( radians );
		c1 = 1.0 - c;

		Vec3 nor = axis.normalized();

		xx = nor[ 0 ] * nor[ 0 ];
		yy = nor[ 1 ] * nor[ 1 ];
		zz = nor[ 2 ] * nor[ 2 ];
		
		xy = nor[ 0 ] * nor[ 1 ];
		yz = nor[ 1 ] * nor[ 2 ];
		zx = nor[ 2 ] * nor[ 0 ];
		
		xs = nor[ 0 ] * s;
		ys = nor[ 1 ] * s;
		zs = nor[ 2 ] * s;
				
		m_v[ 0 ] = ( c1 * xx ) + c;
		m_v[ 1 ] = ( c1 * xy ) + zs;
		m_v[ 2 ] = ( c1 * zx ) - ys;
		
		m_v[ 3 ] = ( c1 * xy ) - zs;
		m_v[ 4 ] = ( c1 * yy ) + c;
		m_v[ 5 ] = ( c1 * yz ) + xs;
		
		m_v[ 6 ] = ( c1 * zx ) + ys;
		m_v[ 7 ] = ( c1 * yz ) - xs;
		m_v[ 8 ] = ( c1 * zz ) + c;
	}

	bool Mat3::operator == ( const Mat3 & b ) const {
		return( equals( b ) );
	}

	bool Mat3::operator != ( const Mat3 & b ) const {
		return( ! equals( b ) );
	}

	Vec3 Mat3::getRow( int index ) const {
		return( Vec3( m_v[ index ], m_v[ 3 + index ], m_v[ 6 + index ] ) );
	}

	Vec3 Mat3::getCol( int index ) const {
		return( Vec3( m_v[ index * 3 + 0 ], m_v[ index * 3 + 1 ], m_v[ index * 3 + 2 ] ) );
	}

	void Mat3::setRow( int index, const Vec3 & row ){
		m_v[ index ] = row[ 0 ];
		m_v[ 3 + index ] = row[ 1 ];
		m_v[ 6 + index ] = row[ 2 ];
	}

	void Mat3::setCol( int index,  const Vec3 & col ){
		m_v[ index * 3 + 0 ] = col[ 0 ];
		m_v[ index * 3 + 1 ] = col[ 1 ];
		m_v[ index * 3 + 2 ] = col[ 2 ];
	}

	bool Mat3::equals(  const Mat3 & compare, double epsilon ) const {
		return( equals( ( const double * )compare, epsilon ) );
	}

	bool Mat3::equals(  const double * compare, double epsilon ) const {
		for( int i = 0; i < 9; i++ ){
			if( fabs( compare[i] - m_v[i] ) > epsilon ){
				return( false );
			}
		}
		return( true );
	}

	Mat3 Mat3::transpose( void ) const {

		Mat3 a;

		a[ 0 ] = m_v[ 0 ];
		a[ 3 ] = m_v[ 1 ];
		a[ 6 ] = m_v[ 2 ];

		a[ 1 ] = m_v[ 3 ];
		a[ 4 ] = m_v[ 4 ];
		a[ 7 ] = m_v[ 5 ];

		a[ 2 ] = m_v[ 6 ];
		a[ 5 ] = m_v[ 7 ];
		a[ 8 ] = m_v[ 8 ];

		return( a );

	}

	Mat3 Mat3::adjugate( void ) const {

		Vec3 x = getRow( 1 ).cross( getRow( 2 ) );
		Vec3 y = getRow( 2 ).cross( getRow( 0 ) );
		Vec3 z = getRow( 0 ).cross( getRow( 1 ) );

		return( Mat3( x, y, z ) );
	}

	double Mat3::determinant( void ) const {
		return( m_v[ 0 ] * ( ( m_v[ 4 ] * m_v[ 8 ] ) - ( m_v[ 5 ] * m_v[ 7 ] ) ) -
				m_v[ 1 ] * ( ( m_v[ 3 ] * m_v[ 8 ] ) - ( m_v[ 5 ] * m_v[ 6 ] ) ) +
				m_v[ 2 ] * ( ( m_v[ 3 ] * m_v[ 7 ] ) - ( m_v[ 4 ] * m_v[ 6 ] ) ) );
	}

	double Mat3::trace( void ) const {
		return( m_v[ 0 ] + m_v[ 4 ] + m_v[ 8 ] );
	}

	Mat3 Mat3::inverse( void ) const {
		double d = determinant();

		if( d == 0.0 ){
			EMIT_WARNING( __FILE__, __LINE__, "matrix is singular" );
			return( Mat3::fromIdentity() );
		}

		return( adjugate().transpose() / d );
	}

	void Mat3::setIdentity( void ){
		m_v[ 0 ] = 1.0;
		m_v[ 1 ] = 0.0;
		m_v[ 2 ] = 0.0;
		m_v[ 3 ] = 0.0;
		m_v[ 4 ] = 1.0;
		m_v[ 5 ] = 0.0;
		m_v[ 6 ] = 0.0;
		m_v[ 7 ] = 0.0;
		m_v[ 8 ] = 1.0;
	}

	void Mat3::scale( const Vec3 & s ){
		m_v[ 0 ] *= s[ 0 ];
		m_v[ 1 ] *= s[ 0 ];
		m_v[ 2 ] *= s[ 0 ];
		
		m_v[ 3 ] *= s[ 1 ];
		m_v[ 4 ] *= s[ 1 ];
		m_v[ 5 ] *= s[ 1 ];

		m_v[ 6 ] *= s[ 2 ];
		m_v[ 7 ] *= s[ 2 ];
		m_v[ 8 ] *= s[ 2 ];
	}

	void Mat3::setScaling( const Vec3 & s ){
		setCol( 0, normalize( getCol( 0 ) ) * s[ 0 ] );
		setCol( 1, normalize( getCol( 1 ) ) * s[ 1 ] );
		setCol( 2, normalize( getCol( 2 ) ) * s[ 2 ] );
	}

	Vec3 Mat3::getScaling( void ){
		Vec3 scaling;
		scaling[ 0 ] = length( getCol( 0 ) );
		scaling[ 1 ] = length( getCol( 1 ) );
		scaling[ 2 ] = length( getCol( 2 ) );
		return( scaling );
	}

	Mat3 Mat3::fromYawPitchRollInDegrees( const Vec3 & YawPitchRollInDegrees ){
		Quat q;
		q.setYawPitchRollInDegrees( YawPitchRollInDegrees[ 0 ], YawPitchRollInDegrees[ 1 ], YawPitchRollInDegrees[ 2 ] );
		return( q.toMat3() );
	}

	Vec3 Mat3::toYawPitchRollInDegrees( void ) const {
		return( Quat::fromMat3( * this ).getYawPitchRollInDegrees() );
	}
	  
	Mat4 Mat3::toMat4( void ) const { 
		Mat4 m;
	      
		m[  0 ] = m_v[ 0 ];
		m[  1 ] = m_v[ 1 ];
		m[  2 ] = m_v[ 2 ];
	      m[  3 ] = 0.0;
	      
		m[  4 ] = m_v[ 3 ];
		m[  5 ] = m_v[ 4 ];
		m[  6 ] = m_v[ 5 ];
		m[  7 ] = 0.0;
	      
		m[  8 ] = m_v[ 6 ];
		m[  9 ] = m_v[ 7 ];
		m[ 10 ] = m_v[ 8 ];
		m[ 11 ] = 0.0;

		m[ 12 ] = 0.0;
		m[ 13 ] = 0.0;
		m[ 14 ] = 0.0;
		m[ 15 ] = 1.0;
	      
		return( m );
	}
	  
	Mat3 Mat3::fromIdentity(){
		Mat3 m;
		m.setIdentity();
		return( m );
	}


	///--------------------------------Vec4-------------------------------


	Vec4::Vec4( double x, double y, double z, double w ){
		m_v[ 0 ] = x;
		m_v[ 1 ] = y;
		m_v[ 2 ] = z;
		m_v[ 3 ] = w;
	}

	Vec4::Vec4( double xyzw ){
		m_v[ 0 ] = xyzw;
		m_v[ 1 ] = xyzw;
		m_v[ 2 ] = xyzw;
		m_v[ 3 ] = xyzw;
	}

	Vec4::Vec4( const double * v ){
		memcpy( m_v, v, 4 * sizeof( double ) );
	}

	Vec4::Vec4( const Vec2 & xy, double z, double w ){
		m_v[ 0 ] = xy[ 0 ];
		m_v[ 1 ] = xy[ 1 ];
		m_v[ 2 ] = z;
		m_v[ 3 ] = w;
	}

	Vec4::Vec4( const Vec3 & xyz, double w ){
		m_v[ 0 ] = xyz[ 0 ];
		m_v[ 1 ] = xyz[ 1 ];
		m_v[ 2 ] = xyz[ 2 ];
		m_v[ 3 ] = w;
	}

	Vec4::Vec4( const Vec2 & xy, const Vec2 & zw ){
		m_v[ 0 ] = xy[ 0 ];
		m_v[ 1 ] = xy[ 1 ];
		m_v[ 2 ] = zw[ 0 ];
		m_v[ 3 ] = zw[ 1 ];
	}

	Vec4::Vec4( double x, const Vec3 & yzw ){
		m_v[ 0 ] = x;
		m_v[ 1 ] = yzw[ 0 ];
		m_v[ 2 ] = yzw[ 1 ];
		m_v[ 3 ] = yzw[ 2 ];
	}

	Vec4::Vec4( double x, double y, const Vec2 & zw ){
		m_v[ 0 ] = x;
		m_v[ 1 ] = y;
		m_v[ 2 ] = zw[ 0 ];
		m_v[ 3 ] = zw[ 1 ];
	}

	bool Vec4::operator < ( const double v ) const {
		return( hyp() < v * v );
	}

	bool Vec4::operator < ( const Vec2 & v ) const {
		return( hyp() < v.hyp() );
	}

	bool Vec4::operator < ( const Vec3 & v ) const {
		return( hyp() < v.hyp() );
	}

	bool Vec4::operator < ( const Vec4 & v ) const {
		return( hyp() < v.hyp() );
	}

	Vec4 Vec4::operator - () const {
		return( Vec4( -m_v[ 0 ], -m_v[ 1 ], -m_v[ 2 ], -m_v[ 3 ] ) );
	}

	Vec4 Vec4::operator + ( const Vec4 & b ) const {
		Vec4 a;
		a[ 0 ] = m_v[ 0 ] + b[ 0 ];
		a[ 1 ] = m_v[ 1 ] + b[ 1 ];
		a[ 2 ] = m_v[ 2 ] + b[ 2 ];
		a[ 3 ] = m_v[ 3 ] + b[ 3 ];
		return( a );
	}

	Vec4 Vec4::operator - ( const Vec4 & b ) const {
		Vec4 a;
		a[ 0 ] = m_v[ 0 ] - b[ 0 ];
		a[ 1 ] = m_v[ 1 ] - b[ 1 ];
		a[ 2 ] = m_v[ 2 ] - b[ 2 ];
		a[ 3 ] = m_v[ 3 ] - b[ 3 ];
		return( a );
	}

	Vec4 Vec4::operator * ( const double b ) const {
		Vec4 a;
		a[ 0 ] = m_v[ 0 ] * b;
		a[ 1 ] = m_v[ 1 ] * b;
		a[ 2 ] = m_v[ 2 ] * b;
		a[ 3 ] = m_v[ 3 ] * b;
		return( a );
	}

	Vec4 Vec4::operator * ( const Vec4 & b ) const {
		Vec4 a;
		a[ 0 ] = m_v[ 0 ] * b[ 0 ];
		a[ 1 ] = m_v[ 1 ] * b[ 1 ];
		a[ 2 ] = m_v[ 2 ] * b[ 2 ];
		a[ 3 ] = m_v[ 3 ] * b[ 3 ];
		return( a );
	}

	Vec4 Vec4::operator / ( const Vec4 & b ) const {
		Vec4 a;
		a[ 0 ] = m_v[ 0 ] / b[ 0 ];
		a[ 1 ] = m_v[ 1 ] / b[ 1 ];
		a[ 2 ] = m_v[ 2 ] / b[ 2 ];
		a[ 3 ] = m_v[ 3 ] / b[ 3 ];
		return( a );
	}

	Vec4 Vec4::operator / ( double b ) const {
		Vec4 a;
		a[ 0 ] = m_v[ 0 ] / b;
		a[ 1 ] = m_v[ 1 ] / b;
		a[ 2 ] = m_v[ 2 ] / b;
		a[ 3 ] = m_v[ 3 ] / b;
		return( a );
	}

	Vec4 & Vec4::operator += ( const Vec4 & b ){
		return( * this = * this + b );
	}

	Vec4 & Vec4::operator -= ( const Vec4 & b ){
		return( * this = * this - b );
	}

	Vec4 & Vec4::operator *= ( double b ){
		return( * this = * this * b );
	}

	Vec4 & Vec4::operator *= ( const Vec4 & b ){
		return( * this = * this * b );
	}

	Vec4 & Vec4::operator /= ( double b ){
		return( * this = * this / b );
	}

	Vec4 & Vec4::operator /= ( const Vec4 & b ){
		return( * this = * this / b );
	}

	double & Vec4::operator [] ( int index ) {
		return( m_v[ index ] );
	}

	const double & Vec4::operator [] ( const int index ) const {
		return( m_v[ index ] );
	}

	Vec4::operator 	const double * ( void ) const{
		return( m_v );
	}

	Vec4::operator 	double * ( void ){
		return( m_v );
	}

	bool Vec4::operator == ( const Vec4 & b ) const {
		return( equals( b ) );
	}

	bool Vec4::operator != ( const Vec4 & b ) const {
		return( ! equals( b ) );
	}

	double &	Vec4::x( void ){
		return( m_v[ 0 ] );
	}

	const double & Vec4::x( void ) const {
		return( m_v[ 0 ] );
	}

	double &	Vec4::y( void ){
		return( m_v[ 1 ] );
	}

	const double & Vec4::y( void ) const {
		return( m_v[ 1 ] );
	}

	double &	Vec4::z( void ){
		return( m_v[ 2 ] );
	}

	const double & Vec4::z( void ) const {
		return( m_v[ 2 ] );
	}

	double &	Vec4::w( void ){
		return( m_v[ 3 ] );
	}

	const double & Vec4::w( void ) const {
		return( m_v[ 3 ] );
	}

	Vec2 Vec4::xy() const {
		return( Vec2( m_v[ 0 ], m_v[ 1 ] ) );
	}

	Vec2 Vec4::zw() const {
		return( Vec2( m_v[ 2 ], m_v[ 3 ] ) );
	}

	Vec3 Vec4::xyz() const {
		return( Vec3( m_v[ 0 ], m_v[ 1 ], m_v[ 2 ] ) );
	}

	double Vec4::hyp( void ) const {
		return( m_v[ 0 ] * m_v[ 0 ] + m_v[ 1 ] * m_v[ 1 ] + m_v[ 2 ] * m_v[ 2 ] + m_v[ 3 ] * m_v[ 3 ] );
	}

	double Vec4::len( void ) const {
		double h = hyp();
		if( h < MU_EPSILON ){
			return( 0.0 );
		}
		return( sqrt( h ) );
	}

	void Vec4::normalize( void ){
		double l = len();
		if( l == 0.0 ){
			EMIT_WARNING( __FILE__, __LINE__, "" );
			return;
		}
		m_v[ 0 ] /= l;
		m_v[ 1 ] /= l;
		m_v[ 2 ] /= l;
		m_v[ 3 ] /= l;
	}

	Vec4 Vec4::normalized( void ) const {
		double l = len();
		return( Vec4( m_v[ 0 ] / l, m_v[ 1 ] / l, m_v[ 2 ] / l, m_v[ 3 ] / l ) );
	}

	double Vec4::dot( const Vec4 & b ) const {
		return( m_v[ 0 ] * b[ 0 ] + m_v[ 1 ] * b[ 1 ] + m_v[ 2 ] * b[ 2 ] + m_v[ 3 ] * b[ 3 ] );
	}

	Vec4 Vec4::abs( void ) const {
		return( Vec4( fabs( m_v[ 0 ] ), fabs( m_v[ 1 ] ), fabs( m_v[ 2 ] ), fabs( m_v[ 3 ] ) ) );
	}

	Vec4 Vec4::sgn( void ) const {
		return( Vec4( m_v[ 0 ] < 0.0 ? -1.0 : 1.0, m_v[ 1 ] < 0.0 ? -1.0 : 1.0, m_v[ 2 ] < 0.0 ? -1.0 : 1.0, m_v[ 3 ] < 0.0 ? -1.0 : 1.0 ) );
	}

	Vec4 Vec4::clamp( double min, double max ) const {
		Vec4 v( *this );
		for( int i = 0; i < 4; i++ ){
			if( v[i] < min ){
				v[i] = min;
			}
			else if( v[i] > max ){
				v[i] = max;
			}
		}
		return( v );
	}

	bool Vec4::equals( const Vec4 & compare, double epsilon ) const {
		return( equals( ( const double * )compare, epsilon ) );
	}

	bool Vec4::equals(  const double * compare, double epsilon ) const {
		for( int i = 0; i < 4; i++ ){
			if( fabs( compare[i] - m_v[i] ) > epsilon ){
				return( false );
			}
		}
		return( true );
	}

	///--------------------------------Quat-------------------------------

	/** @warning - the YawPitchRoll conversions don't work - @todo @fixme
		@22-02-2012: fixed the Quat::getYawPitchRollInDegrees - polar conditions were 'optimized away'
		reconstructed the function from original source http://www.euclideanspace.com/maths/geometry/rotations/conversions/quaternionToEuler/
		RenderTools::Mat3 m;
		RenderTools::Quat q, r;
		for( int i = 0; i < 180; i++ ){
			for( int j = 0; j < 180; j++ ){
				for( int k = 0; k < 180; k++ ){
					Vec3 ypr( i, j, k );//(1)
					std::cout << toString( ypr ) << std::endl;
					q = RenderTools::Quat::fromYawPitchRollInDegrees( ypr );
					m = q.toMat3();
					r = Quat::fromMat3( m );
					ypr = r.getYawPitchRollInDegrees();
					std::cout << toString( q ) << std::endl;
					std::cout << toString( r ) << std::endl;
					std::cout << toString( ypr ) << std::endl << std::endl; // this is not the same as ypr(1)
				}
			}
		}
	**/

	Quat::Quat( double x, double y, double z, double w ){
		m_v[0] = x;
		m_v[1] = y;
		m_v[2] = z;
		m_v[3] = w;
	}

	Quat::Quat( const double * v ){
		memcpy( m_v, v, 4 * sizeof( double ) );
	}

	Quat::Quat( const Vec3 & yawPitchRollInDegrees ){
		setYawPitchRollInDegrees( yawPitchRollInDegrees[ 0 ], yawPitchRollInDegrees[ 1 ], yawPitchRollInDegrees[ 2 ] );
	}

	Vec2 Quat::xy( void ) const {
		return( Vec2( m_v[0], m_v[1] ) );
	}
						 
	Vec2 Quat::zw( void ) const {
		return( Vec2( m_v[2], m_v[3] ) );
	}
						 
	Vec3 Quat::xyz( void ) const {
		return( Vec3( m_v[0], m_v[1], m_v[2] ) );
	}

	bool Quat::equals( const Quat & compare, double epsilon ) const {
		return( equals( ( const double * )compare, epsilon ) );
	}

	bool Quat::equals( const double * compare, double epsilon ) const {
		for( int i = 0; i < 4; i++ ){
			if( fabs( compare[i] - m_v[i] ) > epsilon ){
				return( false );
			}
		}
		return( true );
	}

	double & Quat::operator [] ( int index ) {
		return( m_v[ index ] );
	}

	const double & Quat::operator [] ( const int index ) const {
		return( m_v[ index ] );
	}

	bool Quat::operator == ( const Quat & q ) const {
		return( equals( q ) );
	}

	bool Quat::operator != ( const Quat & q ) const {
		return( ! equals( q ) );
	}

	Quat Quat::operator + ( const Quat & q ) const {
		Quat result;
		for( int i = 0; i < 4; ++i ){
			result.m_v[i] = m_v[i] + q.m_v[i];
		}
		return( result );
	}

	Quat Quat::operator - ( const Quat & q ) const {
		Quat result;
		for( int i = 0; i < 4; ++i ){
			result.m_v[i] = m_v[i] - q.m_v[i];
		}
		return( result );
	}

	Quat Quat::operator * ( const Quat & q ) const {

		Quat result;

		result.m_v[0] =
			m_v[0] * q.m_v[0] -
			m_v[1] * q.m_v[1] -
			m_v[2] * q.m_v[2] -
			m_v[3] * q.m_v[3];

		result.m_v[1] =
			m_v[0] * q.m_v[1] +
			m_v[1] * q.m_v[0] +
			m_v[2] * q.m_v[3] -
			m_v[3] * q.m_v[2];

		result.m_v[2] =
			m_v[0] * q.m_v[2] +
			m_v[2] * q.m_v[0] +
			m_v[3] * q.m_v[1] -
			m_v[1] * q.m_v[3];

		result.m_v[3] =
			m_v[0] * q.m_v[3] +
			m_v[3] * q.m_v[0] +
			m_v[1] * q.m_v[2] -
			m_v[2] * q.m_v[1];

		return( result );
	}

	Quat Quat::operator * ( double scalar ) const {
		Quat result;
		for( int i = 0; i < 4; ++i ){
			result.m_v[i] = scalar * m_v[i];
		}
		return( result );
	}

	Quat Quat::operator / ( double scalar ) const {
		Quat result;
		int i;

		if( scalar != 0 ){
			for( i = 0; i < 4; ++i ){
				result.m_v[i] = m_v[i] / scalar;
			}
		}
		else{
			for( i = 0; i < 4; ++i ){
				result.m_v[i] = 0.0;
			}
		}

		return( result );
	}

	Quat Quat::operator - ( void ) const {
		Quat result;
		for( int i = 0; i < 4; ++i ){
			result.m_v[i] = -m_v[i];
		}
		return( result );
	}

	Quat & Quat::operator += ( const Quat & q ){
		for( int i = 0; i < 4; ++i ){
			m_v[i] += q.m_v[i];
		}
		return( * this );
	}

	Quat & Quat::operator -= ( const Quat & q ){
		for( int i = 0; i < 4; ++i ){
			m_v[i] -= q.m_v[i];
		}
		return( * this );
	}

	Quat & Quat::operator *= ( double scalar ){
		for( int i = 0; i < 4; ++i ){
			m_v[i] *= scalar;
		}
		return( * this );
	}

	Quat & Quat::operator /= ( double scalar ){
		int i;

		if( scalar != 0.0 ){
			for( i = 0; i < 4; ++i ){
				m_v[i] /= scalar;
			}
		}
		else{
			for( i = 0; i < 4; ++i ){
				m_v[i] = 0.0;
			}
		}

		return( * this );
	}

	Quat::operator 	const double * ( void ) const{
		return( m_v );
	}

	Quat::operator 	double * ( void ){
		return( m_v );
	}

	Quat Quat::fromMat3( const Mat3 & m ){
		Quat q;
		// Copied from http://www.gamasutra.com/features/19980703/quaternions_01.htm
		double  tr, s;
		int    i, j, k;

		int nxt[ 3 ] = { 1, 2, 0 };

		tr = m[ 0 ] + m[ 4 ] + m[ 8 ];

		// check the diagonal
		if( tr > 0.0 ){
			s = (double) sqrt (tr + 1.0);
			q[ 3 ] = s / 2.0;
			s = 0.5f / s;
			q[ 0 ] = ( m[ 5 ] - m[ 7 ] ) * s;
			q[ 1 ] = ( m[ 6 ] - m[ 2 ] ) * s;
			q[ 2 ] = ( m[ 1 ] - m[ 3 ] ) * s;
		}
		else{
			// diagonal is negative
			i = 0;
			if( m[ 4 ] > m[ 0 ] ){
				i = 1;
			}
			if( m[ 8 ] > m[ i * 3 + i ] ){
				i = 2;
			}

			j = nxt[ i ];
			k = nxt[ j ];

			s = (double)sqrt( ( m[ i * 3 + i ] - ( m[ j * 3 + j ] + m[ k * 3 + k ] ) ) + 1.0 );

			q[ i ] = s * 0.5f;
		   
			if( s != 0.0 ){
				  s = 0.5f / s;
			}

			q[3] = ( m[ j * 3 + k ] - m[ k * 3 + j ] ) * s;
			q[j] = ( m[ i * 3 + j ] + m[ j * 3 + i ] ) * s;
			q[k] = ( m[ i * 3 + k ] + m[ k * 3 + i ] ) * s;
		}

		return( q );
	}

	Mat3 Quat::toMat3( void ) const {
		Mat3 m;
		// Copied from http://www.gamasutra.com/features/19980703/quaternions_01.htm
		double wx, wy, wz, xx, yy, yz, xy, xz, zz, x2, y2, z2;

		// calculate coefficients
		x2 = m_v[ 0 ] + m_v[ 0 ];
		y2 = m_v[ 1 ] + m_v[ 1 ];
		z2 = m_v[ 2 ] + m_v[ 2 ];

		xx = m_v[ 0 ] * x2;
		xy = m_v[ 0 ] * y2;
		xz = m_v[ 0 ] * z2;

		yy = m_v[ 1 ] * y2;
		yz = m_v[ 1 ] * z2;

		zz = m_v[ 2 ] * z2;

		wx = m_v[ 3 ] * x2;
		wy = m_v[ 3 ] * y2;
		wz = m_v[ 3 ] * z2;

		m[0] = 1.0 - ( yy + zz );
		m[3] = xy - wz;
		m[6] = xz + wy;

		m[1] = xy + wz;
		m[4] = 1.0 - ( xx + zz );
		m[7] = yz - wx;

		m[2] = xz - wy;
		m[5] = yz + wx;
		m[8] = 1.0 - ( xx + yy );
		return( m );
	}

	Mat4 Quat::toMat4( void ) const {
		Mat4 m;

		std::cerr << "Quat::toMat4: not implemented" << std::endl;

		return( m );
	}

	Quat Quat::fromAxisAngle( const Vec3 & axis, double angle ){
		Quat q;
		double halfAngle = 0.5f * angle;
		double sn = sin( halfAngle );
		q.m_v[0] = cos( halfAngle );
		q.m_v[1] = sn * axis[0];
		q.m_v[2] = sn * axis[1];
		q.m_v[3] = sn * axis[2];
		return( q );
	}

	void Quat::toAxisAngle( Vec3 & axis, double & angle ) const {

		double sqrLength = m_v[1] * m_v[1] + m_v[2] * m_v[2] + m_v[3] * m_v[3];

		if( sqrLength > 0.0 ){
			angle = 2.0 * acos( m_v[0] );

			double length = sqrt( sqrLength );
			axis[0] = m_v[1] / length;
			axis[1] = m_v[2] / length;
			axis[2] = m_v[3] / length;
		}
		else{
			angle = 0.0;

			axis[0] = 1.0;
			axis[1] = 0.0;
			axis[2] = 0.0;
		}
	}

	void Quat::setYawPitchRollInDegrees( double yaw, double pitch, double roll ){
		//derived from http://www.euclideanspace.com/maths/geometry/rotations/conversions/eulerToQuaternion/
		yaw = toRadians( yaw );
		pitch = toRadians( pitch );
		roll = toRadians( roll );
		double c1 = cos( yaw / 2.0 );
		double c2 = cos( pitch / 2.0 );
		double c3 = cos( roll / 2.0 );
		double s1 = sin( yaw / 2.0 );
		double s2 = sin( pitch / 2.0 );
		double s3 = sin( roll / 2.0 );

		m_v[ 0 ] = s1 * s2 * c3 + c1 * c2 * s3;
		m_v[ 1 ] = s1 * c2 * c3 + c1 * s2 * s3;
		m_v[ 2 ] = c1 * s2 * c3 - s1 * c2 * s3;
		m_v[ 3 ] = c1 * c2 * c3 - s1 * s2 * s3;
	}

	Vec3 Quat::getYawPitchRollInDegrees( void ) const {
		//derived from http://www.euclideanspace.com/maths/geometry/rotations/conversions/quaternionToEuler/
		Vec3 ypr;
		double test = m_v[ 0 ] * m_v[ 1 ] + m_v[ 2 ] * m_v[ 3 ] ;
		if( test > 0.499999f ){
			ypr[ 0 ] = 360.0 / M_PI * atan2( m_v[ 0 ] , m_v[ 3 ] );
			ypr[ 1 ] = 90.0;
			ypr[ 2 ] = 0.0;
			return( ypr );
		}
		if( test < -0.499999f ){
			ypr[ 0 ] = -360.0 / M_PI * atan2( m_v[ 0 ] , m_v[ 3 ] );
			ypr[ 1 ] = -90.0;
			ypr[ 2 ] = 0.0;
			return( ypr );
		}
		double y =  atan2( 2.0 * m_v[ 1 ] * m_v[ 3 ] -2.0 * m_v[ 0 ] * m_v[ 2 ] , 1.0 - 2.0 * m_v[ 1 ] * m_v[ 1 ] - 2.0 * m_v[ 2 ] * m_v[ 2 ]);
		double p =  asin( 2.0 * m_v[ 0 ] * m_v[ 1 ] +2.0 * m_v[ 2 ] * m_v[ 3 ] );
		double r =  atan2( 2.0 * m_v[ 0 ] * m_v[ 3 ] -2.0 * m_v[ 1 ] * m_v[ 2 ] , 1.0 - 2.0 * m_v[ 0 ] * m_v[ 0 ] -2.0 * m_v[ 2 ] * m_v[ 2 ]);
		ypr[ 0 ] = y * 180.0 / M_PI;
		ypr[ 1 ] = p * 180.0 / M_PI;
		ypr[ 2 ] = r * 180.0 / M_PI;
		return( ypr );
	}

	double Quat::angle( const Quat & q ) const {
		double t = hyp() * q.hyp();
		if( t == 0.0 ){
			EMIT_WARNING( __FILE__, __LINE__, "" );
			return( 0.0 );
		}
		double s = sqrt( t );
		return( acos( dot( q ) / s ) );
	}

	double Quat::getAngle( void ) const {
		double s = 2.0 * acos( m_v[ 3 ] );
		return( s );
	}

	Quat Quat::mix( const Quat & q1, const Quat & q2, double t ){
	/*
	// quaternion to return
		Quat qm;
		// Calculate angle between them.
		double cosHalfTheta = qa[ 3 ] * qb[ 3 ] + qa[ 0 ] * qb[ 0 ] + qa[ 1 ] * qb[ 1 ] + qa[ 2 ] * qb[ 2 ];
		// if qa=qb or qa=-qb then theta = 0 and we can return qa
		if (abs(cosHalfTheta) >= 1.0){
			qm[ 3 ] = qa[ 3 ];qm[ 0 ] = qa[ 0 ];qm[ 1 ] = qa[ 1 ];qm[ 2 ] = qa[ 2 ];
			return qm;
		}
		// Calculate temporary values.
		double halfTheta = acos(cosHalfTheta);
		double sinHalfTheta = sqrt(1.0 - cosHalfTheta*cosHalfTheta);
		// if theta = 180 degrees then result is not fully defined
		// we could rotate around any axis normal to qa or qb
		if (fabs(sinHalfTheta) < 0.001){ // fabs is floating point absolute
			qm[ 3 ] = (qa[ 3 ] * 0.5 + qb[ 3 ] * 0.5);
			qm[ 0 ] = (qa[ 0 ] * 0.5 + qb[ 0 ] * 0.5);
			qm[ 1 ] = (qa[ 1 ] * 0.5 + qb[ 1 ] * 0.5);
			qm[ 2 ] = (qa[ 2 ] * 0.5 + qb[ 2 ] * 0.5);
			return qm;
		}
		double ratioA = sin((1.0 - t) * halfTheta) / sinHalfTheta;
		double ratioB = sin(t * halfTheta) / sinHalfTheta; 
		//calculate Quaternion.
		qm[ 3 ] = (qa[ 3 ] * ratioA + qb[ 3 ] * ratioB);
		qm[ 0 ] = (qa[ 0 ] * ratioA + qb[ 0 ] * ratioB);
		qm[ 1 ] = (qa[ 1 ] * ratioA + qb[ 1 ] * ratioB);
		qm[ 2 ] = (qa[ 2 ] * ratioA + qb[ 2 ] * ratioB);
		return qm;
	*/

			if( t == 0.0 ) return Quat( q1 );
			if( t == 1.0 ) return Quat( q2 );
			double epsilon = 0.0000001;
			Quat q;

			double x = q1[ 0 ];		
			double y = q1[ 1 ];		
			double z = q1[ 2 ];		
			double w = q1[ 3 ];		

			// http://www.euclideanspace.com/maths/algebra/realNormedAlgebra/quaternions/slerp/
			double cosHalfTheta = w * q2[ 3 ] + x * q2[ 0 ] + y * q2[ 1 ] + z * q2[ 2 ];

			if( cosHalfTheta < 0.0 ){
				q[ 3 ] = - q2[ 3 ];
				q[ 0 ] = - q2[ 0 ];
				q[ 1 ] = - q2[ 1 ];
				q[ 2 ] = - q2[ 2 ];
				cosHalfTheta = - cosHalfTheta;
			}
			else{
				q = Quat( q2 );
			}

			if( cosHalfTheta >= 1.0 ) {
				q[ 3 ] = w;
				q[ 0 ] = x;
				q[ 1 ] = y;
				q[ 2 ] = z;
				return( q );
			}

			double halfTheta = acos( cosHalfTheta );
			double sinHalfTheta = sqrt( 1.0 - cosHalfTheta * cosHalfTheta );

			if( fabs( sinHalfTheta ) < epsilon ) {
				q[ 3 ] = 0.5 * ( w + q[ 3 ] );
				q[ 0 ] = 0.5 * ( x + q[ 0 ] );
				q[ 1 ] = 0.5 * ( y + q[ 1 ] );
				q[ 2 ] = 0.5 * ( z + q[ 2 ] );
				return( q );
			}

			double ratioA = sin( ( 1.0 - t ) * halfTheta ) / sinHalfTheta,
			ratioB = sin( t * halfTheta ) / sinHalfTheta;

			q[ 3 ] = ( w * ratioA + q[ 3 ] * ratioB );
			q[ 0 ] = ( x * ratioA + q[ 0 ] * ratioB );
			q[ 1 ] = ( y * ratioA + q[ 1 ] * ratioB );
			q[ 2 ] = ( z * ratioA + q[ 2 ] * ratioB );

			return( q );

	/*
		double q = q1.getAngle();
		if( q != 0.0 ){
			double d = 1.0 / sin( q );
			double s0 = sin( ( 1.0 - f ) * q );
			double s1 = sin( f * q );
			if( q1.dot( q2 ) < 0.0 ){
				// take care of long angle case see http://en.wikipedia.org/wiki/Slerp
				return Quat(	( q1[ 0 ] * s0 + -q2[ 0 ] * s1 ) * d,
								( q1[ 1 ] * s0 + -q2[ 1 ] * s1 ) * d,
								( q1[ 2 ] * s0 + -q2[ 2 ] * s1 ) * d,
								( q1[ 3 ] * s0 + -q2[ 3 ] * s1 ) * d );
			}
			else{
				return Quat(	( q1[ 0 ] * s0 + q2[ 0 ] * s1 ) * d,
								( q1[ 1 ] * s0 + q2[ 1 ] * s1 ) * d,
								( q1[ 2 ] * s0 + q2[ 2 ] * s1 ) * d,
								( q1[ 3 ] * s0 + q2[ 3 ] * s1 ) * d );
			}
		}
		else{
			return( q1 );
		}
	*/
	}

	double Quat::len( void ) const {
		return( sqrt(	m_v[0]*m_v[0] + m_v[1]*m_v[1] + \
						m_v[2]*m_v[2] + m_v[3]*m_v[3] ) );
	}

	double Quat::hyp( void ) const {
		return( m_v[0] * m_v[0] + m_v[1] * m_v[1] + \
				m_v[2] * m_v[2] + m_v[3] * m_v[3] );
	}

	double Quat::dot( const Quat & q ) const {
		return( m_v[0] * q.m_v[0] + m_v[1] * q.m_v[1] + \
				m_v[2] * q.m_v[2] + m_v[3] * q.m_v[3] );
	}

	void Quat::normalize( void ){

		double length = len();

		if( length == 0.0 ){
			EMIT_WARNING( __FILE__, __LINE__, "" );
			return;
		}
		m_v[0] /= length;
		m_v[1] /= length;
		m_v[2] /= length;
		m_v[3] /= length;
	}


	Quat Quat::normalized( void ) const {
		Quat norm;

		double length = len();

		if( length == 0.0 ){
			EMIT_WARNING( __FILE__, __LINE__, "" );
			return( Quat() );
		}
		norm[0] = m_v[0] / length;
		norm[1] = m_v[1] / length;
		norm[2] = m_v[2] / length;
		norm[3] = m_v[3] / length;

		return( norm );
	}

	Quat Quat::inverse( void ) const {
		Quat inverse;

		double norm = hyp();

		if( norm > 0.0 ){
			inverse.m_v[0] =  m_v[0] / norm;
			inverse.m_v[1] = -m_v[1] / norm;
			inverse.m_v[2] = -m_v[2] / norm;
			inverse.m_v[3] = -m_v[3] / norm;
		}
		else{
			EMIT_WARNING( __FILE__, __LINE__, "" );
			return( Quat() );
		}

		return( inverse );
	}

	Quat Quat::conjugate( void ) const {
		return( Quat( m_v[0], -m_v[1], -m_v[2], -m_v[3] ) );
	}

	Quat Quat::exp( void ) const {

		Quat result;

		double angle = sqrt( m_v[1] * m_v[1] + m_v[2] * m_v[2] + m_v[3] * m_v[3] );

		double sn = sin( angle );
		result.m_v[0] = cos( angle );

		int i;

		if( fabs( sn ) >= 0.0 ){
			double coeff = sn / angle;
			for( i = 1; i < 4; ++i ){
				result.m_v[i] = coeff * m_v[i];
			}
		}
		else{
			for( i = 1; i < 4; ++i ){
				result.m_v[i] = m_v[i];
			}
		}

		return( result );
	}

	Quat Quat::log( void ) const {
		Quat result;
		result.m_v[0] = 0.0;

		int i;

		if( fabs( m_v[0] ) < 1.0 ){
			double angle = acos( m_v[0] );
			double sn = sin( angle );
			if( fabs( sn ) >= 0.0 ){
				double coeff = angle / sn;
				for( i = 1; i < 4; ++i ){
					result.m_v[i] = coeff * m_v[i];
				}
				return result;
			}
		}

		for( i = 1; i < 4; ++i ){
			result.m_v[i] = m_v[i];
		}

		return( result );
	}

	Quat Quat::fromYawPitchRollInDegrees( const Vec3 & yawPitchRollInDegrees ){
		return( Quat( yawPitchRollInDegrees ) );
	}

	///--------------------------------Mat4-------------------------------

	Mat4::Mat4(	double v00, double v01, double v02, double v03,
				double v10, double v11, double v12, double v13,
				double v20, double v21, double v22, double v23,
				double v30, double v31, double v32, double v33 ){

		m_v[ 0 ] = v00;
		m_v[ 1 ] = v01;
		m_v[ 2 ] = v02;
		m_v[ 3 ] = v03;
		m_v[ 4 ] = v10;
		m_v[ 5 ] = v11;
		m_v[ 6 ] = v12;
		m_v[ 7 ] = v13;
		m_v[ 8 ] = v20;
		m_v[ 9 ] = v21;
		m_v[ 10 ] = v22;
		m_v[ 11 ] = v23;
		m_v[ 12 ] = v30;
		m_v[ 13 ] = v31;
		m_v[ 14 ] = v32;
		m_v[ 15 ] = v33;
	}

	Mat4::Mat4( const double * v ){
		memcpy( m_v, v, 16 * sizeof( double ) );
	}

	/// rotate through upper left 3x3 and translate, assuming w = 1.0
	Vec3 Mat4::operator * ( const Vec3 & b ) const {
		Vec3 a;
		a[ 0 ] = b[ 0 ] * m_v[ 0 ] + b[ 1 ] * m_v[ 4 ] + b[ 2 ] * m_v[ 8 ] + m_v[ 12 ];
		a[ 1 ] = b[ 0 ] * m_v[ 1 ] + b[ 1 ] * m_v[ 5 ] + b[ 2 ] * m_v[ 9 ] + m_v[ 13 ];
		a[ 2 ] = b[ 0 ] * m_v[ 2 ] + b[ 1 ] * m_v[ 6 ] + b[ 2 ] * m_v[ 10 ] + m_v[ 14 ];
		return( a );
	}

	/// multiply
	Vec4 Mat4::operator * ( const Vec4 & b ) const {
		Vec4 a;
		a[ 0 ] = b[ 0 ] * m_v[ 0 ] + b[ 1 ] * m_v[ 4 ] + b[ 2 ] * m_v[ 8 ] + b[ 3 ] * m_v[ 12 ];
		a[ 1 ] = b[ 0 ] * m_v[ 1 ] + b[ 1 ] * m_v[ 5 ] + b[ 2 ] * m_v[ 9 ] + b[ 3 ] * m_v[ 13 ];
		a[ 2 ] = b[ 0 ] * m_v[ 2 ] + b[ 1 ] * m_v[ 6 ] + b[ 2 ] * m_v[ 10 ] + b[ 3 ] * m_v[ 14 ];
		a[ 3 ] = b[ 0 ] * m_v[ 3 ] + b[ 1 ] * m_v[ 7 ] + b[ 2 ] * m_v[ 11 ] + b[ 3 ] * m_v[ 15 ];
		return( a );
	}

	/// multiply the Mat3 with the upper left 3x3 
	Mat3 Mat4::operator * ( const Mat3 & b ) const {
		Mat3 a;

		a[ 0 ] = m_v[ 0 ] * b[ 0 ] + m_v[ 4 ] * b[ 1 ] + m_v[ 8 ] * b[ 2 ];
		a[ 3 ] = m_v[ 0 ] * b[ 3 ] + m_v[ 4 ] * b[ 4 ] + m_v[ 8 ] * b[ 5 ];
		a[ 6 ] = m_v[ 0 ] * b[ 6 ] + m_v[ 4 ] * b[ 7 ] + m_v[ 8 ] * b[ 8 ];

		a[ 1 ] = m_v[ 1 ] * b[ 0 ] + m_v[ 5 ] * b[ 1 ] + m_v[ 9 ] * b[ 2 ];
		a[ 4 ] = m_v[ 1 ] * b[ 3 ] + m_v[ 5 ] * b[ 4 ] + m_v[ 9 ] * b[ 5 ];
		a[ 7 ] = m_v[ 1 ] * b[ 6 ] + m_v[ 5 ] * b[ 7 ] + m_v[ 9 ] * b[ 8 ];

		a[ 2 ] = m_v[ 2 ] * b[ 0 ] + m_v[ 6 ] * b[ 1 ] + m_v[ 10 ] * b[ 2 ];
		a[ 5 ] = m_v[ 2 ] * b[ 3 ] + m_v[ 6 ] * b[ 4 ] + m_v[ 10 ] * b[ 5 ];
		a[ 8 ] = m_v[ 2 ] * b[ 6 ] + m_v[ 6 ] * b[ 7 ] + m_v[ 10 ] * b[ 8 ];

		return( a );
	}

	/// multiply the Mat4, assumed orthogonal non shearing matrix
	Mat4 Mat4::operator * ( const Mat4 & other ) const {
		static Mat4 resultMat;
		double * result = resultMat.m_v;
		const double * a = m_v;
		const double * b = other.m_v;

		//unsigned int i, j;
		//for( i = 0; i < 4; i++ ){
		//	unsigned int i4 = i * 4;
		//	for( j = 0; j < 4; j++ ){
		//		result[ i4 + j ] = 
		//		b[ i4 ] * a[ j ] +
		//		b[ i4 + 1 ] * a[ 4 + j ] +
		//		b[ i4 + 2 ] * a[ 8 + j ] +
		//		b[ i4 + 3 ] * a[ 12 + j ];
		//	}
		//}
		// 68 mults, 112 adds
		result[ 0 ] = b[ 0 ] * a[ 0 ] + b[ 1 ] * a[ 4 ] + b[ 2 ] * a[ 8 ] + b[ 3 ] * a[ 12 ];
		result[ 1 ] = b[ 0 ] * a[ 1 ] + b[ 1 ] * a[ 5 ] + b[ 2 ] * a[ 9 ] + b[ 3 ] * a[ 13 ];
		result[ 2 ] = b[ 0 ] * a[ 2 ] + b[ 1 ] * a[ 6 ] + b[ 2 ] * a[ 10 ] + b[ 3 ] * a[ 14 ];
		result[ 3 ] = b[ 0 ] * a[ 3 ] + b[ 1 ] * a[ 7 ] + b[ 2 ] * a[ 11 ] + b[ 3 ] * a[ 15 ];
		result[ 4 ] = b[ 4 ] * a[ 0 ] + b[ 5 ] * a[ 4 ] + b[ 6 ] * a[ 8 ] + b[ 7 ] * a[ 12 ];
		result[ 5 ] = b[ 4 ] * a[ 1 ] + b[ 5 ] * a[ 5 ] + b[ 6 ] * a[ 9 ] + b[ 7 ] * a[ 13 ];
		result[ 6 ] = b[ 4 ] * a[ 2 ] + b[ 5 ] * a[ 6 ] + b[ 6 ] * a[ 10 ] + b[ 7 ] * a[ 14 ];
		result[ 7 ] = b[ 4 ] * a[ 3 ] + b[ 5 ] * a[ 7 ] + b[ 6 ] * a[ 11 ] + b[ 7 ] * a[ 15 ];
		result[ 8 ] = b[ 8 ] * a[ 0 ] + b[ 9 ] * a[ 4 ] + b[ 10 ] * a[ 8 ] + b[ 11 ] * a[ 12 ];
		result[ 9 ] = b[ 8 ] * a[ 1 ] + b[ 9 ] * a[ 5 ] + b[ 10 ] * a[ 9 ] + b[ 11 ] * a[ 13 ];
		result[ 10 ] = b[ 8 ] * a[ 2 ] + b[ 9 ] * a[ 6 ] + b[ 10 ] * a[ 10 ] + b[ 11 ] * a[ 14 ];
		result[ 11 ] = b[ 8 ] * a[ 3 ] + b[ 9 ] * a[ 7 ] + b[ 10 ] * a[ 11 ] + b[ 11 ] * a[ 15 ];
		result[ 12 ] = b[ 12 ] * a[ 0 ] + b[ 13 ] * a[ 4 ] + b[ 14 ] * a[ 8 ] + b[ 15 ] * a[ 12 ];
		result[ 13 ] = b[ 12 ] * a[ 1 ] + b[ 13 ] * a[ 5 ] + b[ 14 ] * a[ 9 ] + b[ 15 ] * a[ 13 ];
		result[ 14 ] = b[ 12 ] * a[ 2 ] + b[ 13 ] * a[ 6 ] + b[ 14 ] * a[ 10 ] + b[ 15 ] * a[ 14 ];
		result[ 15 ] = b[ 12 ] * a[ 3 ] + b[ 13 ] * a[ 7 ] + b[ 14 ] * a[ 11 ] + b[ 15 ] * a[ 15 ];
		// 64 mults, 42 adds

		// optimized for non shearing, ortho matrices it'd look like this:
		//result[ 0 ] = m1[ 0 ] * m2[ 0 ] + m1[ 4 ] * m2[ 1 ] + m1[ 8 ] * m2[ 2 ];
		//result[ 1 ] = m1[ 1 ] * m2[ 0 ] + m1[ 5 ] * m2[ 1 ] + m1[ 9 ] * m2[ 2 ];
		//result[ 2 ] = m1[ 2 ] * m2[ 0 ] + m1[ 6 ] * m2[ 1 ] + m1[ 10 ] * m2[ 2 ];
		//result[ 3 ] = 0.0;

		//result[ 4 ] = m1[ 0 ] * m2[ 4 ] + m1[ 4 ] * m2[ 5 ] + m1[ 8 ] * m2[ 6 ];
		//result[ 5 ] = m1[ 1 ] * m2[ 4 ] + m1[ 5 ] * m2[ 5 ] + m1[ 9 ] * m2[ 6 ];
		//result[ 6 ] = m1[ 2 ] * m2[ 4 ] + m1[ 6 ] * m2[ 5 ] + m1[ 10 ] * m2[ 6 ];
		//result[ 7 ] = 0.0;

		//result[ 8 ] = m1[ 0 ] * m2[ 8 ] + m1[ 4 ] * m2[ 9 ] + m1[ 8 ] * m2[ 10 ];
		//result[ 9 ] = m1[ 1 ] * m2[ 8 ] + m1[ 5 ] * m2[ 9 ] + m1[ 9 ] * m2[ 10 ];
		//result[ 10 ] = m1[ 2 ] * m2[ 8 ] + m1[ 6 ] * m2[ 9 ] + m1[ 10 ] * m2[ 10 ];
		//result[ 11 ] = 0.0;

		//result[ 12 ] = m1[ 0 ] * m2[ 12 ] + m1[ 4 ] * m2[ 13 ] + m1[ 8 ] * m2[ 14 ] + m1[ 12 ];
		//result[ 13 ] = m1[ 1 ] * m2[ 12 ] + m1[ 5 ] * m2[ 13 ] + m1[ 9 ] * m2[ 14 ] + m1[ 13 ];
		//result[ 14 ] = m1[ 2 ] * m2[ 12 ] + m1[ 6 ] * m2[ 13 ] + m1[ 10 ] * m2[ 14 ] + m1[ 14 ];
		//result[ 15 ] = 1.0;
		// 39 mults, 27 adds

		return( resultMat );
	}
		
	Mat4 Mat4::operator * ( double f ) const {
		Mat4 m( m_v );

		m.m_v[ 0 ] *= f;
		m.m_v[ 1 ] *= f;
		m.m_v[ 2 ] *= f;

		m.m_v[ 4 ] *= f;
		m.m_v[ 5 ] *= f;
		m.m_v[ 6 ] *= f;

		m.m_v[ 8 ] *= f;
		m.m_v[ 9 ] *= f;
		m.m_v[ 10 ] *= f;

		return( m );
	}

	Mat4 & Mat4::operator *= ( const Mat4 & bMat ){
		const double * b = bMat.m_v;
		static double v[ 16 ];

		v[ 0  ] = m_v[ 0 ] * b[ 0  ] + m_v[ 4 ] * b[ 1  ] + m_v[ 8 ] * b[ 2  ] + m_v[ 12 ] * b[ 3  ];
		v[ 4  ] = m_v[ 0 ] * b[ 4  ] + m_v[ 4 ] * b[ 5  ] + m_v[ 8 ] * b[ 6  ] + m_v[ 12 ] * b[ 7  ];
		v[ 8  ] = m_v[ 0 ] * b[ 8  ] + m_v[ 4 ] * b[ 9  ] + m_v[ 8 ] * b[ 10 ] + m_v[ 12 ] * b[ 11 ];
		v[ 12 ] = m_v[ 0 ] * b[ 12 ] + m_v[ 4 ] * b[ 13 ] + m_v[ 8 ] * b[ 14 ] + m_v[ 12 ] * b[ 15 ];

		v[ 1  ] = m_v[ 1 ] * b[ 0  ] + m_v[ 5 ] * b[ 1  ] + m_v[ 9 ] * b[ 2  ] + m_v[ 13 ] * b[ 3  ];
		v[ 5  ] = m_v[ 1 ] * b[ 4  ] + m_v[ 5 ] * b[ 5  ] + m_v[ 9 ] * b[ 6  ] + m_v[ 13 ] * b[ 7  ];
		v[ 9  ] = m_v[ 1 ] * b[ 8  ] + m_v[ 5 ] * b[ 9  ] + m_v[ 9 ] * b[ 10 ] + m_v[ 13 ] * b[ 11 ];
		v[ 13 ] = m_v[ 1 ] * b[ 12 ] + m_v[ 5 ] * b[ 13 ] + m_v[ 9 ] * b[ 14 ] + m_v[ 13 ] * b[ 15 ];

		v[ 2  ] = m_v[ 2 ] * b[ 0  ] + m_v[ 6 ] * b[ 1  ] + m_v[ 10 ] * b[ 2  ] + m_v[ 14 ] * b[ 3  ];
		v[ 6  ] = m_v[ 2 ] * b[ 4  ] + m_v[ 6 ] * b[ 5  ] + m_v[ 10 ] * b[ 6  ] + m_v[ 14 ] * b[ 7  ];
		v[ 10 ] = m_v[ 2 ] * b[ 8  ] + m_v[ 6 ] * b[ 9  ] + m_v[ 10 ] * b[ 10 ] + m_v[ 14 ] * b[ 11 ];
		v[ 14 ] = m_v[ 2 ] * b[ 12 ] + m_v[ 6 ] * b[ 13 ] + m_v[ 10 ] * b[ 14 ] + m_v[ 14 ] * b[ 15 ];

		v[ 3  ] = m_v[ 3 ] * b[ 0  ] + m_v[ 7 ] * b[ 1  ] + m_v[ 11 ] * b[ 2  ] + m_v[ 15 ] * b[ 3  ];
		v[ 7  ] = m_v[ 3 ] * b[ 4  ] + m_v[ 7 ] * b[ 5  ] + m_v[ 11 ] * b[ 6  ] + m_v[ 15 ] * b[ 7  ];
		v[ 11 ] = m_v[ 3 ] * b[ 8  ] + m_v[ 7 ] * b[ 9  ] + m_v[ 11 ] * b[ 10 ] + m_v[ 15 ] * b[ 11 ];
		v[ 15 ] = m_v[ 3 ] * b[ 12 ] + m_v[ 7 ] * b[ 13 ] + m_v[ 11 ] * b[ 14 ] + m_v[ 15 ] * b[ 15 ];
		
		memcpy( m_v, v, 16 * sizeof( double ) );

		return( * this );
	}

	Mat4 & Mat4::operator *= ( const Mat3 & b ){
		static double v[ 16 ];

		v[ 0  ] = m_v[ 0  ] * b[ 0 ] + m_v[ 4 ] * b[ 1 ] + m_v[ 8 ] * b[ 2 ];
		v[ 4  ] = m_v[ 0  ] * b[ 3 ] + m_v[ 4 ] * b[ 4 ] + m_v[ 8 ] * b[ 5 ];
		v[ 8  ] = m_v[ 0  ] * b[ 6 ] + m_v[ 4 ] * b[ 7 ] + m_v[ 8 ] * b[ 8 ];
		v[ 12 ] = m_v[ 12 ];

		v[ 1  ] = m_v[ 1  ] * b[ 0 ] + m_v[ 5 ] * b[ 1 ] + m_v[ 9 ] * b[ 2 ];
		v[ 5  ] = m_v[ 1  ] * b[ 3 ] + m_v[ 5 ] * b[ 4 ] + m_v[ 9 ] * b[ 5 ];
		v[ 9  ] = m_v[ 1  ] * b[ 6 ] + m_v[ 5 ] * b[ 7 ] + m_v[ 9 ] * b[ 8 ];
		v[ 13 ] = m_v[ 13 ];

		v[ 2  ] = m_v[ 2  ] * b[ 0 ] + m_v[ 6 ] * b[ 1 ] + m_v[ 10 ] * b[ 2 ];
		v[ 6  ] = m_v[ 2  ] * b[ 3 ] + m_v[ 6 ] * b[ 4 ] + m_v[ 10 ] * b[ 5 ];
		v[ 10 ] = m_v[ 2  ] * b[ 6 ] + m_v[ 6 ] * b[ 7 ] + m_v[ 10 ] * b[ 8 ];
		v[ 14 ] = m_v[ 14 ];

		v[ 3  ] = m_v[ 3  ] * b[ 0 ] + m_v[ 7 ] * b[ 1 ] + m_v[ 11 ] * b[ 2 ];
		v[ 7  ] = m_v[ 3  ] * b[ 3 ] + m_v[ 7 ] * b[ 4 ] + m_v[ 11 ] * b[ 5 ];
		v[ 11 ] = m_v[ 3  ] * b[ 6 ] + m_v[ 7 ] * b[ 7 ] + m_v[ 11 ] * b[ 8 ];
		v[ 15 ] = m_v[ 15 ];
		
		memcpy( m_v, v, 16 * sizeof( double ) );

		return( * this );
	}

	Mat4 & Mat4::operator *= ( double f ){
		m_v[ 0 ] *= f;
		m_v[ 1 ] *= f;
		m_v[ 2 ] *= f;

		m_v[ 4 ] *= f;
		m_v[ 5 ] *= f;
		m_v[ 6 ] *= f;

		m_v[ 8 ] *= f;
		m_v[ 9 ] *= f;
		m_v[ 10 ] *= f;

		return( * this );
	}

	Mat4 & Mat4::operator *= ( const Vec3 & v ){
		m_v[ 0 ] *= v[ 0 ];
		m_v[ 1 ] *= v[ 0 ];
		m_v[ 2 ] *= v[ 0 ];

		m_v[ 4 ] *= v[ 1 ];
		m_v[ 5 ] *= v[ 1 ];
		m_v[ 6 ] *= v[ 1 ];

		m_v[ 8 ] *= v[ 2 ];
		m_v[ 9 ] *= v[ 2 ];
		m_v[ 10 ] *= v[ 2 ];

		return( * this );
	}

	/// for transformationmatrices, adding a vec2 
	/// implies a translation in the x-y plane
	Mat4 Mat4::operator + ( const Vec2 & v ) const {
		Mat4 m( m_v );

		m.m_v[ 12 ] += v[ 0 ];
		m.m_v[ 13 ] += v[ 1 ];

		return( m );
	}

	/// for transformationmatrices, adding a vec3 implies a translation
	Mat4 Mat4::operator + ( const Vec3 & v ) const {
		Mat4 m( m_v );

		m.m_v[ 12 ] += v[ 0 ];
		m.m_v[ 13 ] += v[ 1 ];
		m.m_v[ 14 ] += v[ 2 ];

		return( m );
	}

	Mat4 & Mat4::operator += ( const Vec2 & v ){
		m_v[ 12 ] += v[ 0 ];
		m_v[ 13 ] += v[ 1 ];
		return( * this );
	}

	Mat4 & Mat4::operator += ( const Vec3 & v ){
		m_v[ 12 ] += v[ 0 ];
		m_v[ 13 ] += v[ 1 ];
		m_v[ 14 ] += v[ 2 ];
		return( * this );
	}

	double & Mat4::operator [] ( int index ) {
		return( m_v[ index ] );
	}

	const double & Mat4::operator [] ( const int index ) const {
		return( m_v[ index ] );
	}

	Mat4::operator 	const double * ( void ) const{
		return( m_v );
	}

	Mat4::operator 	double * ( void ){
		return( m_v );
	}

	const double & Mat4::getElement( int column, int row ) const {
		return( m_v[ column * 4 + row ] );
	}

	double & Mat4::getElement( int column, int row ){
		return( m_v[ column * 4 + row ] );
	}

	void Mat4::setElement( int col, int row, double v ){
		m_v[ col * 4 + row ] = v;
	}

	bool Mat4::operator == ( const Mat4 & b ) const {
		return( equals( b ) );
	}

	bool Mat4::operator != ( const Mat4 & b ) const {
		return( ! equals( b ) );
	}

	Mat4 & Mat4::operator = ( const Mat4 & b ){
		for( unsigned int i = 0; i < 16; i++ ){
			m_v[ i ] = b[ i ];
		}
		return( * this );
	}

	Mat4 & Mat4::operator = ( const Mat3 & b ){
		m_v[ 0 ] = b[ 0 ];
		m_v[ 1 ] = b[ 1 ];
		m_v[ 2 ] = b[ 2 ];
		m_v[ 4 ] = b[ 3 ];
		m_v[ 5 ] = b[ 4 ];
		m_v[ 6 ] = b[ 5 ];
		m_v[ 8 ] = b[ 6 ];
		m_v[ 9 ] = b[ 7 ];
		m_v[ 10 ] = b[ 8 ];
		return( * this );
	}

	Mat4 & Mat4::operator = ( const Vec3 & b ){
		m_v[ 12 ] = b[ 0 ];
		m_v[ 13 ] = b[ 1 ];
		m_v[ 14 ] = b[ 2 ];
		return( * this );
	}

	Vec4 Mat4::getRow( int index ) const {
		return( Vec4( m_v[ index ], m_v[ 4 + index ], m_v[ 8 + index ], m_v[ 12 + index ] ) );
	}

	Vec4 Mat4::getCol( int index ) const {
		return( Vec4( m_v[ index * 4 + 0 ], m_v[ index * 4 + 1 ], m_v[ index * 4 + 2 ], m_v[ index * 4 + 3 ] ) );
	}

	void Mat4::setRow( int index, const Vec4 & row ){
		m_v[ index ] = row[ 0 ];
		m_v[ 4 + index ] = row[ 1 ];
		m_v[ 8 + index ] = row[ 2 ];
		m_v[ 12 + index ] = row[ 3 ];
	}

	void Mat4::setCol( int index, const Vec4 & col ){
		m_v[ index * 4 + 0 ] = col[ 0 ];
		m_v[ index * 4 + 1 ] = col[ 1 ];
		m_v[ index * 4 + 2 ] = col[ 2 ];
		m_v[ index * 4 + 3 ] = col[ 3 ];
	}

	void Mat4::setCol( int index, const Vec3 & col ){
		m_v[ index * 4 + 0 ] = col[ 0 ];
		m_v[ index * 4 + 1 ] = col[ 1 ];
		m_v[ index * 4 + 2 ] = col[ 2 ];
	}

	bool Mat4::equals( const Mat4 & compare, double epsilon ) const {
		return( equals( ( const double * )compare, epsilon ) );
	}

	bool Mat4::equals( const double * compare, double epsilon ) const {
		for( int i = 0; i < 16; i++ ){
			if( fabs( compare[i] - m_v[i] ) > epsilon ){
				return( false );
			}
		}
		return( true );
	}

	void Mat4::translate( const Vec3 & b ){
		m_v[ 12 ] = m_v[ 0 ] * b[ 0 ] + m_v[ 4 ] * b[ 1 ] + m_v[ 8 ]  * b[ 2 ] + m_v[ 12 ];
		m_v[ 13 ] = m_v[ 1 ] * b[ 0 ] + m_v[ 5 ] * b[ 1 ] + m_v[ 9 ]  * b[ 2 ] + m_v[ 13 ];
		m_v[ 14 ] = m_v[ 2 ] * b[ 0 ] + m_v[ 6 ] * b[ 1 ] + m_v[ 10 ] * b[ 2 ] + m_v[ 14 ];
		m_v[ 15 ] = m_v[ 3 ] * b[ 0 ] + m_v[ 7 ] * b[ 1 ] + m_v[ 11 ] * b[ 2 ] + m_v[ 15 ];
	}

	void Mat4::setTranslation( const Vec3 & b ){
		m_v[ 12 ] = b[ 0 ];
		m_v[ 13 ] = b[ 1 ];
		m_v[ 14 ] = b[ 2 ];
	}
		
	void Mat4::addTranslation( const Vec3 & b ){
		m_v[ 12 ] += b[ 0 ];
		m_v[ 13 ] += b[ 1 ];
		m_v[ 14 ] += b[ 2 ];
	}

	void Mat4::scale( const Vec3 & s ){
		m_v[ 0 ] *= s[ 0 ];
		m_v[ 1 ] *= s[ 0 ];
		m_v[ 2 ] *= s[ 0 ];
		
		m_v[ 4 ] *= s[ 1 ];
		m_v[ 5 ] *= s[ 1 ];
		m_v[ 6 ] *= s[ 1 ];

		m_v[ 8 ] *= s[ 2 ];
		m_v[ 9 ] *= s[ 2 ];
		m_v[ 10 ] *= s[ 2 ];
	}


	void Mat4::setScaling( const Vec3 & s ){
		// do an 'in place' length calculation for speed
		double l0 = m_v[ 0 ] * m_v[ 0 ] + m_v[ 1 ] * m_v[ 1 ] + m_v[ 2 ] * m_v[ 2 ]; 
		double l1 = m_v[ 4 ] * m_v[ 4 ] + m_v[ 5 ] * m_v[ 5 ] + m_v[ 6 ] * m_v[ 6 ]; 
		double l2 = m_v[ 8 ] * m_v[ 8 ] + m_v[ 9 ] * m_v[ 9 ] + m_v[ 10 ] * m_v[ 10 ]; 
	#ifdef NURBSTOOL_DEBUG
		if( l0 <= MU_EPSILON ){
			EMIT_WARNING( __FILE__, __LINE__, "" );
			return;
		}
		if( l1 <= MU_EPSILON ){
			EMIT_WARNING( __FILE__, __LINE__, "" );
			return;
		}
		if( l2 <= MU_EPSILON ){
			EMIT_WARNING( __FILE__, __LINE__, "" );
			return;
		}
	#endif
		// prescale with the reciproce
		l0 = s[ 0 ] / sqrt( l0 );
		l1 = s[ 1 ] / sqrt( l1 );
		l2 = s[ 2 ] / sqrt( l2 );

		// do scaling per element
		m_v[ 0 ] *= l0;
		m_v[ 1 ] *= l0;
		m_v[ 2 ] *= l0;
		
		m_v[ 4 ] *= l1;
		m_v[ 5 ] *= l1;
		m_v[ 6 ] *= l1;

		m_v[ 8 ] *= l2;
		m_v[ 9 ] *= l2;
		m_v[ 10 ] *= l2;
	}

	Vec3 Mat4::getScaling( void ){
		Vec3 scaling;
		scaling[ 0 ] = length( getCol( 0 ).xyz() );
		scaling[ 1 ] = length( getCol( 1 ).xyz() );
		scaling[ 2 ] = length( getCol( 2 ).xyz() );
		return( scaling );
	}

	Vec3 Mat4::getRotation( void ) const {
		return( toYawPitchRollInDegrees() );
	}

	Vec3 Mat4::getPosition( void ) const {
		return( translation() );
	}

	void Mat4::rotate( double degrees, const Vec3 & axis ){
		Mat4 rot;
		rot.setAxisAngle( degrees, axis );
		( * this ) *= rot;
	}

	Vec3 Mat4::transform( const Vec3 & point ) const {
		return( ( ( * this ) * Vec4( point, 1.0 ) ).xyz() );
	}

	Vec3 Mat4::translation( void ) const {
		return( Vec3( m_v[ 12 ], m_v[ 13 ], m_v[ 14 ] ) );
	}

	Mat3 Mat4::rotation( void ) const {
		/// return the upper-left 3x3 matrix
		return( Mat3( m_v[ 0 ], m_v[ 1 ], m_v[ 2 ], m_v[ 4 ], m_v[ 5 ], m_v[ 6 ], m_v[ 8 ], m_v[ 9 ], m_v[ 10 ] ) );
	}

	Mat4 Mat4::transpose( void ) const {

		Mat4 a;

		a[ 0 ] = m_v[ 0 ];
		a[ 4 ] = m_v[ 1 ];
		a[ 8 ] = m_v[ 2 ];
		a[ 12 ] = m_v[ 3 ];

		a[ 1 ] = m_v[ 4 ];
		a[ 5 ] = m_v[ 5 ];
		a[ 9 ] = m_v[ 6 ];
		a[ 13 ] = m_v[ 7 ];

		a[ 2 ] = m_v[ 8 ];
		a[ 6 ] = m_v[ 9 ];
		a[ 10 ] = m_v[ 10 ];
		a[ 14 ] = m_v[ 11 ];

		a[ 3 ] = m_v[ 12 ];
		a[ 7 ] = m_v[ 13 ];
		a[ 11 ] = m_v[ 14 ];
		a[ 15 ] = m_v[ 15 ];

		return( a );
	}

	/// original code from MESA contributed by Jacques Leroy jle@star.be
	Mat4 Mat4::inverse( void ) const {
		Mat4 a;

		double wtmp[ 4 ][ 8 ];
		double m0, m1, m2, m3, s;
		double *r0, *r1, *r2, *r3;

		r0 = wtmp[ 0 ], r1 = wtmp[ 1 ], r2 = wtmp[ 2 ], r3 = wtmp[ 3 ];

		r0[ 0 ] = m_v[ 0 ], r0[ 1 ] = m_v[ 4 ],
		r0[ 2 ] = m_v[ 8 ], r0[ 3 ] = m_v[ 12 ],
		r0[ 4 ] = 1.0, r0[ 5 ] = r0[ 6 ] = r0[ 7 ] = 0.0,

		r1[ 0 ] = m_v[ 1 ], r1[ 1 ] = m_v[ 5 ],
		r1[ 2 ] = m_v[ 9 ], r1[ 3 ] = m_v[ 13 ],
		r1[ 5 ] = 1.0, r1[ 4 ] = r1[ 6 ] = r1[ 7 ] = 0.0,

		r2[ 0 ] = m_v[ 2 ], r2[ 1 ] = m_v[ 6 ],
		r2[ 2 ] = m_v[ 10 ], r2[ 3 ] = m_v[ 14 ],
		r2[ 6 ] = 1.0, r2[ 4 ] = r2[ 5 ] = r2[ 7 ] = 0.0,

		r3[ 0 ] = m_v[ 3 ], r3[ 1 ] = m_v[ 7 ],
		r3[ 2 ] = m_v[ 11 ], r3[ 3 ] = m_v[ 15 ],
		r3[ 7 ] = 1.0, r3[ 4 ] = r3[ 5 ] = r3[ 6 ] = 0.0;

		if( fabs( r3[ 0 ] ) > fabs( r2[ 0 ] ) ){
			std::swap( r3, r2 );
		}
		if( fabs( r2[ 0 ] ) > fabs( r1[ 0 ] ) ){
			std::swap( r2, r1 );
		}
		if( fabs( r1[ 0 ] ) > fabs( r0[ 0 ] ) ){
			std::swap( r1, r0 );
		}
		if( r0[ 0 ] == 0.0 ){
			EMIT_WARNING( __FILE__, __LINE__, "matrix is singular" );
			return( Mat4::fromIdentity() );
		}

		// eliminate first variable
		m1 = r1[ 0 ] / r0[ 0 ]; m2 = r2[ 0 ] / r0[ 0 ]; m3 = r3[ 0 ] / r0[ 0 ];
		s = r0[ 1 ]; r1[ 1 ] -= m1 * s; r2[ 1 ] -= m2 * s; r3[ 1 ] -= m3 * s;
		s = r0[ 2 ]; r1[ 2 ] -= m1 * s; r2[ 2 ] -= m2 * s; r3[ 2 ] -= m3 * s;
		s = r0[ 3 ]; r1[ 3 ] -= m1 * s; r2[ 3 ] -= m2 * s; r3[ 3 ] -= m3 * s;
		s = r0[ 4 ];
		if( s != 0.0 ){ r1[ 4 ] -= m1 * s; r2[ 4 ] -= m2 * s; r3[ 4 ] -= m3 * s; }
		s = r0[ 5 ];
		if (s != 0.0 ){ r1[ 5 ] -= m1 * s; r2[ 5 ] -= m2 * s; r3[ 5 ] -= m3 * s; }
		s = r0[ 6 ];
		if (s != 0.0 ){ r1[ 6 ] -= m1 * s; r2[ 6 ] -= m2 * s; r3[ 6 ] -= m3 * s; }
		s = r0[ 7 ];
		if (s != 0.0 ){ r1[ 7 ] -= m1 * s; r2[ 7 ] -= m2 * s; r3[ 7 ] -= m3 * s; }

		// choose pivot - or die 
		if( fabs( r3[ 1 ] ) > fabs( r2[ 1 ] ) ){
			std::swap( r3, r2 );
		}
		if( fabs( r2[ 1 ] ) > fabs( r1[ 1 ] ) ){
			std::swap( r2, r1 );
		}
		if( r1[ 1 ] == 0.0 ){
			EMIT_WARNING( __FILE__, __LINE__, "matrix is singular" );
			return( Mat4::fromIdentity() );
		}

		// eliminate second variable 
		m2 = r2[ 1 ] / r1[ 1 ]; m3 = r3[ 1 ] / r1[ 1 ];
		r2[ 2 ] -= m2 * r1[ 2 ]; r3[ 2 ] -= m3 * r1[ 2 ];
		r2[ 3 ] -= m2 * r1[ 3 ]; r3[ 3 ] -= m3 * r1[ 3 ];
		s = r1[ 4 ]; if( 0.0 != s ){ r2[ 4 ] -= m2 * s; r3[ 4 ] -= m3 * s; }
		s = r1[ 5 ]; if( 0.0 != s ){ r2[ 5 ] -= m2 * s; r3[ 5 ] -= m3 * s; }
		s = r1[ 6 ]; if( 0.0 != s ){ r2[ 6 ] -= m2 * s; r3[ 6 ] -= m3 * s; }
		s = r1[ 7 ]; if( 0.0 != s ){ r2[ 7 ] -= m2 * s; r3[ 7 ] -= m3 * s; }

		// choose pivot - or die 
		if( fabs( r3[ 2 ] ) > fabs( r2[ 2 ] ) ){
			std::swap( r3, r2 );
		}
		if( r2[ 2 ] == 0.0 ){
			EMIT_WARNING( __FILE__, __LINE__, "matrix is singular" );
			return( Mat4::fromIdentity() );
		}

		// eliminate third variable 
		m3 = r3[ 2 ] / r2[ 2 ];
		r3[ 3 ] -= m3 * r2[ 3 ], r3[ 4 ] -= m3 * r2[ 4 ],
		r3[ 5 ] -= m3 * r2[ 5 ], r3[ 6 ] -= m3 * r2[ 6 ],
		r3[ 7 ] -= m3 * r2[ 7 ];

		// last check 
		if( r3[ 3 ] == 0.0 ){
			EMIT_WARNING( __FILE__, __LINE__, "matrix is singular" );
			return( Mat4::fromIdentity() );
		}

		s = 1.0 / r3[ 3 ]; // now back substitute row 3 
		r3[ 4 ] *= s; r3[ 5 ] *= s; r3[ 6 ] *= s; r3[ 7 ] *= s;

		m2 = r2[ 3 ]; // now back substitute row 2
		s  = 1.0 / r2[ 2 ];
		r2[ 4 ] = s * ( r2[ 4 ] - r3[ 4 ] * m2 ), r2[ 5 ] = s * ( r2[ 5 ] - r3[ 5 ] * m2 ),
		r2[ 6 ] = s * ( r2[ 6 ] - r3[ 6 ] * m2 ), r2[ 7 ] = s * ( r2[ 7 ] - r3[ 7 ] * m2 );
		m1 = r1[ 3 ];
		r1[ 4 ] -= r3[ 4 ] * m1, r1[ 5 ] -= r3[ 5 ] * m1,
		r1[ 6 ] -= r3[ 6 ] * m1, r1[ 7 ] -= r3[ 7 ] * m1;
		m0 = r0[ 3 ];
		r0[ 4 ] -= r3[ 4 ] * m0, r0[ 5 ] -= r3[ 5 ] * m0,
		r0[ 6 ] -= r3[ 6 ] * m0, r0[ 7 ] -= r3[ 7 ] * m0;

		m1 = r1[ 2 ]; // now back substitute row 1 
		s  = 1.0 / r1[ 1 ];
		r1[ 4 ] = s * ( r1[ 4 ] - r2[ 4 ] * m1 ), r1[ 5 ] = s * ( r1[ 5 ] - r2[ 5 ] * m1 ),
		r1[ 6 ] = s * ( r1[ 6 ] - r2[ 6 ] * m1 ), r1[ 7 ] = s * ( r1[ 7 ] - r2[ 7 ] * m1 );
		m0 = r0[ 2 ];
		r0[ 4 ] -= r2[ 4 ] * m0, r0[ 5 ] -= r2[ 5 ] * m0,
		r0[ 6 ] -= r2[ 6 ] * m0, r0[ 7 ] -= r2[ 7 ] * m0;

		m0 = r0[ 1 ]; // now back substitute row 0 
		s  = 1.0 / r0[ 0 ];
		r0[ 4 ] = s * ( r0[ 4 ] - r1[ 4 ] * m0 ), r0[ 5 ] = s * ( r0[ 5 ] - r1[ 5 ] * m0 ),
		r0[ 6 ] = s * ( r0[ 6 ] - r1[ 6 ] * m0 ), r0[ 7 ] = s * ( r0[ 7 ] - r1[ 7 ] * m0 );

		a[ 0 ] = r0[ 4 ]; 
		a[ 1 ] = r1[ 4 ]; 
		a[ 2 ] = r2[ 4 ]; 
		a[ 3 ] = r3[ 4 ]; 

		a[ 4 ] = r0[ 5 ],
		a[ 5 ] = r1[ 5 ],
		a[ 6 ] = r2[ 5 ],
		a[ 7 ] = r3[ 5 ],

		a[ 8 ] = r0[ 6 ]; 
		a[ 9 ] = r1[ 6 ]; 
		a[ 10 ] = r2[ 6 ]; 
		a[ 11 ] = r3[ 6 ]; 

		a[ 12 ] = r0[ 7 ],
		a[ 13 ] = r1[ 7 ],
		a[ 14 ] = r2[ 7 ],
		a[ 15 ] = r3[ 7 ];

		return( a );
	}

	void Mat4::setIdentity( void ){
		m_v[ 0 ] = 1.0;
		m_v[ 1 ] = 0.0;
		m_v[ 2 ] = 0.0;
		m_v[ 3 ] = 0.0;
		m_v[ 4 ] = 0.0;
		m_v[ 5 ] = 1.0;
		m_v[ 6 ] = 0.0;
		m_v[ 7 ] = 0.0;
		m_v[ 8 ] = 0.0;
		m_v[ 9 ] = 0.0;
		m_v[ 10 ] = 1.0;
		m_v[ 11 ] = 0.0;
		m_v[ 12 ] = 0.0;
		m_v[ 13 ] = 0.0;
		m_v[ 14 ] = 0.0;
		m_v[ 15 ] = 1.0;
	}

	Quat Mat4::toQuat( void ){
		Quat q;
		if ( m_v[ 0 * 4 + 0 ] + m_v[ 1 * 4 + 1 ] + m_v[ 2 * 4 + 2 ] > 0.0 ) {
			double t = + m_v[ 0 * 4 + 0 ] + m_v[ 1 * 4 + 1 ] + m_v[ 2 * 4 + 2 ] + 1.0;
			double s = ( 1.0 / sqrt( t ) ) * 0.5f;
			q[ 3 ] = s * t;
			q[ 2 ] = ( m_v[ 0 * 4 + 1 ] - m_v[ 1 * 4 + 0 ] ) * s;
			q[ 1 ] = ( m_v[ 2 * 4 + 0 ] - m_v[ 0 * 4 + 2 ] ) * s;
			q[ 0 ] = ( m_v[ 1 * 4 + 2 ] - m_v[ 2 * 4 + 1 ] ) * s;
		} 
		else if ( m_v[ 0 * 4 + 0 ] > m_v[ 1 * 4 + 1 ] && m_v[ 0 * 4 + 0 ] > m_v[ 2 * 4 + 2 ] ) {
			double t = + m_v[ 0 * 4 + 0 ] - m_v[ 1 * 4 + 1 ] - m_v[ 2 * 4 + 2 ] + 1.0;
			double s = ( 1.0 / sqrt( t ) ) * 0.5f;
			q[ 0 ] = s * t;
			q[ 1 ] = ( m_v[ 0 * 4 + 1 ] + m_v[ 1 * 4 + 0 ] ) * s; 
			q[ 2 ] = ( m_v[ 2 * 4 + 0 ] + m_v[ 0 * 4 + 2 ] ) * s;
			q[ 3 ] = ( m_v[ 1 * 4 + 2 ] - m_v[ 2 * 4 + 1 ] ) * s;
		} 
		else if ( m_v[ 1 * 4 + 1 ] > m_v[ 2 * 4 + 2 ] ) {
			double t = - m_v[ 0 * 4 + 0 ] + m_v[ 1 * 4 + 1 ] - m_v[ 2 * 4 + 2 ] + 1.0;
			double s = ( 1.0 / sqrt( t ) ) * 0.5f;
			q[ 1 ] = s * t;
			q[ 0 ] = ( m_v[ 0 * 4 + 1 ] + m_v[ 1 * 4 + 0 ] ) * s;
			q[ 3 ] = ( m_v[ 2 * 4 + 0 ] - m_v[ 0 * 4 + 2 ] ) * s;
			q[ 2 ] = ( m_v[ 1 * 4 + 2 ] + m_v[ 2 * 4 + 1 ] ) * s;
		} 
		else {
			double t = - m_v[ 0 * 4 + 0 ] - m_v[ 1 * 4 + 1 ] + m_v[ 2 * 4 + 2 ] + 1.0;
			double s = ( 1.0 / sqrt( t ) ) * 0.5f;
			q[ 2 ] = s * t;
			q[ 3 ] = ( m_v[ 0 * 4 + 1 ] - m_v[ 1 * 4 + 0 ] ) * s;
			q[ 0 ] = ( m_v[ 2 * 4 + 0 ] + m_v[ 0 * 4 + 2 ] ) * s;
			q[ 1 ] = ( m_v[ 1 * 4 + 2 ] + m_v[ 2 * 4 + 1 ] ) * s;
		}
		q[ 4 ] = m_v[ 0 * 4 + 3 ];
		q[ 5 ] = m_v[ 1 * 4 + 3 ];
		q[ 6 ] = m_v[ 2 * 4 + 3 ];
		q[ 7 ] = 0.0;
		return( q );
	} 

	Mat4 Mat4::fromTransformation( const Vec3 & position, const Vec3 & YawPitchRollInDegrees, const Vec3 & scaling ){
		return( Mat4::fromTransformation( position, Mat3::fromYawPitchRollInDegrees( YawPitchRollInDegrees ), scaling ) ); 
	}

	Mat4 Mat4::fromTransformation(  const Vec3 & translation,  const Mat3 & rotation, const Vec3 & scaling ){
		Mat4 r;
		r.m_v[ 0 ] = rotation[ 0 ] * scaling[ 0 ];
		r.m_v[ 1 ] = rotation[ 1 ] * scaling[ 0 ];
		r.m_v[ 2 ] = rotation[ 2 ] * scaling[ 0 ];
		r.m_v[ 3 ] = 0.0;
		r.m_v[ 4 ] = rotation[ 3 ] * scaling[ 1 ];
		r.m_v[ 5 ] = rotation[ 4 ] * scaling[ 1 ];
		r.m_v[ 6 ] = rotation[ 5 ] * scaling[ 1 ];
		r.m_v[ 7 ] = 0.0;
		r.m_v[ 8 ] = rotation[ 6 ] * scaling[ 2 ];
		r.m_v[ 9 ] = rotation[ 7 ] * scaling[ 2 ];
		r.m_v[ 10 ] = rotation[ 8 ] * scaling[ 2 ];
		r.m_v[ 11 ] = 0.0;
		r.m_v[ 12 ] = translation[ 0 ];
		r.m_v[ 13 ] = translation[ 1 ];
		r.m_v[ 14 ] = translation[ 2 ];
		r.m_v[ 15 ] = 1.0;
		return( r );
	}

	Mat4 Mat4::fromTranslation( const Vec3 & translation ){
		Mat4 m;
		m.setTranslation( translation );
		return( m );
	}

	Mat4 Mat4::fromRotation( double degrees, const Vec3 & axis ){
		Mat4 m;
		m.rotate( degrees, axis );
		return( m );
	}

	Mat4 Mat4::fromScaling( const Vec3 & scaling ){
		Mat4 m;
		m.setScaling( scaling );
		return( m );
	}

	Vec4 Mat4::toPolar( void ) const { 
		Vec2 px = getCol( 0 ).xyz().toPolar();
		Vec2 py = getCol( 1 ).xyz().toPolar();
		return( Vec4( px[ 0 ], px[ 1 ], py[ 0 ], py[ 1 ] ) );
	}

	Vec3 Mat4::toYawPitchRollInDegrees( void ) const { 
		return( toMat3().toYawPitchRollInDegrees() );
	}

	Mat3 Mat4::toMat3( void ) const { 
		Mat3 m;

		m[ 0 ] = m_v[ 0 ];
		m[ 1 ] = m_v[ 1 ];
		m[ 2 ] = m_v[ 2 ];

		m[ 3 ] = m_v[ 4 ];
		m[ 4 ] = m_v[ 5 ];
		m[ 5 ] = m_v[ 6 ];

		m[ 6 ] = m_v[ 8 ];
		m[ 7 ] = m_v[ 9 ];
		m[ 8 ] = m_v[ 10 ];

		return( m );
	}

	Mat4 Mat4::fromPolar( const Vec4 & polar ){
		Mat4 m;
		m.setCol( 0, Vec4( Vec3( polar.xy() ), 0.0 ) );
		m.setCol( 1, Vec4( Vec3( polar.zw() ), 0.0 ) );
		m.setCol( 2, Vec4( cross( m.getCol(0).xyz(), m.getCol(1).xyz() ), 0.0 ) );
		m.setCol( 3, Vec4( 0, 0, 0, 1 ) );
		return( m );
	}

	Mat4 Mat4::fromPlaneEquation( const Vec4 & equation ){
		Mat4 mat;
		Vec3 normal = normalize( Vec3( equation[ 0 ], equation[ 1 ], equation[ 2 ] ) );
		Mat4 dirMat = fromDirectionalAxis( normal, 'z' );
		mat.setCol( 0, dirMat.getCol(0) );
		mat.setCol( 1, dirMat.getCol(1) );
		mat.setCol( 2, dirMat.getCol(2) );
		mat.setCol( 3, Vec4( normal * equation[ 3 ], 1.0 ) );
		return( mat );
	}


	Mat4 Mat4::fromDirectionalAxis( const Vec3 & axis, char principalAxis ){
		Mat4 mat;
		if( length( axis ) < MU_EPSILON ){
			// the matrix is degenerate
			mat.setIdentity();
			return( mat );
		}
		// the axis is valid, so we use it as principal x-axis
		Vec3 x = normalize( axis );
		// take the (right-handed) perpendicular
		Vec3 y( -x[ 1 ], x[ 0 ], 0.0 );
		// and create the z-axis from that
		Vec3 z = cross( x, y );
		// test if it's degenerate 
		if( length( z ) < MU_EPSILON ){
			// x happens to be the z-axis, so we set y to
			y = Vec3( 0.0, 1.0, 0.0 );
			// and create the z-axis from that
			z = cross( x, y );
		}

		// now re-order according to what is to be the principal axis
		switch( principalAxis ){
			case 'x':
				// nothing needs to be done
				mat.setCol( 0, Vec4( normalize( x ), 0.0 ) );
				mat.setCol( 1, Vec4( normalize( y ), 0.0 ) );
				mat.setCol( 2, Vec4( normalize( z ), 0.0 ) );
				break;
			case 'y':
				// cw rotation around z
				mat.setCol( 0, Vec4( -normalize( y ), 0.0 ) );
				mat.setCol( 1, Vec4( normalize( x ), 0.0 ) );
				mat.setCol( 2, Vec4( normalize( z ), 0.0 ) );
				break;
			case 'z':
				// ccw around y
				mat.setCol( 0, Vec4( -normalize( z ), 0.0 ) );
				mat.setCol( 1, Vec4( normalize( y ), 0.0 ) );
				mat.setCol( 2, Vec4( normalize( x ), 0.0 ) );
				break;
		}
		return( mat );
	}

	Mat4 Mat4::fromDirectionalAxis( const Vec3 & axis, const Vec3 & reference, char principalAxis ){
		Mat4 mat;
		if( length( axis ) < MU_EPSILON ){
			// the matrix is degenerate
			mat.setIdentity();
			return( mat );
		}
		// the axis is valid, so we use it as principal x-axis
		Vec3 x = normalize( axis );
		// take the reference for the y
		Vec3 y = reference;
		// and create the z-axis from that
		Vec3 z = cross( x, y );
		// now re-order according to what is to be the principal axis
		switch( principalAxis ){
			case 'x':
				// nothing needs to be done
				mat.setCol( 0, Vec4( normalize( x ), 0.0 ) );
				mat.setCol( 1, Vec4( normalize( y ), 0.0 ) );
				mat.setCol( 2, Vec4( normalize( z ), 0.0 ) );
				break;
			case 'y':
				// cw rotation around z
				mat.setCol( 0, Vec4( -normalize( y ), 0.0 ) );
				mat.setCol( 1, Vec4( normalize( x ), 0.0 ) );
				mat.setCol( 2, Vec4( normalize( z ), 0.0 ) );
				break;
			case 'z':
				// ccw around y
				mat.setCol( 0, Vec4( -normalize( z ), 0.0 ) );
				mat.setCol( 1, Vec4( normalize( y ), 0.0 ) );
				mat.setCol( 2, Vec4( normalize( x ), 0.0 ) );
				break;
		}
		return( mat );
	}

	Mat4 Mat4::fromOrthogonalAxes( const Vec3 & x, const Vec3 & y, const Vec3 & z ){
		return( Mat4( x[ 0 ], x[ 1 ], x[ 2 ], 0.0, y[ 0 ], y[ 1 ], y[ 2 ], 0.0, z[ 0 ], z[ 1 ], z[ 2 ], 0.0, 0.0, 0.0, 0.0, 1.0 ) ); 
	}

	Mat4 Mat4::fromIdentity( void ){
		Mat4 m;
		m.setIdentity();
		return( m );
	}

	Mat4 Mat4::fromOrtho( double left, double right, double bottom, double top, double zNear, double zFar ){
		Mat4 m;
		m.ortho( left, right, bottom, top, zNear, zFar );
		return( m );
	}

	Mat4 Mat4::fromFrustum( double left, double right, double bottom, double top, double zNear, double zFar ){
		Mat4 m;
		m.frustum( left, right, bottom, top, zNear, zFar );
		return( m );
	}

	Mat4 Mat4::fromPerspective( double fovy, double aspect, double zNear, double zFar ){
		Mat4 m;
		m.perspective( fovy, aspect, zNear, zFar );
		return( m );
	}

	Mat4 Mat4::fromLookAt( const Vec3 & eye, const Vec3 & center, const Vec3 & up ){
		Mat4 m;
		m.lookAt( eye, center, up );
		return( m );
	}

	Mat4 Mat4::fromAxisAngle( double degrees, const Vec3 & axis ){
		Mat4 m;
		m.setAxisAngle( degrees, axis );
		return( m );
	}

	Mat4 Mat4::fromYawPitchRollInDegrees( const Vec3 & YawPitchRollInDegrees ){
		Mat4 m;
		m.setYawPitchRollInDegrees( YawPitchRollInDegrees );
		return( m );
	}

	void Mat4::setAxisAngle( double degrees, const Vec3 & axis ){
		double xx, yy, zz, xy, yz, zx, xs, ys, zs, s, c, c1, radians;
		
		radians = degrees * ( M_PI / 180.0 );
		
		s = sinf( radians );
		c = cosf( radians );
		c1 = 1.0 - c;

		Vec3 nor = axis.normalized();

		xx = nor[ 0 ] * nor[ 0 ];
		yy = nor[ 1 ] * nor[ 1 ];
		zz = nor[ 2 ] * nor[ 2 ];
		
		xy = nor[ 0 ] * nor[ 1 ];
		yz = nor[ 1 ] * nor[ 2 ];
		zx = nor[ 2 ] * nor[ 0 ];
		
		xs = nor[ 0 ] * s;
		ys = nor[ 1 ] * s;
		zs = nor[ 2 ] * s;
				
		m_v[ 0 ] = ( c1 * xx ) + c;
		m_v[ 1 ] = ( c1 * xy ) + zs;
		m_v[ 2 ] = ( c1 * zx ) - ys;
		
		m_v[ 4 ] = ( c1 * xy ) - zs;
		m_v[ 5 ] = ( c1 * yy ) + c;
		m_v[ 6 ] = ( c1 * yz ) + xs;
		
		m_v[ 8 ] = ( c1 * zx ) + ys;
		m_v[ 9 ] = ( c1 * yz ) - xs;
		m_v[ 10 ] = ( c1 * zz ) + c;

		//! don't change the translation column
	}

	void Mat4::setPosition( const Vec3 & pos ){
		m_v[ 12 ] = pos[ 0 ];
		m_v[ 13 ] = pos[ 1 ];
		m_v[ 14 ] = pos[ 2 ];
	}

	void Mat4::setPosition( const Vec4 & pos ){
		m_v[ 12 ] = pos[ 0 ];
		m_v[ 13 ] = pos[ 1 ];
		m_v[ 14 ] = pos[ 2 ];
		m_v[ 15 ] = pos[ 3 ];
	}

	void Mat4::setRotation( const Vec3 & YawPitchRollInDegrees ){
		setRotation( Mat3::fromYawPitchRollInDegrees( YawPitchRollInDegrees ) );
	}

	void Mat4::setRotationX( const double angle_deg ){
		// Fast, dedicated, x-axis rotation...
		double angle_rad = toRadians(angle_deg);
		double c = cos(angle_rad);
		double s = sin(angle_rad);

		m_v[ 0 ] = 1.0;
		m_v[ 1 ] = 0.0;
		m_v[ 2 ] = 0.0;
		m_v[ 3 ] = 0.0;

		m_v[ 4 ] = 0.0;
		m_v[ 5 ] = c;
		m_v[ 6 ] = s;
		m_v[ 7 ] = 0.0;

		m_v[ 8 ] = 0.0;
		m_v[ 9 ] = -s;
		m_v[ 10 ] = c;
		m_v[ 11 ] = 0.0;

		m_v[ 12 ] = 0.0;
		m_v[ 13 ] = 0.0;
		m_v[ 14 ] = 0.0;
		m_v[ 15 ] = 1.0;
	}

	void Mat4::setRotationY( const double angle_deg ){
		// Fast, dedicated, y-axis rotation...
		double angle_rad = toRadians(angle_deg);
		double c = cos(angle_rad);
		double s = sin(angle_rad);

		m_v[ 0 ] = c;
		m_v[ 1 ] = 0.0;
		m_v[ 2 ] = -s;
		m_v[ 3 ] = 0.0;

		m_v[ 4 ] = 0.0;
		m_v[ 5 ] = 1.0;
		m_v[ 6 ] = 0.0;
		m_v[ 7 ] = 0.0;

		m_v[ 8 ] = s;
		m_v[ 9 ] = 0.0;
		m_v[ 10 ] = c;
		m_v[ 11 ] = 0.0;

		m_v[ 12 ] = 0.0;
		m_v[ 13 ] = 0.0;
		m_v[ 14 ] = 0.0;
		m_v[ 15 ] = 1.0;
	}

	void Mat4::setRotationZ( const double angle_deg ){
		// Fast, dedicated, z-axis rotation...
		double angle_rad = toRadians(angle_deg);
		double c = cos(angle_rad);
		double s = sin(angle_rad);

		m_v[ 0 ] = c;
		m_v[ 1 ] = s;
		m_v[ 2 ] = 0.0;
		m_v[ 3 ] = 0.0;

		m_v[ 4 ] = -s;
		m_v[ 5 ] = c;
		m_v[ 6 ] = 0.0;
		m_v[ 7 ] = 0.0;

		m_v[ 8 ] = 0.0;
		m_v[ 9 ] = 0.0;
		m_v[ 10 ] = 1.0;
		m_v[ 11 ] = 0.0;

		m_v[ 12 ] = 0.0;
		m_v[ 13 ] = 0.0;
		m_v[ 14 ] = 0.0;
		m_v[ 15 ] = 1.0;
	}

	void Mat4::setRotation( const Mat3 & rot ){
		m_v[ 0 ] = rot[ 0 ];
		m_v[ 1 ] = rot[ 1 ];
		m_v[ 2 ] = rot[ 2 ];

		m_v[ 4 ] = rot[ 3 ];
		m_v[ 5 ] = rot[ 4 ];
		m_v[ 6 ] = rot[ 5 ];

		m_v[ 8 ] = rot[ 6 ];
		m_v[ 9 ] = rot[ 7 ];
		m_v[ 10 ] = rot[ 8 ];
	}

	void Mat4::setYawPitchRollInDegrees( const Vec3 & YawPitchRollInDegrees ){
		setRotation( Mat3::fromYawPitchRollInDegrees( YawPitchRollInDegrees ) );
	}

	void Mat4::ortho( double left, double right, double bottom, double top, double zNear, double zFar ){
		m_v[ 0 ] = 2.0 / ( right - left );
		m_v[ 1 ] = 0.0;
		m_v[ 2 ] = 0.0;
		m_v[ 3 ] = 0.0;
		m_v[ 4 ] = 0.0;
		m_v[ 5 ] = 2.0 / ( top - bottom );
		m_v[ 6 ] = 0.0;
		m_v[ 7 ] = 0.0;
		m_v[ 8 ] = 0.0;
		m_v[ 9 ] = 0.0;
		m_v[ 10 ] = -2.0 / ( zFar - zNear );
		m_v[ 11 ] = 0.0;
		m_v[ 12 ] = -( right + left ) / ( right - left );
		m_v[ 13 ] = -( top + bottom ) / ( top - bottom );
		m_v[ 14 ] = -( zFar + zNear ) / ( zFar - zNear );
		m_v[ 15 ] = 1.0;
	}

	void Mat4::frustum( double left, double right, double bottom, double top, double zNear, double zFar ){
		m_v[ 0 ] = ( 2.0 * zNear ) / ( right - left );
		m_v[ 1 ] = 0.0;
		m_v[ 2 ] = 0.0;
		m_v[ 3 ] = 0.0;
		m_v[ 4 ] = 0.0;
		m_v[ 5 ] = ( 2.0 * zNear ) / ( top - bottom );
		m_v[ 6 ] = 0.0;
		m_v[ 7 ] = 0.0;
		m_v[ 8 ] = ( right + left) / ( right - left );
		m_v[ 9 ] = ( top + bottom) / ( top - bottom );
		m_v[ 10 ] = ( -zFar - zNear ) / ( zFar  - zNear );
		m_v[ 11 ] = -1.0;
		m_v[ 12 ] = 0.0;
		m_v[ 13 ] = 0.0;
		m_v[ 14 ] = ( -2.0 * zFar * zNear ) / ( zFar - zNear );
		m_v[ 15 ] = 0.0;
	}

	void Mat4::perspective( double fovy, double aspect, double zNear, double zFar ){
		double range = tan( toRadians( fovy / 2.0 ) ) * zNear;
		double left = -range * aspect;
		double right = range * aspect;
		double bottom = -range;
		double top = range;

		frustum( left, right, bottom, top, zNear, zFar );
	}

	void Mat4::lookAt( const Vec3 & eye, const Vec3 & center, const Vec3 & up ){
		Mat4 m;
		Vec3 forward, side;

		forward = center - eye;
		forward.normalize();

		side = cross( forward, up );
		side.normalize();

		m[ 0 ] = side[ 0 ];
		m[ 4 ] = side[ 1 ];
		m[ 8 ] = side[ 2 ];

		m[ 1 ] = up[ 0 ];
		m[ 5 ] = up[ 1 ];
		m[ 9 ] = up[ 2 ];

		m[ 2 ] = -forward[ 0 ];
		m[ 6 ] = -forward[ 1 ];
		m[ 10 ] = -forward[ 2 ];

		( * this ) *= m;

		translate( -eye );
	}

} // namespace mu

#undef EMIT_WARNING

