Pod::Spec.new do |s|
  s.name         = 'MNCLogging'
  s.version      = '1.0.0'
  s.summary      = 'Simple Objective-C logging'
  s.license      = { :type => 'MIT', :file => 'MIT-LICENSE.txt' }
  s.author = {
    'Matthias Tretter' => 'm.yellow@gmx.at'
  }
  s.source       = { :git => "https://github.com/myell0w/MNCLogging.git", :tag => "{s.version}" }
  s.source_files = '*.{h,m}'
  
  s.ios.deployment_target = '6.0'
  s.osx.deployment_target = '10.7'
  s.requires_arc = true
end