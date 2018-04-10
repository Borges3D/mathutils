#ifndef MATH_UTILS_H
#define MATH_UTILS_H

#include <vector>
#include <math.h>
#include <limits.h>
#include <iostream>

#ifndef M_PI
#   define M_PI       3.1415926535897932384626433832795
#endif

#define MU_EPSILON 1e-6

namespace mu {

    class Vec2;
    class Vec3;
    class Vec4;
    class Quat;
    class Mat2;
    class Mat3;
    class Mat4;

    double   largest( double, double );
    double   smallest( double, double );

    double   sgn( double );
    Vec2    sgn( const Vec2 & );
    Vec3    sgn( const Vec3 & );
    Vec4    sgn( const Vec4 & );
    bool    equals( double, double, double epsilon = MU_EPSILON );
    bool    equals( const Vec2 &, const Vec2 &, double epsilon = MU_EPSILON );
    bool    equals( const Vec3 &, const Vec3 &, double epsilon = MU_EPSILON );
    bool    equals( const Vec4 &, const Vec4 &, double epsilon = MU_EPSILON );
    double   clamp( double, double min, double max );
    double   clampMax( double, double max );
    double   clampMin( double, double min );
    Vec2    clamp( const Vec2 &, double min, double max );
    Vec2    clampMax( const Vec2 &, double max );
    Vec2    clampMin( const Vec2 &, double min );
    Vec3    clamp( const Vec3 &, double min, double max );
    Vec3    clampMax( const Vec3 &, double max );
    Vec3    clampMin( const Vec3 &, double min );
    Vec4    clamp( const Vec4 &, double min, double max );
    Vec4    clampMax( const Vec4 &, double max );
    Vec4    clampMin( const Vec4 &, double min );
    double   toRadians( double degrees );
    double   toDegrees( double radians );
    Vec2    toRadians( const Vec2 & );
    Vec2    toDegrees( const Vec2 & );
    Vec3    toRadians( const Vec3 & );
    Vec3    toDegrees( const Vec3 & );
    Vec4    toRadians( const Vec4 & );
    Vec4    toDegrees( const Vec4 & );
    double   distance( const Vec2 &, const Vec2 & );
    double   distance( const Vec3 &, const Vec3 & );
    double   distance( const Vec4 &, const Vec4 & );
    double   distance2( const Vec2 &, const Vec2 & );
    double   distance2( const Vec3 &, const Vec3 & );
    double   distance2( const Vec4 &, const Vec4 & );
    double   length( const Vec2 & );
    double   length( const Vec3 & );
    double   length( const Vec4 & );
    double   length2( const Vec2 & );
    double   length2( const Vec3 & );
    double   length2( const Vec4 & );
    double   dot( const Vec2 &, const Vec2 & v2 );
    double   dot( const Vec3 &, const Vec3 & v2 );
    double   dot( const Vec4 &, const Vec4 & v2 );
    Vec3    cross( const Vec3 &, const Vec3 & v2 );
    double   cross( const Vec2 &, const Vec2 & v2 );
    double   mix( double, double, double );
    Vec2    mix( const Vec2 &, const Vec2 &, double );
    Mat2    mix( const Mat2 &, const Mat2 &, double );
    Vec3    mix( const Vec3 &, const Vec3 &, double );
    Vec4    mix( const Vec4 &, const Vec4 &, double );
    Quat    mix( const Quat & v1, const Quat & v2, double f );
    Mat3    mix( const Mat3 &, const Mat3 &, double );
    Mat4    mix( const Mat4 &, const Mat4 &, double );

    Vec2    normalize( const Vec2 & );
    Vec3    normalize( const Vec3 & );
    Vec4    normalize( const Vec4 & );

    // allow for premultiplication of a vector by scalar
    Vec2    operator * ( double, const Vec2 & );
    Vec3    operator * ( double, const Vec3 & );
    Vec4    operator * ( double, const Vec4 & );

    /// extraction operators
    std::istream & operator >> ( std::istream & s, Vec2 & v );
    std::istream & operator >> ( std::istream & s, Vec3 & v );
    std::istream & operator >> ( std::istream & s, Vec4 & v );
    std::istream & operator >> ( std::istream & s, Quat & v );
    std::istream & operator >> ( std::istream & s, Mat2 & v );
    std::istream & operator >> ( std::istream & s, Mat3 & v );
    std::istream & operator >> ( std::istream & s, Mat4 & v );

    /// insertion operators
    std::ostream & operator << ( std::ostream & s, const Vec2 & v );
    std::ostream & operator << ( std::ostream & s, const Vec3 & v );
    std::ostream & operator << ( std::ostream & s, const Vec4 & v );
    std::ostream & operator << ( std::ostream & s, const Quat & v );
    std::ostream & operator << ( std::ostream & s, const Mat2 & v );
    std::ostream & operator << ( std::ostream & s, const Mat3 & v );
    std::ostream & operator << ( std::ostream & s, const Mat4 & v );

    class Vec2 {
        public:
                                Vec2( double xy = 0.0f );
                                Vec2( double x, double y );
                                Vec2( const double * );

            bool                operator < ( const double ) const;
            bool                operator < ( const Vec2 & ) const;
            bool                operator < ( const Vec3 & ) const;
            bool                operator < ( const Vec4 & ) const;
            Vec2                operator - ( void ) const;
            Vec2                operator + ( const Vec2 & ) const;
            Vec2                operator - ( const Vec2 & ) const;
            Vec2                operator * ( const Vec2 & ) const;
            Vec2                operator * ( double ) const;
            Vec2                operator / ( const Vec2 & ) const;
            Vec2                operator / ( double ) const;
            bool                operator == ( const Vec2 & ) const;
            bool                operator != ( const Vec2 & ) const;
            const double &       operator [] ( const int ) const;

            double &             operator [] ( int );
            Vec2 &              operator += ( const Vec2 & );
            Vec2 &              operator -= ( const Vec2 & );
            Vec2 &              operator *= ( double );
            Vec2 &              operator *= ( const Vec2 & );
            Vec2 &              operator /= ( double );
            Vec2 &              operator /= ( const Vec2 & );
        
            operator            const double * ( void ) const;
            operator            double * ( void );

            double &             x( void );
            const double &       x( void ) const;
            double &             y( void );
            const double &       y( void ) const;
            double               hyp( void ) const;
            double               len( void ) const;
            void                rotate( double radians );
            void                normalize( void );
            Vec2                normalized( void ) const;
            Vec2                abs( void ) const;
            Vec2                sgn( void ) const;
            Vec2                perp( void ) const;
            Vec2                clamp( double min = 0.0f, double max = 1.0f ) const;
            double               dot( const Vec2 & ) const;
            Vec2                cross( void ) const;
            double               cross( const Vec2 & ) const;
            bool                equals( const Vec2 &, double epsilon = MU_EPSILON ) const;
            bool                equals( const double *, double epsilon = MU_EPSILON ) const;
            double               toAngle() const;

            static  Vec2        fromAngle( double radians );

        private:
            double               m_v[2];
    };

    class Mat2 {
        public:
                                Mat2( double v00 = 1.0f, double v01 = 0.0f, double v10 = 0.0f, double v11 = 1.0f );
                                Mat2( const double * );

            Vec2                operator * ( const Vec2 & ) const;
            Mat2                operator * ( double ) const;
            Mat2                operator * ( const Mat2 & ) const;
            Mat2                operator / ( double ) const;
            const double &       operator [] ( const int ) const;
            bool                operator == ( const Mat2 & ) const;
            bool                operator != ( const Mat2 & ) const;

            double &             operator [] ( int );
            Mat2 &              operator *= ( const Mat2 & );
            Mat2 &              operator *= ( double );
            Mat2 &              operator /= ( double );

            operator            const double * ( void ) const;
            operator            double * ( void );
        
            Vec2                getRow( int ) const;
            Vec2                getCol( int ) const;
            const double &       getElement( int column, int row ) const;
            Mat2                transpose( void ) const;
            double               determinant( void ) const;
            Mat2                inverse( void ) const;
            bool                equals( const Mat2 &, double epsilon = MU_EPSILON ) const;
            bool                equals( const double *, double epsilon = MU_EPSILON ) const;
            void                setScaling( const Vec2 & b );
            void                scale( const Vec2 & b );
            Vec2                getScaling( void );
        
            double &             getElement( int column, int row );
            void                setRow( int index, const Vec2 & row );
            void                setCol( int index, const Vec2 & col );
            void                setElement( int col, int row, double );
            void                setIdentity( void );
            void                setRotation( double radians = 0.0f );

            static Mat2         fromIdentity( void );
            static Mat2         fromRowMajor( double r0c0, double r0c1, double r1c0, double r1c1 );
            static Mat2         fromRowMajor( const double * );

        private:
            double               m_v[4];
    };

    class Vec3 {
        public:
                                Vec3( double xyz = 0.0f );
                                Vec3( double x, double y, double z );
                                Vec3( const Vec2 & xy, double z = 0.0 );
                                Vec3( const double * v );
        
            bool                operator < ( const double ) const;
            bool                operator < ( const Vec2 & ) const;
            bool                operator < ( const Vec3 & ) const;
            bool                operator < ( const Vec4 & ) const;
            Vec3                operator - ( void ) const;
            Vec3                operator + ( const Vec3 & ) const;
            Vec3                operator - ( const Vec3 & ) const;
            Vec3                operator * ( const Vec3 & ) const;
            Vec3                operator * ( double ) const;
            Vec3                operator / ( double ) const;
            Vec3                operator / ( const Vec3 & ) const;
            const double &       operator [] ( const int ) const;
            bool                operator == ( const Vec3 & ) const;
            bool                operator != ( const Vec3 & ) const;

            double &             operator [] ( int );
            Vec3 &              operator += ( const Vec3 & );
            Vec3 &              operator -= ( const Vec3 & );
            Vec3 &              operator *= ( double );
            Vec3 &              operator *= ( const Vec3 & );
            Vec3 &              operator /= ( double );
            Vec3 &              operator /= ( const Vec3 & );

            operator            const double * ( void ) const;
            operator            double * ( void );
        
            double &             x( void );
            const double &       x( void ) const;
            double &             y( void );
            const double &       y( void ) const;
            double &             z( void );
            const double &       z( void ) const;
            Vec2                xy( void ) const;
            double               hyp( void ) const;
            double               len( void ) const;
            void                normalize( void );
            Vec3                normalized( void ) const;
            Vec3                abs( void ) const;
            Vec3                sgn( void ) const;
            Vec3                clamp( double min = 0.0f, double max = 1.0f ) const;
            double               dot( const Vec3 & ) const;
            Vec3                cross( const Vec3 & ) const;
            bool                equals( const Vec3 &, double epsilon = MU_EPSILON ) const;
            bool                equals( const double *, double epsilon = MU_EPSILON ) const;
            Vec2                toPolar( void ) const;
            double               getAngle( const Vec3 & xAxis = Vec3( 1,0,0 ), const Vec3 & yAxis = Vec3( 0,1,0 ) ) const;
            void                rotateX( double degrees );
            void                rotateY( double degrees );
            void                rotateZ( double degrees );

            static Vec3         fromPolar( const Vec2 & );

        private:
            double               m_v[3];
    };

    class Mat3 {
        public:
                                Mat3(   double v00 = 1.0f, double v01 = 0.0f, double v02 = 0.0f,
                                        double v10 = 0.0f, double v11 = 1.0f, double v12 = 0.0f,
                                        double v20 = 0.0f, double v21 = 0.0f, double v22 = 1.0f );
                                Mat3( const Vec3 & c0, const Vec3 & c1, const Vec3 & c2 );
                                Mat3( const double * );

            Vec3                operator * ( const Vec3 & ) const;
            Mat3                operator * ( double ) const;
            Mat3                operator * ( const Mat3 & ) const;
            Mat3                operator / ( double ) const;
            const double &       operator [] ( const int ) const;
            bool                operator == ( const Mat3 & )const;
            bool                operator != ( const Mat3 & )const;

            double &             operator [] ( int );
            Mat3 &              operator *= ( const Mat3 & );
            Mat3 &              operator *= ( double );
            Mat3 &              operator /= ( double );

            operator            const double * ( void ) const;
            operator            double * ( void );
        
            Vec3                getRow( int ) const;
            Vec3                getCol( int ) const;
            const double &       getElement( int column, int row ) const;
            Mat3                transpose( void ) const;
            Mat3                adjugate( void ) const;
            double               trace( void ) const;
            double               determinant( void ) const;
            Mat3                inverse( void ) const;
            void                scale( const Vec3 & b );
            void                setScaling( const Vec3 & b );
            Vec3                getScaling( void );
            bool                equals( const Mat3 &, double epsilon = MU_EPSILON ) const;
            bool                equals( const double *, double epsilon = MU_EPSILON ) const;
            Vec3                toYawPitchRollInDegrees( void ) const;
            Mat4                toMat4( void ) const;
            void                rotate( double degrees, const Vec3 & axis );
            void                setRotationX( const double angle_deg );
            void                setRotationY( const double angle_deg );
            void                setRotationZ( const double angle_deg );
            void                rotateX( const double angle_deg );
            void                rotateY( const double angle_deg );
            void                rotateZ( const double angle_deg );
            void                setAxisAngle( double degrees, const Vec3 & axis );

            double &             getElement( int column, int row );
            void                setRow( int index, const Vec3 & row );
            void                setCol( int index, const Vec3 & col );
            void                setElement( int col, int row, double );
            void                setIdentity( void );

            static Mat3         fromYawPitchRollInDegrees( const Vec3 & YawPitchRollInDegrees );
            static Mat3         fromIdentity();
            static Mat3         fromRowMajor( double r0c0, double r0c1, double r0c2, double r1c0, double r1c1, double r1c2, double r2c0, double r2c1, double r2c2 );
            static Mat3         fromRowMajor( const double * );

        private:
            double               m_v[9];
    };

    class Vec4 {
        public:
                                Vec4( double xyzw = 0.0f );
                                Vec4( double x, double y, double z, double w = 1.0f );
                                Vec4( const Vec2 & xy, double z, double w = 1.0f );
                                Vec4( const Vec3 & xyz, double w = 1.0f );
                                Vec4( const Vec2 & xy, const Vec2 & zw );
                                Vec4( double x, const Vec3 & yzw );
                                Vec4( double x, double y, const Vec2 & zw );
                                Vec4( const double * v );
        
            bool                operator < ( const double ) const;
            bool                operator < ( const Vec2 & ) const;
            bool                operator < ( const Vec3 & ) const;
            bool                operator < ( const Vec4 & ) const;
            Vec4                operator - () const;
            Vec4                operator + ( const Vec4 & b ) const;
            Vec4                operator - ( const Vec4 & b ) const;
            Vec4                operator * ( const Vec4 & b ) const;
            Vec4                operator * ( double b ) const;
            Vec4                operator / ( double b ) const;
            Vec4                operator / ( const Vec4 & b ) const;
            const double &       operator [] ( const int index ) const;
            bool                operator == ( const Vec4 & b ) const;
            bool                operator != ( const Vec4 & b ) const;

            double &             operator [] ( int index );
            Vec4 &              operator += ( const Vec4 & b );
            Vec4 &              operator -= ( const Vec4 & b );
            Vec4 &              operator *= ( double b );
            Vec4 &              operator *= ( const Vec4 & b );
            Vec4 &              operator /= ( double b );
            Vec4 &              operator /= ( const Vec4 & b );

            operator            const double * ( void ) const;
            operator            double * ( void );
        
            double &             x( void );
            const double &       x( void ) const;
            double &             y( void );
            const double &       y( void ) const;
            double &             z( void );
            const double &       z( void ) const;
            double &             w( void );
            const double &       w( void ) const;
            Vec2                xy() const;
            Vec2                zw() const;
            Vec3                xyz() const;
            double               hyp( void ) const;
            double               len( void ) const;
            void                normalize( void );
            Vec4                normalized( void ) const;
            Vec4                abs( void ) const;
            Vec4                sgn( void ) const;
            Vec4                clamp( double min = 0.0f, double max = 1.0f ) const;
            double               dot( const Vec4 & b ) const; 
            bool                equals( const Vec4 & compare, double epsilon = MU_EPSILON ) const;
            bool                equals( const double * compare, double epsilon = MU_EPSILON ) const;

            double &             getElement( int index );

        private:
            double               m_v[4];
    };

    class Quat {
        public:
                                Quat( double v0 = 0.0f, double v1 = 0.0f, double v2 = 0.0f, double v3 = 0.0f );
                                Quat( const Mat3 & mat );
                                Quat( const double * v );
                                Quat( const Vec3 & yawPitchRollInDegrees );
        
            bool                operator == ( const Quat & ) const;
            bool                operator != ( const Quat & ) const;
            Quat                operator + ( const Quat & ) const;
            Quat                operator - ( const Quat & ) const;
            Quat                operator * ( const Quat & ) const;
            Quat                operator * ( double s ) const;
            Quat                operator / ( double s ) const;
            Quat                operator - () const;
            const double &       operator [] ( const int ) const;

            double &             operator [] ( int index );
            Quat &              operator += ( const Quat & );
            Quat &              operator -= ( const Quat & );
            Quat &              operator *= ( double scalar );
            Quat &              operator /= ( double scalar );
        
            operator            const double * ( void ) const;
            operator            double * ( void );

            Vec2                xy( void ) const;
            Vec2                zw( void ) const;
            Vec3                xyz( void ) const;
            const double &       getElement( int index ) const;
            double &             getElement( int index );
            double               hyp( void ) const;
            double               len( void ) const;
            void                normalize( void );
            Quat                normalized( void ) const;
            double               dot( const Quat & ) const;
            Quat                inverse( void ) const;
            Quat                conjugate( void ) const;
            Quat                exp( void ) const;
            Quat                log( void ) const;
            Vec3                getYawPitchRollInDegrees( void ) const;
            void                setYawPitchRollInDegrees( double yaw, double pitch, double roll );
            bool                equals( const Quat & compare, double epsilon = MU_EPSILON ) const;
            bool                equals( const double * compare, double epsilon = MU_EPSILON ) const;
            Mat3                toMat3( void ) const;
            Mat4                toMat4( void ) const;
            void                toAxisAngle( Vec3 & axis, double & radians ) const;
            double               angle( const Quat & q ) const;
            double               getAngle( void ) const;

            static Quat         mix( const Quat & q1, const Quat & q2, double f );
            static Quat         fromMat3( const Mat3 & );
            static Quat         fromAxisAngle( const Vec3 & axis, double radians );
            static Quat         fromYawPitchRollInDegrees( const Vec3 & yawPitchRollInDegrees );

        private:
            double               m_v[4];
    };

    class Mat4 {
        public:
                                // indices are column-major, the first four values are the first column vector
                                Mat4(   double v00 = 1.0f, double v01 = 0.0f, double v02 = 0.0f, double v03 = 0.0f,
                                        double v10 = 0.0f, double v11 = 1.0f, double v12 = 0.0f, double v13 = 0.0f,
                                        double v20 = 0.0f, double v21 = 0.0f, double v22 = 1.0f, double v23 = 0.0f,
                                        double v30 = 0.0f, double v31 = 0.0f, double v32 = 0.0f, double v33 = 1.0f );
                                Mat4( const double * );
        
            Vec3                operator * ( const Vec3 & ) const;
            Vec4                operator * ( const Vec4 & ) const;
            Mat3                operator * ( const Mat3 & ) const;
            Mat4                operator * ( const Mat4 & ) const;
            Mat4                operator * ( double ) const;
            Mat4                operator + ( const Vec2 & ) const;
            Mat4                operator + ( const Vec3 & ) const;
            const double &       operator [] ( const int index ) const;
            bool                operator == ( const Mat4 & b ) const;
            bool                operator != ( const Mat4 & b ) const;
            
            double &             operator [] ( int );
            Mat4 &              operator *= ( const Mat4 & b );
            Mat4 &              operator *= ( const Mat3 & b );
            Mat4 &              operator = ( const Mat4 & b );
            Mat4 &              operator = ( const Mat3 & b );
            Mat4 &              operator = ( const Vec3 & b );
            Mat4 &              operator *= ( double );
            Mat4 &              operator *= ( const Vec3 & );
            Mat4 &              operator += ( const Vec2 & );
            Mat4 &              operator += ( const Vec3 & );

            operator            const double * ( void ) const;
            operator            double * ( void );
        
            Vec4                getRow( int ) const;
            Vec4                getCol( int ) const;
            const double &       getElement( int column, int row ) const;
            bool                equals( const Mat4 &, double epsilon = MU_EPSILON ) const;
            bool                equals( const double *, double epsilon = MU_EPSILON ) const;

            Vec3                translation( void ) const;
            Mat3                rotation( void ) const;
            Mat4                transpose( void ) const;
            Mat4                inverse( void ) const;
            Vec4                toPolar( void ) const;
            Mat3                toMat3( void ) const;
            Vec4                toPlaneEquation( void ) const;
            Vec3                toYawPitchRollInDegrees( void ) const;
            Quat                toQuat( void );

            double &             getElement( int column, int row );
            void                setElement( int col, int row, double v );
            void                setRow( int index, const Vec4 & row );
            void                setCol( int index, const Vec3 & col );
            void                setCol( int index, const Vec4 & col );
            void                setIdentity( void );
            void                ortho( double left, double right, double bottom, double top, double near, double far );
            void                frustum( double left, double right, double bottom, double top, double near, double far );
            void                perspective( double fovy, double aspect, double near, double far );
            void                lookAt( const Vec3 & eye, const Vec3 & center, const Vec3 & up = Vec3( 0.0f, 0.0f, 1.0f ) );
            void                translate( const Vec3 & b );
            void                setTranslation( const Vec3 & b );
            void                addTranslation( const Vec3 & b );
            void                scale( const Vec3 & b );
            void                setScaling( const Vec3 & b );
            Vec3                getScaling( void );
            Vec3                getRotation( void ) const;
            Vec3                getPosition( void ) const;
            void                rotate( double degrees, const Vec3 & axis );
            Vec3                transform( const Vec3 & ) const;
            void                setPosition( const Vec3 & );
            void                setPosition( const Vec4 & );
            void                setRotation( const Vec3 & YawPitchRollInDegrees );
            void                setRotationX( const double angle_deg );
            void                setRotationY( const double angle_deg );
            void                setRotationZ( const double angle_deg );
            void                setRotation( const Mat3 & );
            void                setAxisAngle( double degrees, const Vec3 & axis );
            void                setYawPitchRollInDegrees( const Vec3 & YawPitchRollInDegrees );

            static Mat4         fromPlaneEquation( const Vec4 & xyzd );
            static Mat4         fromDirectionalAxis( const Vec3 &, char principalAxis = 'x' );
            static Mat4         fromDirectionalAxis( const Vec3 &, const Vec3 & reference, char principalAxis = 'x' );
            static Mat4         fromOrthogonalAxes( const Vec3 & x, const Vec3 & y, const Vec3 & z );
            static Mat4         fromPolar( const Vec4 & xyVectors );
            static Mat4         fromTransformation( const Vec3 & position, const Mat3 & rotation, const Vec3 & scaling = Vec3( 1.0 ) );
            static Mat4         fromTransformation( const Vec3 & position, const Vec3 & YawPitchRollInDegrees, const Vec3 & scaling = Vec3( 1.0 ) );
            static Mat4         fromTranslation( const Vec3 & translation );
            static Mat4         fromRotation( double degrees, const Vec3 & axis );
            static Mat4         fromScaling( const Vec3 & scaling );
            static Mat4         fromIdentity( void );
            static Mat4         fromOrtho( double left, double right, double bottom, double top, double near, double far );
            static Mat4         fromFrustum( double left, double right, double bottom, double top, double near, double far );
            static Mat4         fromPerspective( double fovy, double aspect, double near, double far );
            static Mat4         fromLookAt( const Vec3 & eye, const Vec3 & center = Vec3(), const Vec3 & up = Vec3( 0.0f, 0.0f, 1.0f ) );
            static Mat4         fromAxisAngle( double degrees, const Vec3 & axis );
            static Mat4         fromYawPitchRollInDegrees( const Vec3 & YawPitchRollInDegrees );
            static Mat4         fromRowMajor( double r0c0, double r0c1, double r0c2, double r0c3, double r1c0, double r1c1, double r1c2, double r1c3, double r2c0, double r2c1, double r2c2, double r2c3, double r3c0, double r3c1, double r3c2, double r3c3 );
            static Mat4         fromRowMajor( const double * );

        private:
            double               m_v[16];
    };

}// mu

#endif //MATH_UTILS_H
