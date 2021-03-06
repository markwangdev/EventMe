// Generated by Apple Swift version 3.1 (swiftlang-802.0.53 clang-802.0.42)
#pragma clang diagnostic push

#if defined(__has_include) && __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <objc/NSObject.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if defined(__has_include) && __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus) || __cplusplus < 201103L
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
typedef unsigned int swift_uint2  __attribute__((__ext_vector_type__(2)));
typedef unsigned int swift_uint3  __attribute__((__ext_vector_type__(3)));
typedef unsigned int swift_uint4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif
#if !defined(SWIFT_CLASS_PROPERTY)
# if __has_feature(objc_class_property)
#  define SWIFT_CLASS_PROPERTY(...) __VA_ARGS__
# else
#  define SWIFT_CLASS_PROPERTY(...)
# endif
#endif

#if defined(__has_attribute) && __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if defined(__has_attribute) && __has_attribute(swift_name)
# define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
#else
# define SWIFT_COMPILE_NAME(X)
#endif
#if defined(__has_attribute) && __has_attribute(objc_method_family)
# define SWIFT_METHOD_FAMILY(X) __attribute__((objc_method_family(X)))
#else
# define SWIFT_METHOD_FAMILY(X)
#endif
#if defined(__has_attribute) && __has_attribute(noescape)
# define SWIFT_NOESCAPE __attribute__((noescape))
#else
# define SWIFT_NOESCAPE
#endif
#if defined(__has_attribute) && __has_attribute(warn_unused_result)
# define SWIFT_WARN_UNUSED_RESULT __attribute__((warn_unused_result))
#else
# define SWIFT_WARN_UNUSED_RESULT
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if defined(__has_attribute) && __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if defined(__has_attribute) && __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name) enum _name : _type _name; enum SWIFT_ENUM_EXTRA _name : _type
# if defined(__has_feature) && __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME) SWIFT_ENUM(_type, _name)
# endif
#endif
#if !defined(SWIFT_UNAVAILABLE)
# define SWIFT_UNAVAILABLE __attribute__((unavailable))
#endif
#if !defined(SWIFT_UNAVAILABLE_MSG)
# define SWIFT_UNAVAILABLE_MSG(msg) __attribute__((unavailable(msg)))
#endif
#if !defined(SWIFT_AVAILABILITY)
# define SWIFT_AVAILABILITY(plat, ...) __attribute__((availability(plat, __VA_ARGS__)))
#endif
#if !defined(SWIFT_DEPRECATED)
# define SWIFT_DEPRECATED __attribute__((deprecated))
#endif
#if !defined(SWIFT_DEPRECATED_MSG)
# define SWIFT_DEPRECATED_MSG(...) __attribute__((deprecated(__VA_ARGS__)))
#endif
#if defined(__has_feature) && __has_feature(modules)
@import ObjectiveC;
@import MapKit;
@import CoreLocation;
@import UIKit;
@import Foundation;
#endif

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
@class CLLocation;
@class CLPlacemark;

SWIFT_CLASS("_TtC14LocationPicker8Location")
@interface Location : NSObject
@property (nonatomic, readonly, copy) NSString * _Nullable name;
@property (nonatomic, readonly, strong) CLLocation * _Nonnull location;
@property (nonatomic, readonly, strong) CLPlacemark * _Nonnull placemark;
@property (nonatomic, readonly, copy) NSString * _Nonnull address;
- (nonnull instancetype)initWithName:(NSString * _Nullable)name location:(CLLocation * _Nullable)location placemark:(CLPlacemark * _Nonnull)placemark OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
@end

@class NSDictionary;

@interface Location (SWIFT_EXTENSION(LocationPicker))
- (NSDictionary * _Nullable)toDefaultsDic SWIFT_WARN_UNUSED_RESULT;
+ (Location * _Nullable)fromDefaultsDic:(NSDictionary * _Nonnull)dic SWIFT_WARN_UNUSED_RESULT;
@end


@interface Location (SWIFT_EXTENSION(LocationPicker)) <MKAnnotation>
@property (nonatomic, readonly) CLLocationCoordinate2D coordinate;
@property (nonatomic, readonly, copy) NSString * _Nullable title;
@end

@class UIColor;
@class CLLocationManager;
@class CLGeocoder;
@class MKLocalSearch;
@class NSTimer;
@class MKMapView;
@class UIButton;
@class LocationSearchResultsViewController;
@class UISearchController;
@class UISearchBar;
@class NSBundle;
@class NSCoder;

SWIFT_CLASS("_TtC14LocationPicker28LocationPickerViewController")
@interface LocationPickerViewController : UIViewController
@property (nonatomic, copy) void (^ _Nullable completion)(Location * _Nullable);
@property (nonatomic) CLLocationDistance resultRegionDistance;
/// default: true
@property (nonatomic) BOOL showCurrentLocationButton;
/// default: true
@property (nonatomic) BOOL showCurrentLocationInitially;
/// see <code>region</code> property of <code>MKLocalSearchRequest</code>
/// default: false
@property (nonatomic) BOOL useCurrentLocationAsHint;
/// default: “Search or enter an address”
@property (nonatomic, copy) NSString * _Nonnull searchBarPlaceholder;
/// default: “Search History”
@property (nonatomic, copy) NSString * _Nonnull searchHistoryLabel;
/// default: “Select”
@property (nonatomic, copy) NSString * _Nonnull selectButtonTitle;
@property (nonatomic, strong) UIColor * _Nonnull currentLocationButtonBackground;
/// default: .Minimal
@property (nonatomic) UISearchBarStyle searchBarStyle;
/// default: .Default
@property (nonatomic) UIStatusBarStyle statusBarStyle;
@property (nonatomic) MKMapType mapType;
@property (nonatomic, strong) Location * _Nullable location;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull SearchTermKey;)
+ (NSString * _Nonnull)SearchTermKey SWIFT_WARN_UNUSED_RESULT;
@property (nonatomic, readonly, strong) CLLocationManager * _Nonnull locationManager;
@property (nonatomic, readonly, strong) CLGeocoder * _Nonnull geocoder;
@property (nonatomic, strong) MKLocalSearch * _Nullable localSearch;
@property (nonatomic, strong) NSTimer * _Nullable searchTimer;
@property (nonatomic, strong) MKMapView * _Null_unspecified mapView;
@property (nonatomic, strong) UIButton * _Nullable locationButton;
@property (nonatomic, strong) LocationSearchResultsViewController * _Nonnull results;
@property (nonatomic, strong) UISearchController * _Nonnull searchController;
@property (nonatomic, strong) UISearchBar * _Nonnull searchBar;
- (void)loadView;
- (void)viewDidLoad;
@property (nonatomic, readonly) UIStatusBarStyle preferredStatusBarStyle;
@property (nonatomic) BOOL presentedInitialLocation;
- (void)viewDidLayoutSubviews;
- (void)setInitialLocation;
- (void)getCurrentLocation;
- (void)currentLocationPressed;
- (void)showCurrentLocation:(BOOL)animated;
- (void)updateAnnotation;
- (void)showCoordinates:(CLLocationCoordinate2D)coordinate animated:(BOOL)animated;
- (nonnull instancetype)initWithNibName:(NSString * _Nullable)nibNameOrNil bundle:(NSBundle * _Nullable)nibBundleOrNil OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end

@class UIGestureRecognizer;

@interface LocationPickerViewController (SWIFT_EXTENSION(LocationPicker))
- (void)addLocation:(UIGestureRecognizer * _Nonnull)gestureRecognizer;
@end


@interface LocationPickerViewController (SWIFT_EXTENSION(LocationPicker)) <CLLocationManagerDelegate>
- (void)locationManager:(CLLocationManager * _Nonnull)manager didUpdateLocations:(NSArray<CLLocation *> * _Nonnull)locations;
@end


@interface LocationPickerViewController (SWIFT_EXTENSION(LocationPicker)) <UIGestureRecognizerDelegate>
- (BOOL)gestureRecognizer:(UIGestureRecognizer * _Nonnull)gestureRecognizer shouldRecognizeSimultaneouslyWithGestureRecognizer:(UIGestureRecognizer * _Nonnull)otherGestureRecognizer SWIFT_WARN_UNUSED_RESULT;
@end


@interface LocationPickerViewController (SWIFT_EXTENSION(LocationPicker)) <UISearchBarDelegate, UIBarPositioningDelegate>
- (void)searchBarTextDidBeginEditing:(UISearchBar * _Nonnull)searchBar;
- (void)searchBar:(UISearchBar * _Nonnull)searchBar textDidChange:(NSString * _Nonnull)searchText;
@end

@class MKAnnotationView;
@class UIControl;

@interface LocationPickerViewController (SWIFT_EXTENSION(LocationPicker)) <MKMapViewDelegate>
- (MKAnnotationView * _Nullable)mapView:(MKMapView * _Nonnull)mapView viewForAnnotation:(id <MKAnnotation> _Nonnull)annotation SWIFT_WARN_UNUSED_RESULT;
- (UIButton * _Nonnull)selectLocationButton SWIFT_WARN_UNUSED_RESULT;
- (void)mapView:(MKMapView * _Nonnull)mapView annotationView:(MKAnnotationView * _Nonnull)view calloutAccessoryControlTapped:(UIControl * _Nonnull)control;
- (void)mapView:(MKMapView * _Nonnull)mapView didAddAnnotationViews:(NSArray<MKAnnotationView *> * _Nonnull)views;
@end

@class MKLocalSearchResponse;

@interface LocationPickerViewController (SWIFT_EXTENSION(LocationPicker)) <UISearchResultsUpdating>
- (void)updateSearchResultsForSearchController:(UISearchController * _Nonnull)searchController;
- (void)searchFromTimer:(NSTimer * _Nonnull)timer;
- (void)showItemsForSearchResult:(MKLocalSearchResponse * _Nullable)searchResult;
- (void)selectedLocation:(Location * _Nonnull)location;
@end

@class UITableView;
@class UITableViewCell;

SWIFT_CLASS("_TtC14LocationPicker35LocationSearchResultsViewController")
@interface LocationSearchResultsViewController : UITableViewController
@property (nonatomic, copy) NSArray<Location *> * _Nonnull locations;
@property (nonatomic, copy) void (^ _Nullable onSelectLocation)(Location * _Nonnull);
@property (nonatomic) BOOL isShowingHistory;
@property (nonatomic, copy) NSString * _Nullable searchHistoryLabel;
- (void)viewDidLoad;
- (NSString * _Nullable)tableView:(UITableView * _Nonnull)tableView titleForHeaderInSection:(NSInteger)section SWIFT_WARN_UNUSED_RESULT;
- (NSInteger)tableView:(UITableView * _Nonnull)tableView numberOfRowsInSection:(NSInteger)section SWIFT_WARN_UNUSED_RESULT;
- (UITableViewCell * _Nonnull)tableView:(UITableView * _Nonnull)tableView cellForRowAtIndexPath:(NSIndexPath * _Nonnull)indexPath SWIFT_WARN_UNUSED_RESULT;
- (void)tableView:(UITableView * _Nonnull)tableView didSelectRowAtIndexPath:(NSIndexPath * _Nonnull)indexPath;
- (nonnull instancetype)initWithStyle:(UITableViewStyle)style OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initWithNibName:(NSString * _Nullable)nibNameOrNil bundle:(NSBundle * _Nullable)nibBundleOrNil OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end

#pragma clang diagnostic pop
